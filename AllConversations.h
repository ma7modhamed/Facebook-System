#pragma once
#include"ConversationLastMessage.h"
#include"FacebookSys.h"
#include"Conversation.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for AllConversations
	/// </summary>
	public ref class AllConversations : public System::Windows::Forms::UserControl
	{
	public:
		AllConversations(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AllConversations(String^mail)
		{
			InitializeComponent();
			for each (KeyValuePair<int,Conversation^>  conv in FacebookSys::AllAccounts[mail]->getmyConversations())
			{
				addconversation(conv.Key);
			} 

		}
		void addconversation(int id)
		{
			ConversationLastMessage^ c = gcnew ConversationLastMessage(id);
			flowLayoutPanel1->Controls->Add(c);
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AllConversations()
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
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(11, 33);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(171, 81);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"My Conversations";
			// 
			// AllConversations
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AllConversations";
			this->Size = System::Drawing::Size(537, 548);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
