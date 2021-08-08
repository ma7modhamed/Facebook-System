#pragma once
#include"newsFeed.h"
#include"Users.h"
#include "SeeFriendship.h"
#include"SendMessage.h"
#include "Messenger.h"
namespace FacebookSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserProfile
	/// </summary>
	public ref class UserProfile : public System::Windows::Forms::Form
	{
	public:
		String^ e_mail;
		void Draw(String^ email)
		{
			if (email == FacebookSys::user_email)
			{
				panel3->Visible = false;
				panel5->Top = pictureBox4->Bottom + 5;
				panel5->Height += 90;
				MessageButton->Visible = false;
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getrequests()->Contains(email))
			{
				RequestPanel->Visible = true;

				RequestSentPanel->Visible = false;
				AddFriendPanel->Visible = false;
				FriendsPanel->Visible = false;
				if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getfollowed_users()->Contains(email))
				{
					followingPanel->Visible = true;
					followingPanel->Location = followPanel->Location;
					followPanel->Visible = false;
				}
				else
				{
					followingPanel->Visible = false;
					followPanel->Visible = true;
				}
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getfriends()->Contains(email))
			{
				RequestPanel->Visible = false;
				RequestSentPanel->Visible = false;
				AddFriendPanel->Visible = false;

				FriendsPanel->Visible = true;
				FriendsPanel->Location = RequestPanel->Location;
				followingPanel->Visible = false;
				followPanel->Visible = false;
				
				
			}
			else if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetrequestedFriends()->Contains(email))
			{
				RequestPanel->Visible = false;
				FriendsPanel->Visible = false;
				AddFriendPanel->Visible = false;

				RequestSentPanel->Visible = true;
				RequestSentPanel->Location = RequestPanel->Location;
				followingPanel->Visible = false;
				followPanel->Visible = false;
				
				

			}
			else
			{
				RequestPanel->Visible = false;
				FriendsPanel->Visible = false;
				RequestSentPanel->Visible = false;

				AddFriendPanel->Visible = true;

				AddFriendPanel->Location = RequestPanel->Location;
				if (FacebookSys::AllAccounts[FacebookSys::user_email]->Getfollowed_users()->Contains(email))
				{
					followingPanel->Visible = true;
					followingPanel->Location = followPanel->Location;
					followPanel->Visible = false;
				}
				else
				{
					followingPanel->Visible = false;
					followPanel->Visible = true;
				}
				
			}
		}
		UserProfile(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		UserProfile(String^user_email)
		{
			InitializeComponent();
			e_mail = user_email;
			profileName->Text = FacebookSys::AllAccounts[user_email]->GetAccountUserName();
			Birthdate->Text = FacebookSys::AllAccounts[user_email]->GetAccountBirthDate();
			Gender->Text = FacebookSys::AllAccounts[user_email]->GetAccountGender();
			if (FacebookSys::AllAccounts[user_email]->GetAccountGender() == "Female")
			{
				pictureBox4->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
				pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);

			}
				
			Draw(user_email);
		
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserProfile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  profileName;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Panel^  panel1;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  Birthdate;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  Gender;
	private: System::Windows::Forms::Panel^  FriendsPanel;

	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::Panel^  RequestSentPanel;
	private: System::Windows::Forms::Label^  label2;
	private: Bunifu::Framework::UI::BunifuThinButton2^  UndoButton;
	private: System::Windows::Forms::Panel^  AddFriendPanel;
	private: Bunifu::Framework::UI::BunifuFlatButton^  AddFriendButton;
	private: System::Windows::Forms::Panel^  RequestPanel;
	private: Bunifu::Framework::UI::BunifuThinButton2^  DeleteRequestButton;
	private: Bunifu::Framework::UI::BunifuThinButton2^  ConfirmButton;
	private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::Panel^  followPanel;
private: Bunifu::Framework::UI::BunifuTileButton^  FriendsButton;


private: Bunifu::Framework::UI::BunifuThinButton2^  bunifuThinButton22;
private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton1;
private: Bunifu::Framework::UI::BunifuTileButton^  MoreButton;

private: Bunifu::Framework::UI::BunifuTileButton^  MessageButton;

private: System::Windows::Forms::Panel^  followingPanel;

private: Bunifu::Framework::UI::BunifuTileButton^  bunifuTileButton3;
private: System::Windows::Forms::Panel^  panel6;
private: Bunifu::Framework::UI::BunifuThinButton2^  unfollowButton;


private: System::Windows::Forms::Panel^  panel4;
private: System::Windows::Forms::Panel^  panel5;
private: System::Windows::Forms::Panel^  panel7;
private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton2;
private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton3;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UserProfile::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->profileName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->Birthdate = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->Gender = (gcnew System::Windows::Forms::Label());
			this->FriendsPanel = (gcnew System::Windows::Forms::Panel());
			this->FriendsButton = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bunifuThinButton22 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->AddFriendPanel = (gcnew System::Windows::Forms::Panel());
			this->AddFriendButton = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->RequestSentPanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->UndoButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->RequestPanel = (gcnew System::Windows::Forms::Panel());
			this->DeleteRequestButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->ConfirmButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->MoreButton = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->followPanel = (gcnew System::Windows::Forms::Panel());
			this->bunifuFlatButton1 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->MessageButton = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->followingPanel = (gcnew System::Windows::Forms::Panel());
			this->bunifuTileButton3 = (gcnew Bunifu::Framework::UI::BunifuTileButton());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->unfollowButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->bunifuFlatButton2 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuFlatButton3 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->FriendsPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->AddFriendPanel->SuspendLayout();
			this->RequestSentPanel->SuspendLayout();
			this->RequestPanel->SuspendLayout();
			this->panel3->SuspendLayout();
			this->followPanel->SuspendLayout();
			this->followingPanel->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(339, 44);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(735, 368);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Location = System::Drawing::Point(376, 379);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(95, 90);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// profileName
			// 
			this->profileName->AutoSize = true;
			this->profileName->BackColor = System::Drawing::Color::White;
			this->profileName->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->profileName->ForeColor = System::Drawing::Color::DarkBlue;
			this->profileName->Location = System::Drawing::Point(476, 417);
			this->profileName->Name = L"profileName";
			this->profileName->Size = System::Drawing::Size(133, 23);
			this->profileName->TabIndex = 2;
			this->profileName->Text = L"Profile Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(513, 454);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Was Born in";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1386, 47);
			this->panel1->TabIndex = 5;
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(3, 3);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(33, 39);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 6;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &UserProfile::bunifuImageButton1_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(476, 446);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 30);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// Birthdate
			// 
			this->Birthdate->AutoSize = true;
			this->Birthdate->BackColor = System::Drawing::Color::White;
			this->Birthdate->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Birthdate->Location = System::Drawing::Point(588, 454);
			this->Birthdate->Name = L"Birthdate";
			this->Birthdate->Size = System::Drawing::Size(73, 13);
			this->Birthdate->TabIndex = 7;
			this->Birthdate->Text = L"Was Born in";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::White;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(478, 476);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(27, 24);
			this->pictureBox4->TabIndex = 8;
			this->pictureBox4->TabStop = false;
			// 
			// Gender
			// 
			this->Gender->AutoSize = true;
			this->Gender->BackColor = System::Drawing::Color::White;
			this->Gender->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Gender->Location = System::Drawing::Point(513, 481);
			this->Gender->Name = L"Gender";
			this->Gender->Size = System::Drawing::Size(34, 13);
			this->Gender->TabIndex = 9;
			this->Gender->Text = L"Male";
			// 
			// FriendsPanel
			// 
			this->FriendsPanel->BackColor = System::Drawing::Color::Transparent;
			this->FriendsPanel->Controls->Add(this->FriendsButton);
			this->FriendsPanel->Controls->Add(this->panel2);
			this->FriendsPanel->Location = System::Drawing::Point(550, 12);
			this->FriendsPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FriendsPanel->Name = L"FriendsPanel";
			this->FriendsPanel->Size = System::Drawing::Size(177, 89);
			this->FriendsPanel->TabIndex = 13;
			// 
			// FriendsButton
			// 
			this->FriendsButton->BackColor = System::Drawing::Color::Transparent;
			this->FriendsButton->color = System::Drawing::Color::Transparent;
			this->FriendsButton->colorActive = System::Drawing::Color::Transparent;
			this->FriendsButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FriendsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FriendsButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->FriendsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FriendsButton.Image")));
			this->FriendsButton->ImagePosition = 15;
			this->FriendsButton->ImageZoom = 50;
			this->FriendsButton->LabelPosition = 31;
			this->FriendsButton->LabelText = L"Friends";
			this->FriendsButton->Location = System::Drawing::Point(4, 4);
			this->FriendsButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->FriendsButton->Name = L"FriendsButton";
			this->FriendsButton->Size = System::Drawing::Size(70, 73);
			this->FriendsButton->TabIndex = 16;
			this->FriendsButton->Click += gcnew System::EventHandler(this, &UserProfile::FriendsButton_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->bunifuThinButton22);
			this->panel2->Location = System::Drawing::Point(81, 30);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(86, 27);
			this->panel2->TabIndex = 2;
			this->panel2->Visible = false;
			// 
			// bunifuThinButton22
			// 
			this->bunifuThinButton22->ActiveBorderThickness = 1;
			this->bunifuThinButton22->ActiveCornerRadius = 10;
			this->bunifuThinButton22->ActiveFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->ActiveForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton22->ActiveLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->BackColor = System::Drawing::Color::White;
			this->bunifuThinButton22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton22.BackgroundImage")));
			this->bunifuThinButton22->ButtonText = L"Unfriend";
			this->bunifuThinButton22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton22->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton22->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton22->IdleBorderThickness = 1;
			this->bunifuThinButton22->IdleCornerRadius = 1;
			this->bunifuThinButton22->IdleFillColor = System::Drawing::Color::White;
			this->bunifuThinButton22->IdleForecolor = System::Drawing::Color::DimGray;
			this->bunifuThinButton22->IdleLineColor = System::Drawing::Color::White;
			this->bunifuThinButton22->Location = System::Drawing::Point(5, 4);
			this->bunifuThinButton22->Margin = System::Windows::Forms::Padding(4);
			this->bunifuThinButton22->Name = L"bunifuThinButton22";
			this->bunifuThinButton22->Size = System::Drawing::Size(80, 21);
			this->bunifuThinButton22->TabIndex = 4;
			this->bunifuThinButton22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton22->Click += gcnew System::EventHandler(this, &UserProfile::bunifuThinButton22_Click);
			// 
			// AddFriendPanel
			// 
			this->AddFriendPanel->BackColor = System::Drawing::Color::Transparent;
			this->AddFriendPanel->Controls->Add(this->AddFriendButton);
			this->AddFriendPanel->Location = System::Drawing::Point(186, 60);
			this->AddFriendPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->AddFriendPanel->Name = L"AddFriendPanel";
			this->AddFriendPanel->Size = System::Drawing::Size(135, 44);
			this->AddFriendPanel->TabIndex = 12;
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
			this->AddFriendButton->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddFriendButton->OnHoverTextColor = System::Drawing::Color::Black;
			this->AddFriendButton->selected = false;
			this->AddFriendButton->Size = System::Drawing::Size(122, 40);
			this->AddFriendButton->TabIndex = 5;
			this->AddFriendButton->Text = L"Add Friend";
			this->AddFriendButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->AddFriendButton->Textcolor = System::Drawing::Color::DimGray;
			this->AddFriendButton->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AddFriendButton->Click += gcnew System::EventHandler(this, &UserProfile::AddFriendButton_Click);
			// 
			// RequestSentPanel
			// 
			this->RequestSentPanel->BackColor = System::Drawing::Color::Transparent;
			this->RequestSentPanel->Controls->Add(this->label2);
			this->RequestSentPanel->Controls->Add(this->UndoButton);
			this->RequestSentPanel->Location = System::Drawing::Point(3, 50);
			this->RequestSentPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RequestSentPanel->Name = L"RequestSentPanel";
			this->RequestSentPanel->Size = System::Drawing::Size(117, 52);
			this->RequestSentPanel->TabIndex = 11;
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
			this->UndoButton->Margin = System::Windows::Forms::Padding(4);
			this->UndoButton->Name = L"UndoButton";
			this->UndoButton->Size = System::Drawing::Size(67, 33);
			this->UndoButton->TabIndex = 1;
			this->UndoButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->UndoButton->Click += gcnew System::EventHandler(this, &UserProfile::UndoButton_Click);
			// 
			// RequestPanel
			// 
			this->RequestPanel->BackColor = System::Drawing::Color::Transparent;
			this->RequestPanel->Controls->Add(this->DeleteRequestButton);
			this->RequestPanel->Controls->Add(this->ConfirmButton);
			this->RequestPanel->Location = System::Drawing::Point(45, 11);
			this->RequestPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->RequestPanel->Name = L"RequestPanel";
			this->RequestPanel->Size = System::Drawing::Size(170, 44);
			this->RequestPanel->TabIndex = 10;
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
			this->DeleteRequestButton->Margin = System::Windows::Forms::Padding(4);
			this->DeleteRequestButton->Name = L"DeleteRequestButton";
			this->DeleteRequestButton->Size = System::Drawing::Size(67, 33);
			this->DeleteRequestButton->TabIndex = 1;
			this->DeleteRequestButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->DeleteRequestButton->Click += gcnew System::EventHandler(this, &UserProfile::DeleteRequestButton_Click);
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
			this->ConfirmButton->Margin = System::Windows::Forms::Padding(4);
			this->ConfirmButton->Name = L"ConfirmButton";
			this->ConfirmButton->Size = System::Drawing::Size(84, 33);
			this->ConfirmButton->TabIndex = 0;
			this->ConfirmButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->ConfirmButton->Click += gcnew System::EventHandler(this, &UserProfile::ConfirmButton_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->FriendsPanel);
			this->panel3->Controls->Add(this->AddFriendPanel);
			this->panel3->Controls->Add(this->MoreButton);
			this->panel3->Controls->Add(this->followPanel);
			this->panel3->Controls->Add(this->MessageButton);
			this->panel3->Controls->Add(this->RequestSentPanel);
			this->panel3->Controls->Add(this->RequestPanel);
			this->panel3->Location = System::Drawing::Point(339, 514);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(735, 105);
			this->panel3->TabIndex = 4;
			// 
			// MoreButton
			// 
			this->MoreButton->BackColor = System::Drawing::Color::Transparent;
			this->MoreButton->color = System::Drawing::Color::Transparent;
			this->MoreButton->colorActive = System::Drawing::Color::Transparent;
			this->MoreButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MoreButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MoreButton->ForeColor = System::Drawing::Color::DimGray;
			this->MoreButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MoreButton.Image")));
			this->MoreButton->ImagePosition = 15;
			this->MoreButton->ImageZoom = 45;
			this->MoreButton->LabelPosition = 31;
			this->MoreButton->LabelText = L"More";
			this->MoreButton->Location = System::Drawing::Point(481, 16);
			this->MoreButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MoreButton->Name = L"MoreButton";
			this->MoreButton->Size = System::Drawing::Size(70, 77);
			this->MoreButton->TabIndex = 16;
			this->MoreButton->Click += gcnew System::EventHandler(this, &UserProfile::MoreButton_Click);
			// 
			// followPanel
			// 
			this->followPanel->Controls->Add(this->bunifuFlatButton1);
			this->followPanel->Location = System::Drawing::Point(219, 13);
			this->followPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->followPanel->Name = L"followPanel";
			this->followPanel->Size = System::Drawing::Size(113, 56);
			this->followPanel->TabIndex = 0;
			this->followPanel->Visible = false;
			// 
			// bunifuFlatButton1
			// 
			this->bunifuFlatButton1->Activecolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton1->BorderRadius = 0;
			this->bunifuFlatButton1->ButtonText = L"Follow";
			this->bunifuFlatButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton1->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton1->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton1.Iconimage")));
			this->bunifuFlatButton1->Iconimage_right = nullptr;
			this->bunifuFlatButton1->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton1->Iconimage_Selected = nullptr;
			this->bunifuFlatButton1->IconMarginLeft = 0;
			this->bunifuFlatButton1->IconMarginRight = 0;
			this->bunifuFlatButton1->IconRightVisible = true;
			this->bunifuFlatButton1->IconRightZoom = 0;
			this->bunifuFlatButton1->IconVisible = true;
			this->bunifuFlatButton1->IconZoom = 40;
			this->bunifuFlatButton1->IsTab = false;
			this->bunifuFlatButton1->Location = System::Drawing::Point(-2, 2);
			this->bunifuFlatButton1->Name = L"bunifuFlatButton1";
			this->bunifuFlatButton1->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton1->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton1->OnHoverTextColor = System::Drawing::Color::Black;
			this->bunifuFlatButton1->selected = false;
			this->bunifuFlatButton1->Size = System::Drawing::Size(111, 40);
			this->bunifuFlatButton1->TabIndex = 6;
			this->bunifuFlatButton1->Text = L"Follow";
			this->bunifuFlatButton1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton1->Textcolor = System::Drawing::Color::DimGray;
			this->bunifuFlatButton1->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->Click += gcnew System::EventHandler(this, &UserProfile::bunifuFlatButton1_Click);
			// 
			// MessageButton
			// 
			this->MessageButton->BackColor = System::Drawing::Color::Transparent;
			this->MessageButton->color = System::Drawing::Color::Transparent;
			this->MessageButton->colorActive = System::Drawing::Color::Transparent;
			this->MessageButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MessageButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MessageButton->ForeColor = System::Drawing::Color::DimGray;
			this->MessageButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MessageButton.Image")));
			this->MessageButton->ImagePosition = 15;
			this->MessageButton->ImageZoom = 50;
			this->MessageButton->LabelPosition = 31;
			this->MessageButton->LabelText = L"Message";
			this->MessageButton->Location = System::Drawing::Point(359, 13);
			this->MessageButton->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MessageButton->Name = L"MessageButton";
			this->MessageButton->Size = System::Drawing::Size(70, 87);
			this->MessageButton->TabIndex = 15;
			this->MessageButton->Click += gcnew System::EventHandler(this, &UserProfile::MessageButton_Click);
			// 
			// followingPanel
			// 
			this->followingPanel->Controls->Add(this->bunifuTileButton3);
			this->followingPanel->Controls->Add(this->panel6);
			this->followingPanel->Location = System::Drawing::Point(366, 9);
			this->followingPanel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->followingPanel->Name = L"followingPanel";
			this->followingPanel->Size = System::Drawing::Size(194, 78);
			this->followingPanel->TabIndex = 16;
			this->followingPanel->Visible = false;
			// 
			// bunifuTileButton3
			// 
			this->bunifuTileButton3->BackColor = System::Drawing::Color::Transparent;
			this->bunifuTileButton3->color = System::Drawing::Color::Transparent;
			this->bunifuTileButton3->colorActive = System::Drawing::Color::Transparent;
			this->bunifuTileButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuTileButton3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuTileButton3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuTileButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuTileButton3.Image")));
			this->bunifuTileButton3->ImagePosition = 15;
			this->bunifuTileButton3->ImageZoom = 50;
			this->bunifuTileButton3->LabelPosition = 31;
			this->bunifuTileButton3->LabelText = L"Following";
			this->bunifuTileButton3->Location = System::Drawing::Point(4, 0);
			this->bunifuTileButton3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->bunifuTileButton3->Name = L"bunifuTileButton3";
			this->bunifuTileButton3->Size = System::Drawing::Size(79, 73);
			this->bunifuTileButton3->TabIndex = 17;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Controls->Add(this->unfollowButton);
			this->panel6->Location = System::Drawing::Point(90, 37);
			this->panel6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(95, 27);
			this->panel6->TabIndex = 5;
			this->panel6->Visible = false;
			// 
			// unfollowButton
			// 
			this->unfollowButton->ActiveBorderThickness = 1;
			this->unfollowButton->ActiveCornerRadius = 10;
			this->unfollowButton->ActiveFillColor = System::Drawing::Color::Transparent;
			this->unfollowButton->ActiveForecolor = System::Drawing::Color::Black;
			this->unfollowButton->ActiveLineColor = System::Drawing::Color::Transparent;
			this->unfollowButton->BackColor = System::Drawing::Color::White;
			this->unfollowButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"unfollowButton.BackgroundImage")));
			this->unfollowButton->ButtonText = L"Unfollow";
			this->unfollowButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->unfollowButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->unfollowButton->ForeColor = System::Drawing::Color::White;
			this->unfollowButton->IdleBorderThickness = 1;
			this->unfollowButton->IdleCornerRadius = 1;
			this->unfollowButton->IdleFillColor = System::Drawing::Color::White;
			this->unfollowButton->IdleForecolor = System::Drawing::Color::DimGray;
			this->unfollowButton->IdleLineColor = System::Drawing::Color::White;
			this->unfollowButton->Location = System::Drawing::Point(4, 2);
			this->unfollowButton->Margin = System::Windows::Forms::Padding(4);
			this->unfollowButton->Name = L"unfollowButton";
			this->unfollowButton->Size = System::Drawing::Size(77, 21);
			this->unfollowButton->TabIndex = 4;
			this->unfollowButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->unfollowButton->Click += gcnew System::EventHandler(this, &UserProfile::unfollowButton_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->followingPanel);
			this->panel4->Location = System::Drawing::Point(339, 412);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(735, 98);
			this->panel4->TabIndex = 17;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->bunifuFlatButton2);
			this->panel7->Controls->Add(this->bunifuFlatButton3);
			this->panel7->Location = System::Drawing::Point(703, 621);
			this->panel7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(187, 129);
			this->panel7->TabIndex = 19;
			this->panel7->Visible = false;
			// 
			// bunifuFlatButton2
			// 
			this->bunifuFlatButton2->Activecolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton2->BorderRadius = 0;
			this->bunifuFlatButton2->ButtonText = L"Mutual Friends";
			this->bunifuFlatButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton2->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton2->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton2.Iconimage")));
			this->bunifuFlatButton2->Iconimage_right = nullptr;
			this->bunifuFlatButton2->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton2->Iconimage_Selected = nullptr;
			this->bunifuFlatButton2->IconMarginLeft = 0;
			this->bunifuFlatButton2->IconMarginRight = 0;
			this->bunifuFlatButton2->IconRightVisible = true;
			this->bunifuFlatButton2->IconRightZoom = 0;
			this->bunifuFlatButton2->IconVisible = true;
			this->bunifuFlatButton2->IconZoom = 50;
			this->bunifuFlatButton2->IsTab = false;
			this->bunifuFlatButton2->Location = System::Drawing::Point(3, 3);
			this->bunifuFlatButton2->Name = L"bunifuFlatButton2";
			this->bunifuFlatButton2->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton2->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton2->OnHoverTextColor = System::Drawing::Color::Black;
			this->bunifuFlatButton2->selected = false;
			this->bunifuFlatButton2->Size = System::Drawing::Size(177, 40);
			this->bunifuFlatButton2->TabIndex = 6;
			this->bunifuFlatButton2->Text = L"Mutual Friends";
			this->bunifuFlatButton2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton2->Textcolor = System::Drawing::Color::DimGray;
			this->bunifuFlatButton2->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->Click += gcnew System::EventHandler(this, &UserProfile::bunifuFlatButton2_Click);
			// 
			// bunifuFlatButton3
			// 
			this->bunifuFlatButton3->Activecolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton3->BorderRadius = 0;
			this->bunifuFlatButton3->ButtonText = L"See Friendship";
			this->bunifuFlatButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton3->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton3->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton3->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton3.Iconimage")));
			this->bunifuFlatButton3->Iconimage_right = nullptr;
			this->bunifuFlatButton3->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton3->Iconimage_Selected = nullptr;
			this->bunifuFlatButton3->IconMarginLeft = 0;
			this->bunifuFlatButton3->IconMarginRight = 0;
			this->bunifuFlatButton3->IconRightVisible = true;
			this->bunifuFlatButton3->IconRightZoom = 0;
			this->bunifuFlatButton3->IconVisible = true;
			this->bunifuFlatButton3->IconZoom = 50;
			this->bunifuFlatButton3->IsTab = false;
			this->bunifuFlatButton3->Location = System::Drawing::Point(3, 50);
			this->bunifuFlatButton3->Name = L"bunifuFlatButton3";
			this->bunifuFlatButton3->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton3->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->bunifuFlatButton3->OnHoverTextColor = System::Drawing::Color::Black;
			this->bunifuFlatButton3->selected = false;
			this->bunifuFlatButton3->Size = System::Drawing::Size(177, 40);
			this->bunifuFlatButton3->TabIndex = 7;
			this->bunifuFlatButton3->Text = L"See Friendship";
			this->bunifuFlatButton3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton3->Textcolor = System::Drawing::Color::DimGray;
			this->bunifuFlatButton3->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton3->Click += gcnew System::EventHandler(this, &UserProfile::bunifuFlatButton3_Click);
			// 
			// panel5
			// 
			this->panel5->AutoScroll = true;
			this->panel5->BackColor = System::Drawing::Color::White;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Location = System::Drawing::Point(339, 620);
			this->panel5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(735, 167);
			this->panel5->TabIndex = 18;
			this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &UserProfile::panel5_Paint);
			// 
			// UserProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->ClientSize = System::Drawing::Size(1386, 788);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->Gender);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->Birthdate);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->profileName);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"UserProfile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"     ";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &UserProfile::UserProfile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->FriendsPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->AddFriendPanel->ResumeLayout(false);
			this->RequestSentPanel->ResumeLayout(false);
			this->RequestSentPanel->PerformLayout();
			this->RequestPanel->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->followPanel->ResumeLayout(false);
			this->followingPanel->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void UserProfile_Load(System::Object^  sender, System::EventArgs^  e) {
		
		newsFeed^ posts = gcnew newsFeed(e_mail,"Profile");
		panel5->Controls->Add(posts);

	}
	private: System::Void panel5_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
private: System::Void ConfirmButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::AllAccounts[FacebookSys::user_email]->addFriendOrfollowed(e_mail, "Friend");
	FacebookSys::insetFriendshiptDB(e_mail, "Friend");
	FacebookSys::DeleteRequest(e_mail);
	// function deletes from object
	FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_Request(e_mail);
	Draw(e_mail);
}
	
private: System::Void DeleteRequestButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::DeleteRequest(e_mail);
	// function deletes from object
	FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_Request(e_mail);
	Draw(e_mail);
}
private: System::Void UndoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::DeleteRequest(e_mail);
	FacebookSys::AllAccounts[e_mail]->Delete_Request(FacebookSys::user_email);
	Draw(e_mail);
}
private: System::Void AddFriendButton_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::request(e_mail);
	FacebookSys::AllAccounts[FacebookSys::user_email]->addRequest(e_mail);
	Draw(e_mail);
}
private: System::Void bunifuThinButton22_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::Delete_Friendship(e_mail);
	FacebookSys::AllAccounts[FacebookSys::user_email]->Delete_FriendShip(e_mail);
	Draw(e_mail);
}
private: System::Void FriendsButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel2->Visible == false)
		panel2->Visible = true;
	else
		panel2->Visible = false;
}
private: System::Void bunifuFlatButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::AllAccounts[FacebookSys::user_email]->addFriendOrfollowed(e_mail, "Follower");
	FacebookSys::insetFriendshiptDB(e_mail, "Follower");
	Draw(e_mail);
}
private: System::Void unfollowButton_Click(System::Object^  sender, System::EventArgs^  e) {
	//function unfollow
}
private: System::Void MoreButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel7->Visible == false)
		panel7->Visible = true;
	else
		panel7->Visible = false;
}
private: System::Void bunifuFlatButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	Users^ mutualFriends = gcnew Users(e_mail);
	mutualFriends->ShowDialog();
}
private: System::Void bunifuFlatButton3_Click(System::Object^  sender, System::EventArgs^  e) {
	SeeFriendship^ friendship = gcnew SeeFriendship(e_mail);
	friendship->Show();
}
private: System::Void MessageButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SendMessage^ send = gcnew SendMessage(e_mail);
	send->ShowDialog();
	
	
}
private: System::Void bunifuThinButton21_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
