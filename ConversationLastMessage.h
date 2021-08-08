#pragma once
#include "FacebookSys.h"
#include "Messenger.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for ConversationLastMessage
	/// </summary>
	public ref class ConversationLastMessage : public System::Windows::Forms::UserControl
	{
	public:
		int cId;
		ConversationLastMessage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		ConversationLastMessage(int convID)
		{
			InitializeComponent();
			cId = convID;
			
			int messagesCount = FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[convID]->GetMessages()->Count;
			
			
			if (FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[convID]->GetMessages()[messagesCount - 1].Key == FacebookSys::user_email)
				label1->Visible = true;
			LastMessageSent->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[convID]->GetMessages()[messagesCount - 1].Value;
			String^ email;
			for each (String^ em in FacebookSys::AllAccounts[FacebookSys::user_email]->getmyConversations()[convID]->GetUserEmails())
			{
				if (em != FacebookSys::user_email)
					email = em;
			}
			LastSenderName->Text = FacebookSys::AllAccounts[email]->GetAccountUserName();
			if (FacebookSys::AllAccounts[email]->GetAccountGender() == "Female")
				pictureBox1->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConversationLastMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  LastSenderName;
	private: System::Windows::Forms::Label^  LastMessageSent;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ConversationLastMessage::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->LastSenderName = (gcnew System::Windows::Forms::Label());
			this->LastMessageSent = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(10, 11);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(66, 66);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// LastSenderName
			// 
			this->LastSenderName->AutoSize = true;
			this->LastSenderName->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LastSenderName->ForeColor = System::Drawing::Color::DarkBlue;
			this->LastSenderName->Location = System::Drawing::Point(98, 18);
			this->LastSenderName->Name = L"LastSenderName";
			this->LastSenderName->Size = System::Drawing::Size(43, 14);
			this->LastSenderName->TabIndex = 1;
			this->LastSenderName->Text = L"label1";
			// 
			// LastMessageSent
			// 
			this->LastMessageSent->AutoSize = true;
			this->LastMessageSent->Location = System::Drawing::Point(118, 51);
			this->LastMessageSent->Name = L"LastMessageSent";
			this->LastMessageSent->Size = System::Drawing::Size(35, 13);
			this->LastMessageSent->TabIndex = 2;
			this->LastMessageSent->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"You:";
			this->label1->Visible = false;
			// 
			// ConversationLastMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LastMessageSent);
			this->Controls->Add(this->LastSenderName);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ConversationLastMessage";
			this->Size = System::Drawing::Size(395, 102);
			this->Load += gcnew System::EventHandler(this, &ConversationLastMessage::ConversationLastMessage_Load);
			this->Click += gcnew System::EventHandler(this, &ConversationLastMessage::ConversationLastMessage_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ConversationLastMessage_Click(System::Object^  sender, System::EventArgs^  e) {
		//show chat
		Messenger^ chat = gcnew Messenger(cId);
		chat->Show();
	}
	private: System::Void ConversationLastMessage_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
	}
};
}
