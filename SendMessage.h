#pragma once
#include"FacebookSys.h"

namespace FacebookSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SendMessage
	/// </summary>
	public ref class SendMessage : public System::Windows::Forms::Form
	{
	public:
		SendMessage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			

		}
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: System::Windows::Forms::Label^  label1;
	public:
		String^Email;
		SendMessage(String^mail)
		{
			InitializeComponent();
			Email = mail;
			label1->Text += FacebookSys::AllAccounts[mail]->GetAccountUserName();
			//
			//TODO: Add the constructor code here
			//
			
			


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SendMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SendMessage::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(1, 31);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(396, 112);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(319, 147);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(68, 26);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SendMessage::button1_Click);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(370, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(25, 27);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 2;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &SendMessage::bunifuImageButton1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"To ";
			// 
			// SendMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->ClientSize = System::Drawing::Size(399, 177);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bunifuImageButton1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"SendMessage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SendMessage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Conversation^ newConverstion = gcnew Conversation();
		if (FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()->Count == 0)
		{
			int convID = FacebookSys::Makeing_Conversation();
			FacebookSys::UsersConversations(Email, convID);
			FacebookSys::UsersConversations(FacebookSys::user_email, convID);

			FacebookSys::AllAccounts[FacebookSys::user_email]->addConversation(convID,newConverstion);
			FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationUsers(convID, Email);
			FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationUsers(convID, FacebookSys::user_email);

			FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationMessages(convID, FacebookSys::user_email, richTextBox1->Text);
			FacebookSys::Make_Messages(richTextBox1->Text, convID);
		}
		else
		{
			for each (KeyValuePair<int, Conversation^> var in FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations())
			{
				if (var.Value->GetUserEmails()->Contains(Email) && var.Value->GetUserEmails()->Count == 1)
				{
					FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationMessages(var.Key, FacebookSys::user_email, richTextBox1->Text);
					FacebookSys::Make_Messages(richTextBox1->Text, var.Key);
				}
				else
				{
					int convID = FacebookSys::Makeing_Conversation();
					FacebookSys::UsersConversations(Email, convID);
					FacebookSys::UsersConversations(FacebookSys::user_email, convID);

					FacebookSys::AllAccounts[FacebookSys::user_email]->addConversation(convID, newConverstion);
					FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationUsers(convID, Email);
					FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationUsers(convID, FacebookSys::user_email);

					FacebookSys::AllAccounts[FacebookSys::user_email]->addConversationMessages(convID, FacebookSys::user_email, richTextBox1->Text);
					FacebookSys::Make_Messages(richTextBox1->Text, convID);

				}
			}
		}

		
		MessageBox::Show("Message Sent");
		this->Close();
	}
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
