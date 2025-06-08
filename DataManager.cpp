#include "DataManager.hpp"

DataManager::DataManager(List<Task^>^ taskList, List<Category^>^ categoryList)
{
    this->taskList = taskList;
    this->categoryList = categoryList;
    if (!categoryList->Count)
    {
        Category^ uncategorized = gcnew Category("Нет категории", 0);
        uncategorized->MarkNew();
        this->categoryList->Add(uncategorized);
        Console::WriteLine("\nCatList size: " + System::Convert::ToString(categoryList->Count));
    }
}

DataManager::DataManager()
{
    this->taskList = gcnew List<Task^>();
    this->categoryList = gcnew List<Category^>();
    this->categoryList->Add(gcnew Category("Нет категории", 0));
    Console::WriteLine("\nCatList size: " + System::Convert::ToString(categoryList->Count));
    Console::WriteLine("\nChache is ready to work!");
}

List<Task^>^ DataManager::getTasks()
{
    List<Task^>^ result = gcnew List<Task^>();
    for each (Task^ task in taskList)
    {
        result->Add(task);
    }
    return result;
}

List<Category^>^ DataManager::getCategories()
{
    List<Category^>^ result = gcnew List<Category^>();

    for each (Category^ category in categoryList)
    {
        result->Add(category);
    }

    return result;
}

void DataManager::addTask(Task^ task)
{
    task->MarkNew();
    taskList->Add(task);
}

void DataManager::addCategory(Category^ category)
{
    category->MarkNew();
    categoryList->Add(category);
}

void DataManager::deleteTask(Task^ task)
{
    task->MarkDeleted();
}

void DataManager::deleteCategory(Category^ category)
{
    category->MarkDeleted();
}

Task^ DataManager::findTaskByName(String^ name)
{
    for each (Task^ task in taskList)
    {
        if (task->getName() == name && task->getState() != EntityState::Deleted)
        {
            return task;
        }
        return nullptr;
    }
}

Category^ DataManager::findCategoryByName(String^ name)
{
    for each (Category^ cat in categoryList)
    {
        if (cat->getName() == name && cat->getState() != EntityState::Deleted)
        {
            return cat;
        }
        return nullptr;
    }
}

void DataManager::saveChanges(TaskRepository^ repo)
{
    Dictionary<int, int>^ catIndexToDbId = gcnew Dictionary<int, int>();

    // === Сначала сохраняем категории ===
    for (int i = 0; i < categoryList->Count; i++)
    {
        Category^ cat = categoryList[i];
        EntityState state = cat->getState();

        if (state == EntityState::New)
        {
            int dbId = repo->InsertCategory(cat);
            cat->setID(dbId);
            cat->MarkUnchanged();
        }

        if (cat->getState() != EntityState::Deleted)
        {
            catIndexToDbId[i] = cat->getID();
        }
    }

    // === Затем задачи ===
    for each (Task ^ task in taskList)
    {
        switch (task->getState())
        {
        case EntityState::New:
        {
            int categoryIndex = task->getCategoryID();
            if (!catIndexToDbId->ContainsKey(categoryIndex)) continue;

            int actualCatId = catIndexToDbId[categoryIndex];
            repo->InsertTask(task, actualCatId);
            task->MarkUnchanged();
            break;
        }

        //case EntityState::Deleted:
        //    repo->DeleteTask(task);
        //    break;

        //case EntityState::Modified:
        //    repo->UpdateTask(task);
        //    task->MarkUnchanged();
        //    break;

        default:
            break;
        }
    }
}


