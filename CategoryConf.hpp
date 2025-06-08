#pragma once

#include "DataManager.hpp"
#include "Category.hpp"
#include "TaskConf.hpp"

namespace TaskMngr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CategoryConf
	/// </summary>
	public ref class CategoryConf : public System::Windows::Forms::Form
	{
	public:
		CategoryConf(ref class TaskConf^ parent, DataManager^ manager)
		{
			this->parentForm = parent;
			this->dataManager = manager;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CategoryConf()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ catNametb;
	private: System::Windows::Forms::Button^ catConfOkBtn;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->catNametb = (gcnew System::Windows::Forms::TextBox());
			this->catConfOkBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(48, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(258, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название категории:";
			// 
			// catNametb
			// 
			this->catNametb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->catNametb->Location = System::Drawing::Point(321, 84);
			this->catNametb->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->catNametb->Name = L"catNametb";
			this->catNametb->Size = System::Drawing::Size(262, 30);
			this->catNametb->TabIndex = 1;
			this->catNametb->TextChanged += gcnew System::EventHandler(this, &CategoryConf::catNametb_TextChanged);
			// 
			// catConfOkBtn
			// 
			this->catConfOkBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->catConfOkBtn->Location = System::Drawing::Point(230, 162);
			this->catConfOkBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->catConfOkBtn->Name = L"catConfOkBtn";
			this->catConfOkBtn->Size = System::Drawing::Size(180, 46);
			this->catConfOkBtn->TabIndex = 2;
			this->catConfOkBtn->Text = L"Ok";
			this->catConfOkBtn->UseVisualStyleBackColor = true;
			this->catConfOkBtn->Click += gcnew System::EventHandler(this, &CategoryConf::catConfOkBtn_Click);
			// 
			// CategoryConf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 254);
			this->Controls->Add(this->catConfOkBtn);
			this->Controls->Add(this->catNametb);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"CategoryConf";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CategoryConf";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		TaskConf^ parentForm;
		Category^ currentCat;
		bool catExist = false;
		DataManager^ dataManager;
		System::Void catConfOkBtn_Click(System::Object^ sender, System::EventArgs^ e);
		bool tbIndicator(TextBox^ tb);
		System::Void catNametb_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void fixTextLen(int maxLen, TextBox^ tb);
	};
}
