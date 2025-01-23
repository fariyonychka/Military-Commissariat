#pragma once
#define _CRT_SECURE_NO_WARNINGS

//#include "MilitaryCommissariat.h"
namespace MilitaryCommissariat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm1(double dataFromForm1)
		{
			this->receivedData = dataFromForm1;  // «бер≥гаЇмо передане значенн€

			InitializeComponent();
		}
		double receivedData ;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxInfo;
	private: System::Windows::Forms::Button^ button_ok;
	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxInfo = (gcnew System::Windows::Forms::TextBox());
			this->button_ok = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxInfo
			// 
			this->textBoxInfo->Location = System::Drawing::Point(42, 91);
			this->textBoxInfo->Multiline = true;
			this->textBoxInfo->Name = L"textBoxInfo";
			this->textBoxInfo->Size = System::Drawing::Size(200, 38);
			this->textBoxInfo->TabIndex = 1;
			this->textBoxInfo->Text = receivedData.ToString("F2");

			// 
			// button_ok
			// 
			this->button_ok->Location = System::Drawing::Point(100, 168);
			this->button_ok->Name = L"button_ok";
			this->button_ok->Size = System::Drawing::Size(75, 38);
			this->button_ok->TabIndex = 2;
			this->button_ok->Text = L"OK";
			this->button_ok->UseVisualStyleBackColor = true;
			this->button_ok->Click += gcnew System::EventHandler(this, &MyForm1::button_ok_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->button_ok);
			this->Controls->Add(this->textBoxInfo);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxInfo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		//this->textBoxInfo->Text = receivedData.ToString();

	}
	private: System::Void button_ok_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Close the form after saving

	}
	};
}
