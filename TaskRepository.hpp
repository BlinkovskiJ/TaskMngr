#pragma once

#include "Task.hpp"
#include "Category.hpp"

using namespace System;
using namespace Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

ref class TaskRepository
{
private:
    String^ connectionString;

    int GenerateNewTaskId(SqlConnection^ conn);

public:
    TaskRepository(String^ connStr);
    void InsertTask(Task^ task, int categoryId);
    int InsertCategory(Category^ cat);
    List<Task^>^ GetAllTasks();
    List<Category^>^ getAllCats();
};

