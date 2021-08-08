#pragma once
#include"FacebookSys.h"
#include "oneMessage.h"
namespace FacebookSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Messenger
	/// </summary>
	public ref class Messenger : public System::Windows::Forms::Form
	{
	public:
		int cID,hi;
	private: Bunifu::Framework::UI::BunifuDragControl^  bunifuDragControl1;
	public:
		Messenger(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Messenger(int id)
		{
			InitializeComponent();
			cID = id;
			hi = 75;
			for each (KeyValuePair<String^,String^> mes in FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[id]->GetMessages())
			{
				oneMessage^ message = gcnew oneMessage(mes.Value,mes.Key);
				panel2->Controls->Add(message);
				message->Top = hi;
				if (mes.Key == FacebookSys::user_email)
					message->Left = panel2->Right - 330;

				hi = message->Bottom;
					

			}
			String^ email;
			for each (String^ mail in FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[id]->GetUserEmails())
			{
				if (mail != FacebookSys::user_email)
					email = mail;
			}
			
			label2->Text = FacebookSys::AllAccounts[email]->GetAccountUserName();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Messenger()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton2;
	private: Bunifu::Framework::UI::BunifuTextbox^  bunifuTextbox1;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Messenger::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton2 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuTextbox1 = (gcnew Bunifu::Framework::UI::BunifuTextbox());
			this->bunifuDragControl1 = (gcnew Bunifu::Framework::UI::BunifuDragControl(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1047, 42);
			this->panel1->TabIndex = 0;
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(1001, 3);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(31, 36);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 0;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &Messenger::bunifuImageButton1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Maiandra GD", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(11, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Messenger";
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel2->Location = System::Drawing::Point(3, 91);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1041, 636);
			this->panel2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(497, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(3, 43);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1041, 48);
			this->panel3->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Gainsboro;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->bunifuImageButton2);
			this->panel4->Controls->Add(this->bunifuTextbox1);
			this->panel4->Location = System::Drawing::Point(3, 727);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(1041, 55);
			this->panel4->TabIndex = 1;
			// 
			// bunifuImageButton2
			// 
			this->bunifuImageButton2->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.Image")));
			this->bunifuImageButton2->ImageActive = nullptr;
			this->bunifuImageButton2->Location = System::Drawing::Point(967, 4);
			this->bunifuImageButton2->Name = L"bunifuImageButton2";
			this->bunifuImageButton2->Size = System::Drawing::Size(36, 44);
			this->bunifuImageButton2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton2->TabIndex = 4;
			this->bunifuImageButton2->TabStop = false;
			this->bunifuImageButton2->Zoom = 10;
			this->bunifuImageButton2->Click += gcnew System::EventHandler(this, &Messenger::bunifuImageButton2_Click);
			// 
			// bunifuTextbox1
			// 
			this->bunifuTextbox1->BackColor = System::Drawing::Color::Gainsboro;
			this->bunifuTextbox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox1.BackgroundImage")));
			this->bunifuTextbox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuTextbox1->ForeColor = System::Drawing::Color::Black;
			this->bunifuTextbox1->Icon = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTextbox1.Icon")));
			this->bunifuTextbox1->Location = System::Drawing::Point(31, 5);
			this->bunifuTextbox1->Name = L"bunifuTextbox1";
			this->bunifuTextbox1->Size = System::Drawing::Size(922, 42);
			this->bunifuTextbox1->TabIndex = 3;
			this->bunifuTextbox1->text = L"";
			// 
			// bunifuDragControl1
			// 
			this->bunifuDragControl1->Fixed = true;
			this->bunifuDragControl1->Horizontal = true;
			this->bunifuDragControl1->TargetControl = this->panel1;
			this->bunifuDragControl1->Vertical = true;
			// 
			// Messenger
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(132)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1047, 784);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Messenger";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Messenger";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void bunifuImageButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationMessages(cID, FacebookSys::user_email, bunifuTextbox1->text);
	FacebookSys::Make_Messages(bunifuTextbox1->text, cID);
	oneMessage^ message = gcnew oneMessage(bunifuTextbox1->text, FacebookSys::user_email);
	panel2->Controls->Add(message);
	message->Top = hi;
		message->Left = panel2->Right- 330;
		bunifuTextbox1->text = "";

}
};
}
