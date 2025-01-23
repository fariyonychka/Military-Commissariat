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
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for MoreCost
	/// </summary>
	public ref class MoreCost : public System::Windows::Forms::Form
	{
	public:
		MoreCost(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	
		   List<String^>^ arrayCommissaritWithLessEmpl;

		MoreCost(vector<char*> true_comm)
		{
			// Ініціалізація списку в .NET
			arrayCommissaritWithLessEmpl = gcnew List<String^>();

			// Копіюємо значення з вектора C++ у список .NET
			for (char* comm : true_comm)
			{
				arrayCommissaritWithLessEmpl->Add(gcnew String(comm));
			}

			InitializeComponent();  // Після ініціалізації полів
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MoreCost()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ textBox1;
	public:
	private: System::Windows::Forms::Button^ button1;

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
			this->textBox1->Location = System::Drawing::Point(125, 48);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(304, 302);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MoreCost::textBox1_TextChanged);
			if (arrayCommissaritWithLessEmpl->Count == 0)
			{
				this->textBox1->AppendText("Немає таких військоматів " + "\r\n");
			}
			else {
				for (int i = 0; i < arrayCommissaritWithLessEmpl->Count; i++)
				{
					String^ name = arrayCommissaritWithLessEmpl[i];
					this->textBox1->AppendText(name + "\r\n");
				}
				if (arrayCommissaritWithLessEmpl->Count < 4)
				{
					this->textBox1->AppendText("Таких військоматів лише " + arrayCommissaritWithLessEmpl->Count + "\r\n");
				}
			}
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MoreCost::button1_Click);
			// 
			// MoreCost
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(554, 522);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MoreCost";
			this->Text = L"MoreCost";
			this->Load += gcnew System::EventHandler(this, &MoreCost::MoreCost_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MoreCost_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
