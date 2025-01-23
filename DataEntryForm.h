#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <msclr/marshal_cppstd.h>
#include <iostream>

namespace MilitaryCommissariat {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// DataEntryForm: форма для введення даних
	/// </summary>
	public ref class DataEntryForm : public System::Windows::Forms::Form
	{
	public:
		DataEntryForm(void)
		{
			InitializeComponent();
		}
	public:
		//функції для отримання введених даних з форми
		String^ GetName() { return textBoxName->Text; }
		String^ GetAddress() { return textBoxAddress->Text; }
		int GetCosts() {
			int costs;
			if (!Int32::TryParse(textBoxCosts->Text, costs)) {
				throw 'c';
			}
			return costs;
		}

		int GetEmployees() {
			int employees;
			if (!Int32::TryParse(textBoxEmployees->Text, employees)) {
				throw 'd';
			}
			return employees;
		}

		int GetAssigned() {
			int assigned;
			if (!Int32::TryParse(textBoxAssigned->Text, assigned)) {
				throw 'f';
			}
			return assigned;
		}



	protected:
		~DataEntryForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::TextBox^ textBoxName;
		System::Windows::Forms::TextBox^ textBoxAddress;
		System::Windows::Forms::TextBox^ textBoxCosts;
		System::Windows::Forms::TextBox^ textBoxEmployees;
		System::Windows::Forms::TextBox^ textBoxAssigned;
		System::Windows::Forms::Button^ buttonSave;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCosts = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEmployees = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAssigned = (gcnew System::Windows::Forms::TextBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());

			this->SuspendLayout();

			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(50, 30);
			this->textBoxName->Size = System::Drawing::Size(200, 22);
			this->textBoxName->TabIndex = 0;
			SetPlaceholder(this->textBoxName, "Введіть ім'я");
			this->textBoxName->GotFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxName_GotFocus);
			this->textBoxName->LostFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxName_LostFocus);

			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(50, 70);
			this->textBoxAddress->Size = System::Drawing::Size(200, 22);
			this->textBoxAddress->TabIndex = 1;
			SetPlaceholder(this->textBoxAddress, "Введіть адресу");
			this->textBoxAddress->GotFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxAddress_GotFocus);
			this->textBoxAddress->LostFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxAddress_LostFocus);

			// 
			// textBoxCosts
			// 
			this->textBoxCosts->Location = System::Drawing::Point(50, 110);
			this->textBoxCosts->Size = System::Drawing::Size(200, 22);
			this->textBoxCosts->TabIndex = 2;
			SetPlaceholder(this->textBoxCosts, "Введіть витрати на працівника");
			this->textBoxCosts->GotFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxCosts_GotFocus);
			this->textBoxCosts->LostFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxCosts_LostFocus);

			// 
			// textBoxEmployees
			// 
			this->textBoxEmployees->Location = System::Drawing::Point(50, 150);
			this->textBoxEmployees->Size = System::Drawing::Size(200, 22);
			this->textBoxEmployees->TabIndex = 3;
			SetPlaceholder(this->textBoxEmployees, "Введіть кількість працівників");
			this->textBoxEmployees->GotFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxEmployees_GotFocus);
			this->textBoxEmployees->LostFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxEmployees_LostFocus);

			// 
			// textBoxAssigned
			// 
			this->textBoxAssigned->Location = System::Drawing::Point(50, 190);
			this->textBoxAssigned->Size = System::Drawing::Size(200, 22);
			this->textBoxAssigned->TabIndex = 4;
			SetPlaceholder(this->textBoxAssigned, "Введіть кількість приписаних");
			this->textBoxAssigned->GotFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxAssigned_GotFocus);
			this->textBoxAssigned->LostFocus += gcnew System::EventHandler(this, &DataEntryForm::textBoxAssigned_LostFocus);

			// 
			// buttonSave
			// 
			this->buttonSave->Location = System::Drawing::Point(100, 240);
			this->buttonSave->Text = L"Зберегти";
			this->buttonSave->Click += gcnew System::EventHandler(this, &DataEntryForm::buttonSave_Click);

			// 
			// DataEntryForm
			// 
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->textBoxCosts);
			this->Controls->Add(this->textBoxEmployees);
			this->Controls->Add(this->textBoxAssigned);
			this->Controls->Add(this->buttonSave);
			this->ResumeLayout(false);
		}

#pragma endregion

		// Методи для встановлення та видалення підказки
		void SetPlaceholder(System::Windows::Forms::TextBox^ textBox, String^ placeholder) {
			if (String::IsNullOrEmpty(textBox->Text)) {
				textBox->Text = placeholder;
				textBox->ForeColor = System::Drawing::Color::Gray;
			}
		}

		void RemovePlaceholder(System::Windows::Forms::TextBox^ textBox, String^ placeholder) {
			if (textBox->Text == placeholder) {
				textBox->Text = "";
				textBox->ForeColor = System::Drawing::Color::Black;
			}
		}

		// Події для текстових полів
		void textBoxName_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			RemovePlaceholder(this->textBoxName, "Введіть ім'я");
		}

		void textBoxName_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			SetPlaceholder(this->textBoxName, "Введіть ім'я");
		}

		void textBoxAddress_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			RemovePlaceholder(this->textBoxAddress, "Введіть адресу");
		}

		void textBoxAddress_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			SetPlaceholder(this->textBoxAddress, "Введіть адресу");
		}

		void textBoxCosts_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			RemovePlaceholder(this->textBoxCosts, "Введіть витрати на працівника");
		}

		void textBoxCosts_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			SetPlaceholder(this->textBoxCosts, "Введіть витрати на працівника");
		}

		void textBoxEmployees_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			RemovePlaceholder(this->textBoxEmployees, "Введіть кількість працівників");
		}

		void textBoxEmployees_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			SetPlaceholder(this->textBoxEmployees, "Введіть кількість працівників");
		}

		void textBoxAssigned_GotFocus(System::Object^ sender, System::EventArgs^ e) {
			RemovePlaceholder(this->textBoxAssigned, "Введіть кількість приписаних");
		}

		void textBoxAssigned_LostFocus(System::Object^ sender, System::EventArgs^ e) {
			SetPlaceholder(this->textBoxAssigned, "Введіть кількість приписаних");
		}

		// Подія для кнопки збереження
		void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
			if (String::IsNullOrWhiteSpace(this->textBoxName->Text) ||
				String::IsNullOrWhiteSpace(this->textBoxAddress->Text) ||
				String::IsNullOrWhiteSpace(this->textBoxCosts->Text) ||
				String::IsNullOrWhiteSpace(this->textBoxEmployees->Text) ||
				String::IsNullOrWhiteSpace(this->textBoxAssigned->Text)) {
				MessageBox::Show("Будь ласка, заповніть всі поля!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			

			this->DialogResult = System::Windows::Forms::DialogResult::OK; // Set dialog result
			this->Close(); // Close the form after saving
		}
	};
}
