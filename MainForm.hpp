#pragma once

#include "Task.hpp"
#include "Category.hpp"
#include "TaskRepository.hpp"
#include "TaskConf.hpp"
#include "DataManager.hpp"

namespace TaskMngr {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

		//DataManager^ getDataManager() { return dataManager;  }
		System::Void update();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::GroupBox^ taskBrowserGroup;
	private: System::Windows::Forms::TreeView^ taskBrowser;
	private: System::Windows::Forms::Label^ nameLabel;

	private: System::Windows::Forms::Panel^ taskPanel;

	private: System::Windows::Forms::Label^ infoBox_TaskDesc;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ infoBox_TaskStatus;
	private: System::Windows::Forms::Label^ infoBox_TaskName;
	private: System::Windows::Forms::DateTimePicker^ infoBox_TaskDeadLineCalendar;
	private: System::Windows::Forms::GroupBox^ emtybdDialog;
	private: System::Windows::Forms::Button^ NewTaskBtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ saveALL;
	private: System::Windows::Forms::TextBox^ serverAddress;

	private: System::Windows::Forms::Button^ connectToDB;





















	protected:

	protected:

	protected:

	protected:

	protected:





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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->taskBrowserGroup = (gcnew System::Windows::Forms::GroupBox());
			this->taskBrowser = (gcnew System::Windows::Forms::TreeView());
			this->emtybdDialog = (gcnew System::Windows::Forms::GroupBox());
			this->NewTaskBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->taskPanel = (gcnew System::Windows::Forms::Panel());
			this->saveALL = (gcnew System::Windows::Forms::Button());
			this->infoBox_TaskDeadLineCalendar = (gcnew System::Windows::Forms::DateTimePicker());
			this->infoBox_TaskDesc = (gcnew System::Windows::Forms::Label());
			this->infoBox_TaskName = (gcnew System::Windows::Forms::Label());
			this->infoBox_TaskStatus = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->serverAddress = (gcnew System::Windows::Forms::TextBox());
			this->connectToDB = (gcnew System::Windows::Forms::Button());
			this->taskBrowserGroup->SuspendLayout();
			this->emtybdDialog->SuspendLayout();
			this->taskPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(27, 24);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(46, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::showTaskConfDialog);
			this->button1->MouseHover += gcnew System::EventHandler(this, &MainForm::button1_MouseHover);
			// 
			// taskBrowserGroup
			// 
			this->taskBrowserGroup->Controls->Add(this->taskBrowser);
			this->taskBrowserGroup->Controls->Add(this->button1);
			this->taskBrowserGroup->Location = System::Drawing::Point(0, 0);
			this->taskBrowserGroup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskBrowserGroup->Name = L"taskBrowserGroup";
			this->taskBrowserGroup->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskBrowserGroup->Size = System::Drawing::Size(459, 1149);
			this->taskBrowserGroup->TabIndex = 4;
			this->taskBrowserGroup->TabStop = false;
			// 
			// taskBrowser
			// 
			this->taskBrowser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->taskBrowser->BackColor = System::Drawing::SystemColors::Info;
			this->taskBrowser->Location = System::Drawing::Point(27, 88);
			this->taskBrowser->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskBrowser->Name = L"taskBrowser";
			this->taskBrowser->Size = System::Drawing::Size(388, 1033);
			this->taskBrowser->TabIndex = 3;
			this->taskBrowser->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainForm::taskBrowser_AfterSelect);
			// 
			// emtybdDialog
			// 
			this->emtybdDialog->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(209)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->emtybdDialog->Controls->Add(this->NewTaskBtn);
			this->emtybdDialog->Controls->Add(this->label1);
			this->emtybdDialog->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->emtybdDialog->Location = System::Drawing::Point(178, 138);
			this->emtybdDialog->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->emtybdDialog->Name = L"emtybdDialog";
			this->emtybdDialog->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->emtybdDialog->Size = System::Drawing::Size(956, 781);
			this->emtybdDialog->TabIndex = 3;
			this->emtybdDialog->TabStop = false;
			// 
			// NewTaskBtn
			// 
			this->NewTaskBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->NewTaskBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->NewTaskBtn->Location = System::Drawing::Point(302, 370);
			this->NewTaskBtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->NewTaskBtn->Name = L"NewTaskBtn";
			this->NewTaskBtn->Size = System::Drawing::Size(361, 165);
			this->NewTaskBtn->TabIndex = 0;
			this->NewTaskBtn->Text = L"Новая задача";
			this->NewTaskBtn->UseVisualStyleBackColor = true;
			this->NewTaskBtn->Click += gcnew System::EventHandler(this, &MainForm::showTaskConfDialog);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(259, 268);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(446, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"У вас пока нет задач...";
			// 
			// nameLabel
			// 
			this->nameLabel->AutoSize = true;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameLabel->Location = System::Drawing::Point(92, 70);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(251, 32);
			this->nameLabel->TabIndex = 0;
			this->nameLabel->Text = L"Название задачи:";
			// 
			// taskPanel
			// 
			this->taskPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->taskPanel->Controls->Add(this->saveALL);
			this->taskPanel->Controls->Add(this->emtybdDialog);
			this->taskPanel->Controls->Add(this->infoBox_TaskDeadLineCalendar);
			this->taskPanel->Controls->Add(this->infoBox_TaskDesc);
			this->taskPanel->Controls->Add(this->infoBox_TaskName);
			this->taskPanel->Controls->Add(this->infoBox_TaskStatus);
			this->taskPanel->Controls->Add(this->label4);
			this->taskPanel->Controls->Add(this->label3);
			this->taskPanel->Controls->Add(this->label2);
			this->taskPanel->Controls->Add(this->nameLabel);
			this->taskPanel->Location = System::Drawing::Point(479, 88);
			this->taskPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->taskPanel->Name = L"taskPanel";
			this->taskPanel->Size = System::Drawing::Size(1346, 1032);
			this->taskPanel->TabIndex = 5;
			// 
			// saveALL
			// 
			this->saveALL->Location = System::Drawing::Point(834, 24);
			this->saveALL->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->saveALL->Name = L"saveALL";
			this->saveALL->Size = System::Drawing::Size(253, 88);
			this->saveALL->TabIndex = 4;
			this->saveALL->Text = L"Сохр.";
			this->saveALL->UseVisualStyleBackColor = true;
			this->saveALL->Click += gcnew System::EventHandler(this, &MainForm::saveALL_Click);
			// 
			// infoBox_TaskDeadLineCalendar
			// 
			this->infoBox_TaskDeadLineCalendar->Location = System::Drawing::Point(97, 548);
			this->infoBox_TaskDeadLineCalendar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->infoBox_TaskDeadLineCalendar->Name = L"infoBox_TaskDeadLineCalendar";
			this->infoBox_TaskDeadLineCalendar->Size = System::Drawing::Size(433, 26);
			this->infoBox_TaskDeadLineCalendar->TabIndex = 1;
			// 
			// infoBox_TaskDesc
			// 
			this->infoBox_TaskDesc->AutoSize = true;
			this->infoBox_TaskDesc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoBox_TaskDesc->Location = System::Drawing::Point(92, 214);
			this->infoBox_TaskDesc->Name = L"infoBox_TaskDesc";
			this->infoBox_TaskDesc->Size = System::Drawing::Size(38, 32);
			this->infoBox_TaskDesc->TabIndex = 0;
			this->infoBox_TaskDesc->Text = L"...";
			// 
			// infoBox_TaskName
			// 
			this->infoBox_TaskName->AutoSize = true;
			this->infoBox_TaskName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoBox_TaskName->Location = System::Drawing::Point(349, 70);
			this->infoBox_TaskName->Name = L"infoBox_TaskName";
			this->infoBox_TaskName->Size = System::Drawing::Size(143, 32);
			this->infoBox_TaskName->TabIndex = 0;
			this->infoBox_TaskName->Text = L"Название";
			// 
			// infoBox_TaskStatus
			// 
			this->infoBox_TaskStatus->AutoSize = true;
			this->infoBox_TaskStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->infoBox_TaskStatus->Location = System::Drawing::Point(349, 702);
			this->infoBox_TaskStatus->Name = L"infoBox_TaskStatus";
			this->infoBox_TaskStatus->Size = System::Drawing::Size(190, 32);
			this->infoBox_TaskStatus->TabIndex = 0;
			this->infoBox_TaskStatus->Text = L"Выполняется";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(92, 702);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(212, 32);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Статус задачи:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(92, 459);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(240, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Дедлайн задачи:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(92, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 32);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Описание задачи:";
			// 
			// serverAddress
			// 
			this->serverAddress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->serverAddress->Location = System::Drawing::Point(479, 21);
			this->serverAddress->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->serverAddress->Name = L"serverAddress";
			this->serverAddress->Size = System::Drawing::Size(258, 35);
			this->serverAddress->TabIndex = 6;
			this->serverAddress->Text = L"DESKTOP-HDMG0FD\\MSSQLSERVER01";
			// 
			// connectToDB
			// 
			this->connectToDB->Location = System::Drawing::Point(765, 18);
			this->connectToDB->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->connectToDB->Name = L"connectToDB";
			this->connectToDB->Size = System::Drawing::Size(130, 40);
			this->connectToDB->TabIndex = 7;
			this->connectToDB->Text = L"Подключить";
			this->connectToDB->UseVisualStyleBackColor = true;
			this->connectToDB->Click += gcnew System::EventHandler(this, &MainForm::connectToDB_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(209)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(207)));
			this->ClientSize = System::Drawing::Size(1881, 1055);
			this->Controls->Add(this->connectToDB);
			this->Controls->Add(this->serverAddress);
			this->Controls->Add(this->taskBrowserGroup);
			this->Controls->Add(this->taskPanel);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TaskMngr";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->taskBrowserGroup->ResumeLayout(false);
			this->emtybdDialog->ResumeLayout(false);
			this->emtybdDialog->PerformLayout();
			this->taskPanel->ResumeLayout(false);
			this->taskPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);*/
	private: 
		System::Void _connectToDB();
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void button1_MouseHover(System::Object^ sender, System::EventArgs^ e);
		System::Void showTaskConfDialog(System::Object^ sender, System::EventArgs^ e);
		System::Void displayTasks();
		static DataManager^ dataManager;
		static bool connected = false;
		System::Void taskBrowser_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
		/*System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);*/
		System::Void saveALL_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void connectToDB_Click(System::Object^ sender, System::EventArgs^ e);
};
}
