#pragma once
#include"FacebookSys.h"
#include"AccountShow.h"
#include "Reactors.h"		
namespace FacebookSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Users
	/// </summary>
	public ref class Users : public System::Windows::Forms::Form
	{
	public:
		Users(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Users(String^email)
		{
			InitializeComponent();
			label1->Text = "Mutual Friends";
			
			//if ((FacebookSys::AllAccounts[FacebookSys::user_email] & FacebookSys::AllAccounts[email])->Count != 0)
			for each (String^ mutual in FacebookSys::AllAccounts[FacebookSys::user_email] & FacebookSys::AllAccounts[email])
			{
				AddAccount(mutual, "");
			}
			
		}
		Users(Reactors^ reactors)
		{
			InitializeComponent();
			
			label1->Text = reactors->GettotalReactors()->Count.ToString() + " Reactors";
			for each (KeyValuePair<String^,String^> reac  in reactors->GettotalReactors())
			{
				AddAccount(reac.Key, reac.Value);
			}
			
			
		}
		void AddAccount(String^email,String^ React)
		{
			AccountShow^ acc = gcnew AccountShow(email, React);
			flowLayoutPanel1->Controls->Add(acc);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Users()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Users::typeid));
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(506, 5);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(26, 34);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 0;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &Users::bunifuImageButton1_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 58);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(539, 500);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Location = System::Drawing::Point(12, 11);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(539, 44);
			this->panel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// Users
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(551, 567);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Users";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Users";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
