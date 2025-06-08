#include "CategoryConf.hpp"

System::Void TaskMngr::CategoryConf::catConfOkBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tbIndicator(catNametb))
	{
		dataManager->addCategory(currentCat);
		parentForm->update();
		Close();
	}
	else
	{
		String^ msg;
		String^ caption = "Ошибка";
		MessageBoxButtons btn = MessageBoxButtons::OK;

		if (catExist)
		{
			msg = "Такая категория уже есть, попробуйте ввести другое название категории!";
		}
		else
		{
			msg = "Что-то пошло не так... Проверьте введённую информацию!";
		}

		MessageBox::Show(msg, caption, btn, MessageBoxIcon::Warning);
	}
}

bool TaskMngr::CategoryConf::tbIndicator(TextBox^ tb)
{
	String^ nameToCheck = tb->Text->Trim();
	List<Category^>^ cats = dataManager->getCategories();

	catExist = false;
	for each (Category ^ cat in cats)
	{
		if (cat->getName()->Equals(nameToCheck, StringComparison::OrdinalIgnoreCase))
		{
			catExist = true;
			break;
		}
	}

	if (tb->Text->Length == 0 || catExist)
	{
		tb->BackColor = Color::FromArgb(237, 114, 114);
		return false;
	}
	else
	{
		tb->BackColor = SystemColors::Window;
		return true;
	}
}

System::Void TaskMngr::CategoryConf::catNametb_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	currentCat = gcnew Category(catNametb->Text->Trim(), dataManager->getCategories()->Count);
	fixTextLen(50, catNametb);
	tbIndicator(catNametb);
}

System::Void TaskMngr::CategoryConf::fixTextLen(int maxLen, TextBox^ tb)
{
	if (tb->Text->Length > maxLen)
	{
		tb->Text = tb->Text->Substring(0, maxLen);
		tb->SelectionStart = tb->Text->Length;
	}
}
