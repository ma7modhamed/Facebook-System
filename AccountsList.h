#pragma once
#include"AccountControl.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for AccountsList
	/// </summary>
	public ref class AccountsList : public System::Windows::Forms::UserControl
	{
	private:
		Form^frm;
		UserControl^user;
	public:
		AccountsList(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AccountsList(int width,String^stat)
		{
			InitializeComponent();
			label1->Text = stat;
			this->Width = width-10;
		}
		AccountsList(String^stat)
		{
			InitializeComponent();

			label1->Text = stat;
		}
		AccountsList(UserControl^control,String^Stat)
		{
			InitializeComponent();

			user = control;
			label1->Text = Stat;
		}
		
		void AddAccount(String^stat)
		{
			AccountControl^acc = gcnew AccountControl(stat);
			flowLayoutPanel1->Controls->Add(acc);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccountsList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;

	private: System::Windows::Forms::Label^  label1;
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
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(484, 68);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(24, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// AccountsList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AccountsList";
			this->Size = System::Drawing::Size(369, 596);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (user != nullptr)
			user->Show();
	}
};
}
