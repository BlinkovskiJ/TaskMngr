#include "TaskRepository.hpp"

TaskRepository::TaskRepository(String^ connStr)
{
    connectionString = connStr;
}

int TaskRepository::GenerateNewTaskId(SqlConnection^ conn)
{
    SqlCommand^ cmd = gcnew SqlCommand("SELECT ISNULL(MAX(Id), 0) + 1 FROM Tasks", conn);
    if (conn->State != ConnectionState::Open)
        conn->Open();
    int id = Convert::ToInt32(cmd->ExecuteScalar());
    conn->Close();
    return id;
}

void TaskRepository::InsertTask(Task^ task, int categoryId)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlCommand^ cmd = gcnew SqlCommand();
    cmd->Connection = conn;
    cmd->CommandText = "INSERT INTO Tasks (Id, Title, [Desc], DeadLine, Status, CategoryID) " +
        "VALUES (@Id, @Title, @Desc, @DeadLine, @Status, @CategoryID)";

    int newId = GenerateNewTaskId(conn);

    cmd->Parameters->AddWithValue("@Id", newId);
    cmd->Parameters->AddWithValue("@Title", task->getName());
    cmd->Parameters->AddWithValue("@Desc", task->getDesc());
    cmd->Parameters->AddWithValue("@DeadLine", task->getDeadLine());
    cmd->Parameters->AddWithValue("@Status", static_cast<int>(task->getStatus()));
    cmd->Parameters->AddWithValue("@CategoryID", categoryId);

    try
    {
        conn->Open();
        cmd->ExecuteNonQuery();
    }
    catch (SqlException^ ex)
    {
        Console::WriteLine("Ошибка при вставке задачи: " + ex->Message, "Ошибка БД");
    }
    finally
    {
        conn->Close();
    }
}

int TaskRepository::InsertCategory(Category^ cat)
{
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlCommand^ cmd = gcnew SqlCommand("INSERT INTO Cats (CatName) OUTPUT INSERTED.CatID VALUES (@Name)", conn);
    cmd->Parameters->AddWithValue("@Name", cat->getName());

    try
    {
        conn->Open();
        int id = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();
        return id;
    }
    catch (SqlException^ ex)
    {
        Console::WriteLine("Ошибка при вставке категории: " + ex->Message);
        return -1;
    }
}

List<Task^>^ TaskRepository::GetAllTasks()
{
    List<Task^>^ tasks = gcnew List<Task^>();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlCommand^ cmd = gcnew SqlCommand("SELECT Title, [Desc], DeadLine, Status, CategoryID FROM Tasks", conn);

    try
    {
        conn->Open();
        SqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read())
        {
            String^ title = reader->GetString(0);
            String^ desc = reader->IsDBNull(1) ? "" : reader->GetString(1);
            DateTime deadline = reader->GetDateTime(2);
            TaskStatus status = static_cast<TaskStatus>(reader->GetInt32(3));
            int catID = reader->GetInt32(4);

            Task^ t = gcnew Task(title, desc, deadline, status, catID);
            tasks->Add(t);
        }

        reader->Close();
    }
    catch (SqlException^ ex)
    {
        Console::WriteLine("Ошибка при вставке задачи: " + ex->Message, "Ошибка БД");
    }
    finally
    {
        conn->Close();
    }

    return tasks;
}

List<Category^>^ TaskRepository::getAllCats()
{
    List<Category^>^ cats = gcnew List<Category^>();
    SqlConnection^ conn = gcnew SqlConnection(connectionString);
    SqlCommand^ cmd = gcnew SqlCommand("SELECT CatID, CatName FROM Cats", conn);

    try
    {
        conn->Open();
        SqlDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read())
        {
            int catId = reader->GetInt32(0);
            String^ catName = reader->GetString(1);
            cats->Add(gcnew Category(catName, catId));
            //cats->Add(gcnew Category(catName));
        }

        reader->Close();
    }
    catch (SqlException^ ex)
    {
        Console::WriteLine("Ошибка при вставке задачи: " + ex->Message, "Ошибка БД");
    }
    finally
    {
        conn->Close();
    }

    return cats;
}

