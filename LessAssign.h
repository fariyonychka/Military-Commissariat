#pragma once
#include <vector>
using namespace std;
namespace MilitaryCommissariat {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;  // Для List<T>


	/// <summary>
	/// Summary for LessAssign
	/// </summary>
	public ref class LessAssign : public System::Windows::Forms::Form
	{
	public:
		LessAssign(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Button^ button1;
		   int allCosts, allAssignmet, allEmployers;
	public:

		LessAssign(int Costs, int Assignmet, int Employers)
		{
			this->allCosts = Costs;
			this->allAssignmet = Assignmet;
			this->allEmployers = Employers;

			InitializeComponent();  // Після ініціалізації полів
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LessAssign()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(133, 23);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(308, 354);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LessAssign::textBox1_TextChanged);
			
				this->textBox1->AppendText("Загальні витрати: "+allCosts.ToString() + "\r\n"+ "Загальні кількість працівників: " + allEmployers.ToString() +  "\r\n"+"Загальна кількість приписаних: " + allAssignmet.ToString() + "\r\n");
			
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(257, 411);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 40);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LessAssign::button1_Click);
			// 
			// LessAssign
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 466);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"LessAssign";
			this->Text = L"LessAssign";
			this->Load += gcnew System::EventHandler(this, &LessAssign::LessAssign_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LessAssign_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Close the form after saving

	}
	};
}
