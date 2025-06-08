#pragma once

#include "Task.hpp"
#include "Category.hpp"
#include "DataManager.hpp"
#include "MainForm.hpp"
#include "CategoryConf.hpp"

namespace TaskMngr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TaskConf
	/// </summary>
	public ref class TaskConf : public System::Windows::Forms::Form
	{
	public:
		//TaskConf(void)
		//{
		//	InitializeComponent();
		//	//
		//	//TODO: добавьте код конструктора
		//	//
		//}

		TaskConf(ref class MainForm^ parent, DataManager^ manager)
		{
			this->parentForm = parent;
			this->dataManager = manager;
			InitializeComponent();
		}

		System::Void update();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TaskConf()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ deadLine_units;




	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbDesc;

	private: System::Windows::Forms::Button^ taskConfOK;
	private: System::Windows::Forms::ComboBox^ deadLine_format;
	private: System::Windows::Forms::ComboBox^ currentStatus;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ taskCat;
	private: System::Windows::Forms::Button^ addNewCatBtn;










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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->deadLine_units = (gcnew System::Windows::Forms::NumericUpDown());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbDesc = (gcnew System::Windows::Forms::TextBox());
			this->taskConfOK = (gcnew System::Windows::Forms::Button());
			this->deadLine_format = (gcnew System::Windows::Forms::ComboBox());
			this->currentStatus = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->taskCat = (gcnew System::Windows::Forms::ComboBox());
			this->addNewCatBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deadLine_units))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(173, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(173, 225);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Описание:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(173, 428);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 29);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Срок выполнения:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label4->Location = System::Drawing::Point(173, 502);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 29);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Статус:";
			// 
			// deadLine_units
			// 
			this->deadLine_units->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->deadLine_units->Location = System::Drawing::Point(420, 426);
			this->deadLine_units->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->deadLine_units->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->deadLine_units->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->deadLine_units->Name = L"deadLine_units";
			this->deadLine_units->Size = System::Drawing::Size(79, 34);
			this->deadLine_units->TabIndex = 2;
			this->deadLine_units->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->deadLine_units->ValueChanged += gcnew System::EventHandler(this, &TaskConf::deadLine_units_ValueChanged);
			// 
			// tbName
			// 
			this->tbName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->tbName->Location = System::Drawing::Point(329, 132);
			this->tbName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(264, 34);
			this->tbName->TabIndex = 1;
			this->tbName->TextChanged += gcnew System::EventHandler(this, &TaskConf::tbName_TextChanged);
			// 
			// tbDesc
			// 
			this->tbDesc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tbDesc->Location = System::Drawing::Point(329, 222);
			this->tbDesc->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tbDesc->Multiline = true;
			this->tbDesc->Name = L"tbDesc";
			this->tbDesc->Size = System::Drawing::Size(389, 145);
			this->tbDesc->TabIndex = 1;
			this->tbDesc->TextChanged += gcnew System::EventHandler(this, &TaskConf::tbDesc_TextChanged);
			// 
			// taskConfOK
			// 
			this->taskConfOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->taskConfOK->Location = System::Drawing::Point(271, 739);
			this->taskConfOK->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskConfOK->Name = L"taskConfOK";
			this->taskConfOK->Size = System::Drawing::Size(208, 72);
			this->taskConfOK->TabIndex = 3;
			this->taskConfOK->Text = L"OK";
			this->taskConfOK->UseVisualStyleBackColor = true;
			this->taskConfOK->Click += gcnew System::EventHandler(this, &TaskConf::taskConfOK_Click);
			// 
			// deadLine_format
			// 
			this->deadLine_format->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->deadLine_format->FormattingEnabled = true;
			this->deadLine_format->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Минут", L"Часов", L"Дней", L"Недель", L"Месяцев" });
			this->deadLine_format->Location = System::Drawing::Point(519, 426);
			this->deadLine_format->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->deadLine_format->Name = L"deadLine_format";
			this->deadLine_format->Size = System::Drawing::Size(154, 37);
			this->deadLine_format->TabIndex = 4;
			// 
			// currentStatus
			// 
			this->currentStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->currentStatus->FormattingEnabled = true;
			this->currentStatus->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Отложено", L"В процессе", L"Завершено" });
			this->currentStatus->Location = System::Drawing::Point(380, 500);
			this->currentStatus->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->currentStatus->Name = L"currentStatus";
			this->currentStatus->Size = System::Drawing::Size(213, 37);
			this->currentStatus->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label5->Location = System::Drawing::Point(173, 588);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 29);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Категория:";
			// 
			// taskCat
			// 
			this->taskCat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->taskCat->FormattingEnabled = true;
			this->taskCat->Location = System::Drawing::Point(380, 586);
			this->taskCat->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskCat->Name = L"taskCat";
			this->taskCat->Size = System::Drawing::Size(213, 37);
			this->taskCat->TabIndex = 5;
			// 
			// addNewCatBtn
			// 
			this->addNewCatBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->addNewCatBtn->Location = System::Drawing::Point(136, 588);
			this->addNewCatBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addNewCatBtn->Name = L"addNewCatBtn";
			this->addNewCatBtn->Size = System::Drawing::Size(32, 30);
			this->addNewCatBtn->TabIndex = 6;
			this->addNewCatBtn->Text = L"+";
			this->addNewCatBtn->UseVisualStyleBackColor = true;
			this->addNewCatBtn->Click += gcnew System::EventHandler(this, &TaskConf::addNewCatBtn_Click);
			// 
			// TaskConf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(805, 844);
			this->Controls->Add(this->addNewCatBtn);
			this->Controls->Add(this->taskCat);
			this->Controls->Add(this->currentStatus);
			this->Controls->Add(this->deadLine_format);
			this->Controls->Add(this->taskConfOK);
			this->Controls->Add(this->deadLine_units);
			this->Controls->Add(this->tbDesc);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"TaskConf";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TaskConf";
			this->Load += gcnew System::EventHandler(this, &TaskConf::TaskConf_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->deadLine_units))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		MainForm^ parentForm;
		DataManager^ dataManager;
		System::Void taskConfOK_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void TaskConf_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void updateUnit();
		System::Void deadLine_units_ValueChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void tbName_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void tbDesc_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void fixTextLen(int maxLen, TextBox^ tb);
		DateTime calculateDeadline(int deadlineFormatIndex, int value);
		bool tbIndicator(TextBox^ tb);
		System::Void addNewCatBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
