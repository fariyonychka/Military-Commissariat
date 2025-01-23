#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "DataEntryForm.h"
#include "MilitaryCommissariat.h"
#include <string>
#include <clocale> 
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <msclr/marshal.h>
#include "AverageCost.h"
#include "LessAssign.h"
#include "MoreCost.h"
#include <cstring>
#include <algorithm> 
#include <vector>  
using namespace std;

//���������� �������� ����, � ����� ����������� ��� ��� ������� � ��'����
namespace InfoAllCommissariat {
	int AmountAllCommissariat = 0;
	vector<CMillitaryCommissariat> arrayCommissariat;  
}

namespace MilitaryCommissariat {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::Form_Closing);

			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	public:
	bool isFileSaved = false;  // ���� ��� ��������, �� ��� ���� ����������

	 double AvarageCost = 0;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MilitaryName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ costPer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AmountEmpl;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ AmountAssig;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ addCommissariat;
	private: System::Windows::Forms::Button^ button1;
	protected:







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MilitaryName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->costPer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AmountEmpl = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AmountAssig = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCommissariat = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::WhiteSmoke;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::LightSteelBlue;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Number,
					this->MilitaryName, this->Adress, this->costPer, this->AmountEmpl, this->AmountAssig
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::LightBlue;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::Color::Silver;
			this->dataGridView1->Location = System::Drawing::Point(2, 85);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 60;
			this->dataGridView1->RowTemplate->Height = 35;
			this->dataGridView1->Size = System::Drawing::Size(1242, 347);
			this->dataGridView1->TabIndex = 0;
			// 
			// Number
			// 
			this->Number->FillWeight = 50;
			this->Number->HeaderText = L"�";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			// 
			// MilitaryName
			// 
			this->MilitaryName->HeaderText = L"³���������";
			this->MilitaryName->MinimumWidth = 6;
			this->MilitaryName->Name = L"MilitaryName";
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"������";
			this->Adress->MinimumWidth = 6;
			this->Adress->Name = L"Adress";
			// 
			// costPer
			// 
			this->costPer->FillWeight = 50;
			this->costPer->HeaderText = L"������� �� ����������";
			this->costPer->MinimumWidth = 6;
			this->costPer->Name = L"costPer";
			// 
			// AmountEmpl
			// 
			this->AmountEmpl->FillWeight = 50;
			this->AmountEmpl->HeaderText = L"ʳ������ ����������";
			this->AmountEmpl->MinimumWidth = 6;
			this->AmountEmpl->Name = L"AmountEmpl";
			// 
			// AmountAssig
			// 
			this->AmountAssig->FillWeight = 50;
			this->AmountAssig->HeaderText = L"ʳ������ ����������";
			this->AmountAssig->MinimumWidth = 6;
			this->AmountAssig->Name = L"AmountAssig";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->����ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1256, 29);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->��������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Wide Latin", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(74, 25);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(182, 26);
			this->�������ToolStripMenuItem->Text = L"³������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(182, 26);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������ToolStripMenuItem_Click);
			// 
			// addCommissariat
			// 
			this->addCommissariat->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->addCommissariat->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->addCommissariat->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
			this->addCommissariat->Location = System::Drawing::Point(2, 31);
			this->addCommissariat->Name = L"addCommissariat";
			this->addCommissariat->Size = System::Drawing::Size(49, 48);
			this->addCommissariat->TabIndex = 2;
			this->addCommissariat->Text = L"+";
			this->addCommissariat->UseVisualStyleBackColor = true;
			this->addCommissariat->Click += gcnew System::EventHandler(this, &MyForm::addCommissariat_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Pink;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(158, 438);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(948, 36);
			this->button1->TabIndex = 3;
			this->button1->Text = L"��������� ������ ������� �� ��� ������������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Pink;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(158, 524);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(948, 43);
			this->button2->TabIndex = 4;
			this->button2->Text = L"³���������� ������ �� ������� ���������� � ����������";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Pink;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(156, 573);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(948, 41);
			this->button3->TabIndex = 5;
			this->button3->Text = L"³����������, � ���� ���������� ����� 50% �� ������� ����������";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Pink;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(158, 620);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(948, 40);
			this->button4->TabIndex = 6;
			this->button4->Text = L"³����������, � ���� ������� �� ���������� ����� �� ������ �� ��� �����������"
				L"�";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Pink;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(156, 666);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(948, 47);
			this->button5->TabIndex = 7;
			this->button5->Text = L"4 �����������, � ���� ������� ����������  ����� ��������, ����� ������� �� �"
				L"��������� ����� ������\r\n";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Pink;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(158, 480);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(946, 38);
			this->button6->TabIndex = 8;
			this->button6->Text = L"���� ��������� ������ �� ��� ������������, �������� ������� ���������� �� ��"
				L"������ ������� ����������";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Pink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1256, 738);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->addCommissariat);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Commissariat";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}

		   //��� ��������� ������ ��� ���������� � �����
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		setlocale(LC_ALL, "uk_UA.UTF-8"); 

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ fileName = openFileDialog1->FileName;

			// ���������� ���� �� ����� � ����������� C++ �����
			string filePath = msclr::interop::marshal_as<string>(fileName);

			// ³�������� ����
			ifstream inputFile(filePath);
			string firstLine;
			try {
				if (!getline(inputFile, firstLine)) {
					throw 1;
				}
			// ���� �� ������ ��������� ������ �����, �� ���� �� �������
			// ����������� �� ������� �����, ��� ���������� ���� �������
			inputFile.clear();  // ������� ������ ������ (��� ���������� ������������ ���� getline)
			inputFile.seekg(0, ios::beg);  // ����������� �� ������� �����

			// ������� DataGridView ����� ����� ������������� �����
			this->dataGridView1->Rows->Clear();

			// ������� ������ ����� ������������� ����� �����
			InfoAllCommissariat::arrayCommissariat.clear();
			InfoAllCommissariat::AmountAllCommissariat = 0; // ������� ������� ��'����

			// ������� ��� � ����� � ������ �� �������
			CMillitaryCommissariat commissariat;
			while (inputFile >> commissariat) {
				InfoAllCommissariat::arrayCommissariat.push_back(commissariat); // ������ ��'��� �� �������
				InfoAllCommissariat::AmountAllCommissariat++;

				// ������ ��� �� DataGridView
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(this->dataGridView1);

				row->Cells[0]->Value = InfoAllCommissariat::AmountAllCommissariat.ToString();
				row->Cells[1]->Value = gcnew String(commissariat.getName());
				row->Cells[2]->Value = String::Concat(gcnew String(commissariat.getAdress().getStreet()), ", ", gcnew String(commissariat.getAdress().getHouseNumber()));
				row->Cells[3]->Value = commissariat.getCostsPerEmployee().ToString();
				row->Cells[4]->Value = commissariat.getNumberOfEmployees().ToString();
				row->Cells[5]->Value = commissariat.getNumberOfAssigned().ToString();

				this->dataGridView1->Rows->Add(row);

				// ���� ������� ����, ��������� ����������
				if (InfoAllCommissariat::AmountAllCommissariat >= 100) {
					throw 2;
					break;
				}
			}
			inputFile.close();

			if (InfoAllCommissariat::AmountAllCommissariat == 0) {
				throw 3;
			}
		}
			//������� ��������
			catch (int error)
			{
				if (error == 1) {
					MessageBox::Show("���� ������� ��� �� ������� ��������� ���", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				if (error == 2)
				{
					MessageBox::Show("��������� ���������. �������� �� ����� 100 ������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				if (error == 3) {
					MessageBox::Show("��� �� ������� ���������. ������������ ������", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

			}
			
		}
	}

//��� ��������� ��������� ��'���� � ���������
private: System::Void addCommissariat_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		DataEntryForm^ entryForm = gcnew DataEntryForm();
		if (entryForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			string nameStr = msclr::interop::marshal_as<string>(entryForm->GetName());
			wstring wideName = wstring(nameStr.begin(), nameStr.end());

			// �������� ����
			if (wideName.empty()) {
				MessageBox::Show("��'� �� ���� ���� �������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			for (size_t i = 0; i < wideName.length(); i++) {
				if (iswdigit(wideName[i])) {  // ����������, �� � ������ ������
					throw 'a';
				}
			}
			char* nativeName = new char[nameStr.length() + 1];
			strcpy(nativeName, nameStr.c_str());

			// �������� ���� �������� � �����
			string addressStr = msclr::interop::marshal_as<string>(entryForm->GetAddress());
			if (addressStr.empty()) {
				MessageBox::Show("������ �� ���� ���� ���������.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			char* nativeAddress = new char[addressStr.length() + 1];
			strcpy(nativeAddress, addressStr.c_str());
			char* street = strtok(nativeAddress, ",");
			char* houseNumber = strtok(nullptr, ",");

			if (street == nullptr || houseNumber == nullptr) {
				throw 'b';
			}

			int costs = entryForm->GetCosts();
			if (costs == -1) return;

			int employees = entryForm->GetEmployees();
			if (employees == -1) return;

			int assigned = entryForm->GetAssigned();
			if (assigned == -1) return;

			// ��������� ������ ��������� � ������
			CMillitaryCommissariat newCommissariat;
			newCommissariat.setName(nativeName);
			newCommissariat.setAdress().setStreet(street);
			newCommissariat.setAdress().setHouseNumber(houseNumber);
			newCommissariat.setCostsPerEmployee(costs);
			newCommissariat.setNumberOfAssigned(assigned);
			newCommissariat.setNumberOfEmployees(employees);

			InfoAllCommissariat::arrayCommissariat.push_back(newCommissariat);

			// ��������� DataGridView
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row->CreateCells(this->dataGridView1);
			int lastIndex = InfoAllCommissariat::arrayCommissariat.size() - 1;
			row->Cells[0]->Value = (lastIndex + 1).ToString();
			row->Cells[1]->Value = gcnew String(InfoAllCommissariat::arrayCommissariat[lastIndex].getName());
			row->Cells[2]->Value = String::Concat(gcnew String(InfoAllCommissariat::arrayCommissariat[lastIndex].getAdress().getStreet()), ", ", gcnew String(InfoAllCommissariat::arrayCommissariat[lastIndex].getAdress().getHouseNumber()));
			row->Cells[3]->Value = InfoAllCommissariat::arrayCommissariat[lastIndex].getCostsPerEmployee().ToString();
			row->Cells[4]->Value = InfoAllCommissariat::arrayCommissariat[lastIndex].getNumberOfEmployees().ToString();
			row->Cells[5]->Value = InfoAllCommissariat::arrayCommissariat[lastIndex].getNumberOfAssigned().ToString();

			this->dataGridView1->Rows->Add(row);
		}
	}
	//������� �������
	catch (char symbol)
	{
		if (symbol == 'a')
		{
			MessageBox::Show("��'� �� ������� ������ �����", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (symbol == 'b')
		{
			MessageBox::Show("������ �� ���� � ������ '������, �����'.", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (symbol == 'c')
		{
			MessageBox::Show("���� �����, ������ �������� ������� �������!", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;  
		}
		if (symbol == 'd')
		{
			MessageBox::Show("���� �����, ������ �������� ������� �����������!", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (symbol == 'f')
		{
			MessageBox::Show("���� �����, ������ �������� ������� ���������� ���!", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return ;
		}
	}

}


//������ ��� ������� ���������� ������� ������
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	AvarageCost = DefineAvarageCost(InfoAllCommissariat::arrayCommissariat);

	MyForm1^ entryForm = gcnew MyForm1(AvarageCost);
	entryForm->ShowDialog();
}

//������ ��� ������� ���������� ������
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	mergeSort(InfoAllCommissariat::arrayCommissariat, 0, InfoAllCommissariat::arrayCommissariat.size() -1);
	this->dataGridView1->Rows->Clear();
	for (int i = 0; i < InfoAllCommissariat::arrayCommissariat.size(); i++)
	{
		DataGridViewRow^ row = gcnew DataGridViewRow();
		row->CreateCells(this->dataGridView1);

		row->Cells[0]->Value = (i + 1).ToString();
		row->Cells[1]->Value = gcnew String(InfoAllCommissariat::arrayCommissariat[i].getName());
		row->Cells[2]->Value = String::Concat(gcnew String(InfoAllCommissariat::arrayCommissariat[i].getAdress().getStreet()), ", ", gcnew String(InfoAllCommissariat::arrayCommissariat[i].getAdress().getHouseNumber()));
		row->Cells[3]->Value = InfoAllCommissariat::arrayCommissariat[i].getCostsPerEmployee().ToString();
		row->Cells[4]->Value = InfoAllCommissariat::arrayCommissariat[i].getNumberOfEmployees().ToString();
		row->Cells[5]->Value = InfoAllCommissariat::arrayCommissariat[i].getNumberOfAssigned().ToString();

		this->dataGridView1->Rows->Add(row);
	}

}

//������ ��� ������� ���������� �����������, � ���� ���������� ����� 50% �� ������� ����������
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<char*> arrayCommissaritWithLessEmpl;
	getLessAssignThanEmpl(InfoAllCommissariat::arrayCommissariat, arrayCommissaritWithLessEmpl);
	MoreCost^ entryForm = gcnew MoreCost(arrayCommissaritWithLessEmpl);
	entryForm->ShowDialog();
}

//������ ��� ������� ���������� �����������, � ���� ������� �� ���������� ����� �� ������ �� ��� ������������
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<char*> arrayCommissaritWithNoreCosts;
	getMoreCostsPerEmplCommissar(InfoAllCommissariat::arrayCommissariat, arrayCommissaritWithNoreCosts);
	MoreCost^ entryForm = gcnew MoreCost(arrayCommissaritWithNoreCosts);
	entryForm->ShowDialog();
}

//������ ��� ������� ���������� 4 �����������, � ���� ������� ����������  ����� ��������, ����� ������� �� ���������� ����� ������
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	vector<char*> arrayCommissaritWithMoreAssigAndLessCosts;
	getMoreAssigAndLessCosts(InfoAllCommissariat::arrayCommissariat, arrayCommissaritWithMoreAssigAndLessCosts);
	MoreCost^ entryForm = gcnew MoreCost(arrayCommissaritWithMoreAssigAndLessCosts);
	entryForm->ShowDialog();
}

//������ ��� ������� ���������� ���� ��������� ������ �� ��� ������������, �������� ������� ���������� �� �������� ������� ����������
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int allCostsPerEmpl=0, allAssignment=0, allEmployers = 0;
	getGeneralInfo(InfoAllCommissariat::arrayCommissariat, &allCostsPerEmpl, &allEmployers, &allAssignment);
	LessAssign^ entryForm = gcnew LessAssign(allCostsPerEmpl, allAssignment, allEmployers);
	entryForm->ShowDialog();
}



//������ ��� ��������� �����
private: System::Void ��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();

	saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
	saveFileDialog1->FilterIndex = 1;
	saveFileDialog1->RestoreDirectory = true;

	
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// �������� ���� �� �����
		String^ fileName = saveFileDialog1->FileName;
		std::ofstream outFile(msclr::interop::marshal_as<std::string>(fileName));  // ��������� ����� ��� ������ � ����

		if (outFile.is_open()) {
			// ��������� �� ������� �������� ������� � �������� ���� � ����
			for (const auto& commissariat : InfoAllCommissariat::arrayCommissariat) {
				outFile << commissariat << std::endl;  // ������������� �������������� �������� << ��� ���������
				outFile << "--------------------------" << std::endl;  // ��� ��������� ������
			}
			outFile.close();
			MessageBox::Show("Data saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			isFileSaved = true;  // ������������ ����, �� ���� ���������

		}
		else {
			MessageBox::Show("Failed to open file for writing.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
 //������������, ��� ����� ��� ���������� �����
	   private: System::Void Form_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		   if (!isFileSaved) {
			   // ���� ���� �� ����������, �������� � �����������
			   System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
				   "�� ������ �������� ���� ����� �������?",
				   "���������� ����",
				   System::Windows::Forms::MessageBoxButtons::YesNoCancel,
				   System::Windows::Forms::MessageBoxIcon::Warning);

			   if (result == System::Windows::Forms::DialogResult::Yes) {
				   // ��������� ����� ���������� �����
				   ��������ToolStripMenuItem_Click(sender, e);
				   if (!isFileSaved) {
					   // ���� ���� ������ �������� ���� �� ��� �� �� ����������, �� ���������� ��������� �����
					   e->Cancel = true;
				   }
			   }
			   else if (result == System::Windows::Forms::DialogResult::Cancel) {
				   // ���� ���������� �������� Cancel, ������� �������� �����
				   e->Cancel = true;
			   }
			   // ���� ��������� "No", �������� ��������� ��� ����������, � �������� ���������.
		   }
	   }



};
}
