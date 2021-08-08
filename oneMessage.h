#pragma once
#include "FacebookSys.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for oneMessage
	/// </summary>
	public ref class oneMessage : public System::Windows::Forms::UserControl
	{
	public:
		oneMessage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		oneMessage(String^message, String^senderMail)
		{
			InitializeComponent();

			label1->Text = message;
			LastSenderName->Text = FacebookSys::AllAccounts[senderMail]->GetAccountUserName();
			Graphics^g = CreateGraphics();
			SizeF^ ss = g->MeasureString(message, label1->Font, 270);
			label1->Height = Math::Round(ss->Height + 10, 0);
			pictureBox2->Height = label1->Height + 10;
			this->Height = pictureBox2->Height + 40;
			if (FacebookSys::user_email == senderMail)
			{
				label1->BackColor = System::Drawing::Color::FromArgb(0, 125, 255);
				label1->ForeColor = Color::White;
				this->Height = pictureBox2->Height + 20;
				LastSenderName->Visible = false;
				pictureBox1->Visible = false;
				pictureBox2->BackgroundImage = Image::FromFile(System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\free-vector-pill-button-blue-clip-art_116761_Pillbuttonblue_clip_art_hight.png");
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~oneMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  LastSenderName;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(oneMessage::typeid));
			this->LastSenderName = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// LastSenderName
			// 
			this->LastSenderName->AutoSize = true;
			this->LastSenderName->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LastSenderName->ForeColor = System::Drawing::Color::DarkBlue;
			this->LastSenderName->Location = System::Drawing::Point(60, 6);
			this->LastSenderName->Name = L"LastSenderName";
			this->LastSenderName->Size = System::Drawing::Size(43, 14);
			this->LastSenderName->TabIndex = 3;
			this->LastSenderName->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(3, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(51, 51);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->label1->Location = System::Drawing::Point(68, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(60, 23);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(277, 47);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// oneMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Controls->Add(this->label1);
			this->Controls->Add(this->LastSenderName);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Name = L"oneMessage";
			this->Size = System::Drawing::Size(344, 74);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
