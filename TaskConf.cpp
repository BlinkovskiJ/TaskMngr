#include "TaskConf.hpp"

System::Void TaskMngr::TaskConf::taskConfOK_Click(System::Object^ sender, System::EventArgs^ e)
{
	tbIndicator(tbName);
	if (tbIndicator(tbName))
	{
		dataManager->addTask(gcnew Task(tbName->Text, tbDesc->Text,
			calculateDeadline(deadLine_format->SelectedIndex, Convert::ToInt32(deadLine_units->Value)), 
			static_cast<TaskStatus>(currentStatus->SelectedIndex), taskCat->SelectedIndex));

		for each (Task^ task in dataManager->getTasks())
		{
			Console::WriteLine("\nTask data: " + Convert::ToString(task->getName()) + " " + Convert::ToString(task->getCategoryID()));
		}

		parentForm->update();

		Close();
	}
	else
	{
		String^ msg = "Что-то пошло не так... Провьрье введённую информацию!";
		String^ caption = "Ошибка";
		MessageBoxButtons btn = MessageBoxButtons::OK;
		MessageBox::Show(msg, caption, btn, MessageBoxIcon::Warning);
	}
}

System::Void TaskMngr::TaskConf::TaskConf_Load(System::Object^ sender, System::EventArgs^ e)
{
	deadLine_format->SelectedIndex = 0;
	currentStatus->Text = Convert::ToString(currentStatus->Items[0]);

	update();
}

System::Void TaskMngr::TaskConf::updateUnit()
{
	array<int>^ ThresholdsUnits = { 60, 24, 7, 4 };

	if (deadLine_format->SelectedIndex < ThresholdsUnits->Length && deadLine_units->Value >= ThresholdsUnits[deadLine_format->SelectedIndex])
	{
		deadLine_units->Value = deadLine_units->Minimum;
		deadLine_format->SelectedIndex++;
		Console::WriteLine("Current index " + Convert::ToString(deadLine_format->SelectedIndex));
	}
}

System::Void TaskMngr::TaskConf::deadLine_units_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	updateUnit();
}

System::Void TaskMngr::TaskConf::tbName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	fixTextLen(50, tbName);
	tbIndicator(tbName);
}

System::Void TaskMngr::TaskConf::tbDesc_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	fixTextLen(250, tbDesc);
}

System::Void TaskMngr::TaskConf::fixTextLen(int maxLen, TextBox^ tb)
{
	if (tb->Text->Length > maxLen)
	{
		tb->Text = tb->Text->Substring(0, maxLen);
		tb->SelectionStart = tb->Text->Length;
	}
}

DateTime TaskMngr::TaskConf::calculateDeadline(int deadlineFormatIndex, int value)
{
	DateTime now = DateTime::Now;
	DateTime deadLineAt;
	switch (deadlineFormatIndex)
	{
	case 0: deadLineAt = now.AddMinutes(value); break;
	case 1: deadLineAt = now.AddHours(value); break;
	case 2: deadLineAt = now.AddDays(value); break;
	case 3: deadLineAt = now.AddDays(value * 7); break;
	case 4: deadLineAt = now.AddMonths(value); break;
	}

	Console::WriteLine("DeadlineFormatIndex: " + Convert::ToString(deadlineFormatIndex) + ", " + deadLineAt.ToString());

	return deadLineAt;
}

bool TaskMngr::TaskConf::tbIndicator(TextBox^ tb)
{
	if (tb->Text->Length == 0)
	{
		tb->BackColor = Color::FromArgb(237, 114, 114);
		return false;
	}
	else
	{
		tb->BackColor = Color::FromName("Window");
		return true;
	}
}

System::Void TaskMngr::TaskConf::addNewCatBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	CategoryConf^ catConf = gcnew CategoryConf(this, dataManager);
	catConf->Show();
}

System::Void TaskMngr::TaskConf::update()
{
	List<Category^>^ ExistingCats = dataManager->getCategories();

	taskCat->Items->Clear();

	for each (Category ^ cat in ExistingCats)
	{
		taskCat->Items->Add(cat->getName());
	}

	taskCat->SelectedIndex = ExistingCats->Count - 1;
}
