#include "MainForm.hpp"

using namespace System::Windows::Forms;
using namespace System;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew TaskMngr::MainForm());
}

System::Void TaskMngr::MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	/*taskPanel->Visible = false;*/
	_connectToDB();

	this->DoubleBuffered = true;
	this->SetStyle(ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint | ControlStyles::OptimizedDoubleBuffer, true);
	this->UpdateStyles();

	update();
}

System::Void TaskMngr::MainForm::button1_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	ToolTip^ toolTip = gcnew ToolTip();
	toolTip->IsBalloon = true;
	toolTip->AutoPopDelay = 5000;
	toolTip->InitialDelay = 250;
	toolTip->ReshowDelay = 500;
	toolTip->SetToolTip(button1, "Создать новую задачу");
}

System::Void TaskMngr::MainForm::showTaskConfDialog(System::Object^ sender, System::EventArgs^ e)
{
	TaskConf^ taskConf = gcnew TaskConf(this, dataManager);
	taskConf->Show();
}

System::Void TaskMngr::MainForm::displayTasks()
{
	taskBrowser->BeginUpdate();
	taskBrowser->Nodes->Clear();

	for each (Category ^ cat in dataManager->getCategories())
	{
		TreeNode^ catNode = gcnew TreeNode(cat->getName());
		catNode->Tag = cat;

		for each (Task ^ task in dataManager->getTasks())
		{
			Console::WriteLine("\nTask cat id: " + Convert::ToString(task->getCategoryID()) + " Category id: " + Convert::ToString(cat->getID()));
			if (task->getCategoryID() == cat->getID() && task->getState() != EntityState::Deleted)
			{
				Console::WriteLine("\nTask name: " + task->getName() + " Category name: " + cat->getName());
				TreeNode^ taskNode = gcnew TreeNode(task->getName());
				taskNode->Tag = task;
				catNode->Nodes->Add(taskNode);
			}
		}

		taskBrowser->Nodes->Add(catNode);
	}

	taskBrowser->EndUpdate();
}

System::Void TaskMngr::MainForm::update()
{
	displayTasks();

	// -- logging -- 
	for each (Task^ task in dataManager->getTasks())
	{
		Console::WriteLine("\nTask data:\n" + "Name: " + task->getName()
			+ ", " + "Category id: " + System::Convert::ToString(task->getCategoryID()));
	}

	Console::WriteLine("\nTasks count: " + Convert::ToString(dataManager->getTasks()->Count));
	String^ result = emtybdDialog->Visible ? "Yes" : "No";
	Console::WriteLine("\nIs dialog visible?: " + result);
	// -- logging -- 

	if (dataManager->getTasks()->Count)
	{
		emtybdDialog->Visible = false;
	}
	else
	{
		emtybdDialog->Visible = true;
	}
}

System::Void TaskMngr::MainForm::taskBrowser_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
	TreeNode^ selectedNode = e->Node;

	if (selectedNode == nullptr || selectedNode->Tag == nullptr)
	{
		return;
	}

	if (selectedNode->Tag->GetType() == Task::typeid)
	{
		taskPanel->Visible = true;

		Task^ selectedTask = static_cast<Task^>(selectedNode->Tag);

		infoBox_TaskName->Text = selectedTask->getName();
		infoBox_TaskDesc->Text = selectedTask->getDesc();
		infoBox_TaskDeadLineCalendar->Value = selectedTask->getDeadLine();

		infoBox_TaskDeadLineCalendar->Invalidate();
		infoBox_TaskDeadLineCalendar->Update();
		taskPanel->Invalidate();
		taskPanel->Update();

		switch (selectedTask->getStatus())
		{
		case TaskStatus::Process:  infoBox_TaskStatus->Text = "Выполняется..."; break;
		case TaskStatus::Finished: infoBox_TaskStatus->Text = "Завершена!"; break;
		case TaskStatus::Delayed:  infoBox_TaskStatus->Text = "Отложена..."; break;
		}
	}

	/*else if (selectedNode->Tag->GetType() == Category::typeid)
	{
		Category^ category = static_cast<Category^>(selectedNode->Tag);
	}*/
}

//System::Void TaskMngr::MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
//{
//
//}

System::Void TaskMngr::MainForm::saveALL_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ connStr = "Data Source=" + serverAddress->Text + ";Initial Catalog=Tasks;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
	TaskRepository^ repo = gcnew TaskRepository(connStr);

	dataManager->saveChanges(repo);
	String^ msg = "Все данные были сохранены!";
	String^ caption = "Сохранение";
	MessageBoxButtons btn = MessageBoxButtons::OK;
	MessageBox::Show(msg, caption, btn);
}

System::Void TaskMngr::MainForm::connectToDB_Click(System::Object^ sender, System::EventArgs^ e)
{
	_connectToDB();
}

void TaskMngr::MainForm::_connectToDB()
{
	String^ connStr = "Data Source=" + serverAddress->Text + ";Initial Catalog=Tasks;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
	TaskRepository^ repo = gcnew TaskRepository(connStr);
	List<Task^>^ taskList = repo->GetAllTasks();

	repo = gcnew TaskRepository(connStr);
	List<Category^>^ categoryList = repo->getAllCats();

	if (dataManager)
	{
		System::Console::WriteLine("\n1");
		taskList->AddRange(dataManager->getTasks());
		categoryList->AddRange(dataManager->getCategories());
	}

	dataManager = gcnew DataManager(taskList, categoryList);

	update();
}