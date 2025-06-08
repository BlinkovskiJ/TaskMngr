#pragma once

#include "Task.hpp"
#include "Category.hpp"
#include "TaskRepository.hpp"

using namespace System;
using namespace System::Collections::Generic;

ref class DataManager
{

private:
	List<Task^>^ taskList;
	List<Category^>^ categoryList;

public:
	DataManager(List<Task^>^ taskList, List<Category^>^ categoryList);
	DataManager(); // working with chache

	List<Task^>^ getTasks();
	List<Category^>^ getCategories();

	void addTask(Task^ task);
	void addCategory(Category^ category);

	void deleteTask(Task^ task);
	void deleteCategory(Category^ category);

	Task^ findTaskByName(String^ name);
	Category^ findCategoryByName(String^ name);

	void saveChanges(TaskRepository^ repo);
};

