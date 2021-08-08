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
	/// Summary for AccountShow
	/// </summary>
	public ref class AccountShow : public System::Windows::Forms::UserControl
	{
	public:
		String^ e_mail;
		
		void Draw(String^ email)
		{
			if (email == FacebookSys::user_email)
			{
				RequestPanel->Visible = false;

				RequestSentPanel->Visible = false;
				AddFriendPanel->Visible = false;
				FriendsPanel->Visible = false;
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getrequests()->Contains(email))
			{
				RequestPanel->Visible = true;

				RequestSentPanel->Visible = false;
				AddFriendPanel->Visible = false;
				FriendsPanel->Visible = false;
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getfriends()->Contains(email))
			{
				RequestPanel->Visible = false;
				RequestSentPanel->Visible = false;
				AddFriendPanel->Visible = false;

				FriendsPanel->Visible = true;
				FriendsPanel->Location = RequestPanel->Location;
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetrequestedFriends()->Contains(email))
			{
				RequestPanel->Visible = false;
				FriendsPanel->Visible = false;
				AddFriendPanel->Visible = false;

				RequestSentPanel->Visible = true;
				RequestSentPanel->Location = RequestPanel->Location;

			}
			else
			{
				RequestPanel->Visible = false;
				FriendsPanel->Visible = false;
				RequestSentPanel->Visible = false;

				AddFriendPanel->Visible = true;

				AddFriendPanel->Location = RequestPanel->Location;
			}
		}
		AccountShow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AccountShow(String^email,String^ ReactType)
		{

			InitializeComponent();
			e_mail = email;
			AccountName->Text = FacebookSys::AllAccounts[email]->GetAccountUserName();
			if (FacebookSys::AllAccounts[email]->GetAccountGender()=="Female")
			pictureBox1->BackgroundImage=Image::FromFile(FacebookSys::femaleicon_image);
			if (ReactType == "")
				pictureBox2->Visible = false;
			else
			{
				pictureBox2->Visible = true;
				if (ReactType == "love")
					pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::loveimage);
				if (ReactType == "haha")
					pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::hahaimage);
				if (ReactType == "wow")
					pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::wowimage);
				if (ReactType == "angry")
					pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::angryimage);
				if (ReactType == "sad")
					pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::sadimage);
				
			}

			Draw(email);

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccountShow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  FriendsPanel;
	protected:
	private: Bunifu::Framework::UI::BunifuThinButton2^  FriendsButton;
	private: System::Windows::Forms::Panel^  panel1;
	private: Bunifu::Framework::UI::BunifuThinButton2^  bunifuThinButton21;
	private: System::Windows::Forms::Panel^  RequestSentPanel;
	private: System::Windows::Forms::Label^  label2;
	private: Bunifu::Framework::UI::BunifuThinButton2^  UndoButton;
	private: System::Windows::Forms::Panel^  AddFriendPanel;
	private: Bunifu::Framework::UI::BunifuFlatButton^  AddFriendButton;
	private: System::Windows::Forms::Panel^  RequestPanel;
	private: Bunifu::Framework::UI::BunifuThinButton2^  DeleteRequestButton;
	private: Bunifu::Framework::UI::BunifuThinButton2^  ConfirmButton;
	private: System::Windows::Forms::Label^  AccountName;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountShow::typeid));
			this->FriendsPanel = (gcnew System::Windows::Forms::Panel());
			this->FriendsButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->RequestSentPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UndoButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->AddFriendPanel = (gcnew System::Windows::Forms::Panel());
			this->AddFriendButton = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->RequestPanel = (gcnew System::Windows::Forms::Panel());
			this->DeleteRequestButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->ConfirmButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->AccountName = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->FriendsPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->RequestSentPanel->SuspendLayout();
			this->AddFriendPanel->SuspendLayout();
			this->RequestPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// FriendsPanel
			// 
			this->FriendsPanel->BackColor = System::Drawing::Color::Transparent;
			this->FriendsPanel->Controls->Add(this->FriendsButton);
			this->FriendsPanel->Controls->Add(this->panel1);
			this->FriendsPanel->Location = System::Drawing::Point(343, 10);
			this->FriendsPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FriendsPanel->Name = L"FriendsPanel";
			this->FriendsPanel->Size = System::Drawing::Size(163, 59);
			this->FriendsPanel->TabIndex = 12;
			// 
			// FriendsButton
			// 
			this->FriendsButton->ActiveBorderThickness = 1;
			this->FriendsButton->ActiveCornerRadius = 10;
			this->FriendsButton->ActiveFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->FriendsButton->ActiveForecolor = System::Drawing::Color::White;
			this->FriendsButton->ActiveLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->FriendsButton->BackColor = System::Drawing::Color::Transparent;
			this->FriendsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FriendsButton.BackgroundImage")));
			this->FriendsButton->ButtonText = L"Friends";
			this->FriendsButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FriendsButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FriendsButton->ForeColor = System::Drawing::Color::White;
			this->FriendsButton->IdleBorderThickness = 1;
			this->FriendsButton->IdleCornerRadius = 10;
			this->FriendsButton->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->FriendsButton->IdleForecolor = System::Drawing::Color::White;
			this->FriendsButton->IdleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->FriendsButton->Location = System::Drawing::Point(4, -1);
			this->FriendsButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->FriendsButton->Name = L"FriendsButton";
			this->FriendsButton->Size = System::Drawing::Size(154, 33);
			this->FriendsButton->TabIndex = 1;
			this->FriendsButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->FriendsButton->Click += gcnew System::EventHandler(this, &AccountShow::FriendsButton_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->bunifuThinButton21);
			this->panel1->Location = System::Drawing::Point(0, 30);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(163, 27);
			this->panel1->TabIndex = 2;
			this->panel1->Visible = false;
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 10;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->BackColor = System::Drawing::Color::White;
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"Unfriend";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 1;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::DimGray;
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::White;
			this->bunifuThinButton21->Location = System::Drawing::Point(4, 4);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(111, 21);
			this->bunifuThinButton21->TabIndex = 3;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &AccountShow::bunifuThinButton21_Click);
			// 
			// RequestSentPanel
			// 
			this->RequestSentPanel->BackColor = System::Drawing::Color::Transparent;
			this->RequestSentPanel->Controls->Add(this->label2);
			this->RequestSentPanel->Controls->Add(this->UndoButton);
			this->RequestSentPanel->Location = System::Drawing::Point(513, 4);
			this->RequestSentPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RequestSentPanel->Name = L"RequestSentPanel";
			this->RequestSentPanel->Size = System::Drawing::Size(117, 52);
			this->RequestSentPanel->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(5, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Request Sent";
			// 
			// UndoButton
			// 
			this->UndoButton->ActiveBorderThickness = 1;
			this->UndoButton->ActiveCornerRadius = 10;
			this->UndoButton->ActiveFillColor = System::Drawing::Color::White;
			this->UndoButton->ActiveForecolor = System::Drawing::Color::DimGray;
			this->UndoButton->ActiveLineColor = System::Drawing::Color::DimGray;
			this->UndoButton->BackColor = System::Drawing::Color::Transparent;
			this->UndoButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"UndoButton.BackgroundImage")));
			this->UndoButton->ButtonText = L"Undo";
			this->UndoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UndoButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UndoButton->ForeColor = System::Drawing::Color::White;
			this->UndoButton->IdleBorderThickness = 1;
			this->UndoButton->IdleCornerRadius = 10;
			this->UndoButton->IdleFillColor = System::Drawing::Color::White;
			this->UndoButton->IdleForecolor = System::Drawing::Color::DimGray;
			this->UndoButton->IdleLineColor = System::Drawing::Color::DimGray;
			this->UndoButton->Location = System::Drawing::Point(4, 17);
			this->UndoButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->UndoButton->Name = L"UndoButton";
			this->UndoButton->Size = System::Drawing::Size(67, 33);
			this->UndoButton->TabIndex = 1;
			this->UndoButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->UndoButton->Click += gcnew System::EventHandler(this, &AccountShow::UndoButton_Click);
			// 
			// AddFriendPanel
			// 
			this->AddFriendPanel->BackColor = System::Drawing::Color::Transparent;
			this->AddFriendPanel->Controls->Add(this->AddFriendButton);
			this->AddFriendPanel->Location = System::Drawing::Point(513, 59);
			this->AddFriendPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AddFriendPanel->Name = L"AddFriendPanel";
			this->AddFriendPanel->Size = System::Drawing::Size(135, 44);
			this->AddFriendPanel->TabIndex = 11;
			// 
			// AddFriendButton
			// 
			this->AddFriendButton->Activecolor = System::Drawing::Color::Transparent;
			this->AddFriendButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddFriendButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->AddFriendButton->BorderRadius = 0;
			this->AddFriendButton->ButtonText = L"Add Friend";
			this->AddFriendButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->AddFriendButton->DisabledColor = System::Drawing::Color::Gray;
			this->AddFriendButton->Iconcolor = System::Drawing::Color::Transparent;
			this->AddFriendButton->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddFriendButton.Iconimage")));
			this->AddFriendButton->Iconimage_right = nullptr;
			this->AddFriendButton->Iconimage_right_Selected = nullptr;
			this->AddFriendButton->Iconimage_Selected = nullptr;
			this->AddFriendButton->IconMarginLeft = 0;
			this->AddFriendButton->IconMarginRight = 0;
			this->AddFriendButton->IconRightVisible = true;
			this->AddFriendButton->IconRightZoom = 0;
			this->AddFriendButton->IconVisible = true;
			this->AddFriendButton->IconZoom = 50;
			this->AddFriendButton->IsTab = false;
			this->AddFriendButton->Location = System::Drawing::Point(8, 2);
			this->AddFriendButton->Name = L"AddFriendButton";
			this->AddFriendButton->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddFriendButton->OnHovercolor = System::Drawing::Color::Transparent;
			this->AddFriendButton->OnHoverTextColor = System::Drawing::Color::Black;
			this->AddFriendButton->selected = false;
			this->AddFriendButton->Size = System::Drawing::Size(122, 40);
			this->AddFriendButton->TabIndex = 5;
			this->AddFriendButton->Text = L"Add Friend";
			this->AddFriendButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->AddFriendButton->Textcolor = System::Drawing::Color::DimGray;
			this->AddFriendButton->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AddFriendButton->Click += gcnew System::EventHandler(this, &AccountShow::AddFriendButton_Click);
			// 
			// RequestPanel
			// 
			this->RequestPanel->BackColor = System::Drawing::Color::Transparent;
			this->RequestPanel->Controls->Add(this->DeleteRequestButton);
			this->RequestPanel->Controls->Add(this->ConfirmButton);
			this->RequestPanel->Location = System::Drawing::Point(89, 44);
			this->RequestPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RequestPanel->Name = L"RequestPanel";
			this->RequestPanel->Size = System::Drawing::Size(170, 44);
			this->RequestPanel->TabIndex = 9;
			// 
			// DeleteRequestButton
			// 
			this->DeleteRequestButton->ActiveBorderThickness = 1;
			this->DeleteRequestButton->ActiveCornerRadius = 10;
			this->DeleteRequestButton->ActiveFillColor = System::Drawing::Color::White;
			this->DeleteRequestButton->ActiveForecolor = System::Drawing::Color::DimGray;
			this->DeleteRequestButton->ActiveLineColor = System::Drawing::Color::DimGray;
			this->DeleteRequestButton->BackColor = System::Drawing::Color::Transparent;
			this->DeleteRequestButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteRequestButton.BackgroundImage")));
			this->DeleteRequestButton->ButtonText = L"Delete";
			this->DeleteRequestButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DeleteRequestButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteRequestButton->ForeColor = System::Drawing::Color::White;
			this->DeleteRequestButton->IdleBorderThickness = 1;
			this->DeleteRequestButton->IdleCornerRadius = 10;
			this->DeleteRequestButton->IdleFillColor = System::Drawing::Color::White;
			this->DeleteRequestButton->IdleForecolor = System::Drawing::Color::DimGray;
			this->DeleteRequestButton->IdleLineColor = System::Drawing::Color::DimGray;
			this->DeleteRequestButton->Location = System::Drawing::Point(97, 4);
			this->DeleteRequestButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->DeleteRequestButton->Name = L"DeleteRequestButton";
			this->DeleteRequestButton->Size = System::Drawing::Size(67, 33);
			this->DeleteRequestButton->TabIndex = 1;
			this->DeleteRequestButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->DeleteRequestButton->Click += gcnew System::EventHandler(this, &AccountShow::DeleteRequestButton_Click);
			// 
			// ConfirmButton
			// 
			this->ConfirmButton->ActiveBorderThickness = 1;
			this->ConfirmButton->ActiveCornerRadius = 10;
			this->ConfirmButton->ActiveFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ConfirmButton->ActiveForecolor = System::Drawing::Color::White;
			this->ConfirmButton->ActiveLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ConfirmButton->BackColor = System::Drawing::Color::Transparent;
			this->ConfirmButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ConfirmButton.BackgroundImage")));
			this->ConfirmButton->ButtonText = L"Confirm";
			this->ConfirmButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ConfirmButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConfirmButton->ForeColor = System::Drawing::Color::White;
			this->ConfirmButton->IdleBorderThickness = 1;
			this->ConfirmButton->IdleCornerRadius = 10;
			this->ConfirmButton->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ConfirmButton->IdleForecolor = System::Drawing::Color::White;
			this->ConfirmButton->IdleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->ConfirmButton->Location = System::Drawing::Point(5, 4);
			this->ConfirmButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ConfirmButton->Name = L"ConfirmButton";
			this->ConfirmButton->Size = System::Drawing::Size(84, 33);
			this->ConfirmButton->TabIndex = 0;
			this->ConfirmButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ConfirmButton->Click += gcnew System::EventHandler(this, &AccountShow::ConfirmButton_Click);
			// 
			// AccountName
			// 
			this->AccountName->AutoSize = true;
			this->AccountName->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AccountName->ForeColor = System::Drawing::Color::DarkBlue;
			this->AccountName->Location = System::Drawing::Point(86, 15);
			this->AccountName->Name = L"AccountName";
			this->AccountName->Size = System::Drawing::Size(112, 19);
			this->AccountName->TabIndex = 8;
			this->AccountName->Text = L"profile name";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(14, 13);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(66, 63);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(289, 24);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(51, 54);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// AccountShow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->FriendsPanel);
			this->Controls->Add(this->RequestSentPanel);
			this->Controls->Add(this->AddFriendPanel);
			this->Controls->Add(this->RequestPanel);
			this->Controls->Add(this->AccountName);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AccountShow";
			this->Size = System::Drawing::Size(549, 130);
			this->FriendsPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->RequestSentPanel->ResumeLayout(false);
			this->RequestSentPanel->PerformLayout();
			this->AddFriendPanel->ResumeLayout(false);
			this->RequestPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ConfirmButton_Click(System::Object^  sender, System::EventArgs^  e) {
		FacebookSys::AllAccounts[FacebookSys::user_email]->addFriendOrfollowed(e_mail, "Friend");
		FacebookSys::insetFriendshiptDB(e_mail, "Friend");
		FacebookSys::DeleteRequest(e_mail);
		// function deletes from object
		FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_Request(e_mail);


		//show the friends panel
		Draw(e_mail);
	}
			
private: System::Void DeleteRequestButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::DeleteRequest(e_mail);
	// function deletes from object
	FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_Request(e_mail);
	Draw(e_mail);
}
private: System::Void FriendsButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel1->Visible == false)
		panel1->Visible = true;
	else
		panel1->Visible = false;
}
private: System::Void bunifuThinButton21_Click(System::Object^  sender, System::EventArgs^  e) {
	//delete friendship from database and the hole dictionary
	FacebookSys::Delete_Friendship(e_mail);
	FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_FriendShip(e_mail);
	Draw(e_mail);
}
private: System::Void UndoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// delete request sent to someone from DB and dictionary
	FacebookSys::DeleteRequest(e_mail);
	FacebookSys::AllAccounts[e_mail]->Delete_Request(FacebookSys::user_email);
	Draw(e_mail);
}
private: System::Void AddFriendButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::request(e_mail);
	FacebookSys::AllAccounts[FacebookSys::user_email]->addRequest(e_mail);
	Draw(e_mail);
}
};
}
