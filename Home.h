#pragma once
#include "Post.h"
#include"newsFeed.h"
#include"AccountsList.h"
#include "AccountSettings.h"
#include"AllConversations.h"
namespace FacebookSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	private:		
		Form^l;

	public:
		Home(Form^ c)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			l = c;
			bunifuFlatButton1->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountUserName();
			//
			panel4->Controls->Clear();
			AccountsList^ pymkn = gcnew AccountsList("");
			List<String^>^ Pmails = gcnew List<String^>();
			for each (String^ var in FacebookSys::AllAccounts[FacebookSys::user_email]->Getfriends())
			{
				for (int i = 0; i < FacebookSys::AllAccounts[var]->Getfriends()->Count; i++)
				{
					if (FacebookSys::AllAccounts[var]->Getfriends()[i] != FacebookSys::user_email &&
						!FacebookSys::AllAccounts[FacebookSys::user_email]->Getfriends()->Contains( FacebookSys::AllAccounts[var]->Getfriends()[i])&&
						!FacebookSys::AllAccounts[FacebookSys::user_email]->GetrequestedFriends()->Contains(FacebookSys::AllAccounts[var]->Getfriends()[i])&&
						!FacebookSys::AllAccounts[FacebookSys::user_email]->Getrequests()->Contains(FacebookSys::AllAccounts[var]->Getfriends()[i]))
					Pmails->Add(FacebookSys::AllAccounts[var]->Getfriends()[i]);
				

				}
					
			} 
			for (int i = 0; i < Pmails->Count; i++)
				pymkn->AddAccount(Pmails[i]);
			panel3->Controls->Add(pymkn);

			newsFeed^news = gcnew newsFeed(FacebookSys::user_email, "NewsFeed");
			panel4->Controls->Add(news);
			profileName->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountUserName();
			if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountGender() == "Female")
				pictureBox1->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
		}
	private: System::Windows::Forms::PictureBox^  messageD;
	public:

	private: System::Windows::Forms::PictureBox^  FriendsPic;
	public:


	public:








	private: System::Windows::Forms::Label^  label2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton6;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton5;
	private: Bunifu::Framework::UI::BunifuDragControl^  bunifuDragControl1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  friendD;

	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  profileName;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton7;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton2;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton1;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton3;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton4;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton5;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton6;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel3;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton7;
	private: System::Windows::Forms::Panel^  menuPanel;

	private: System::Windows::Forms::PictureBox^  MessagesPic;















	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}





	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton2;


	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bunifuImageButton6 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton5 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->messageD = (gcnew System::Windows::Forms::PictureBox());
			this->MessagesPic = (gcnew System::Windows::Forms::PictureBox());
			this->FriendsPic = (gcnew System::Windows::Forms::PictureBox());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton2 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuDragControl1 = (gcnew Bunifu::Framework::UI::BunifuDragControl(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuFlatButton2 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuFlatButton1 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuImageButton7 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->friendD = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->profileName = (gcnew System::Windows::Forms::Label());
			this->bunifuFlatButton3 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->bunifuFlatButton4 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuFlatButton5 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuFlatButton6 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->bunifuFlatButton7 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->menuPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->messageD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MessagesPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FriendsPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->friendD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->menuPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(28, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"facebook";
			this->label2->Click += gcnew System::EventHandler(this, &Home::label2_Click);
			// 
			// bunifuImageButton6
			// 
			this->bunifuImageButton6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bunifuImageButton6->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton6.Image")));
			this->bunifuImageButton6->ImageActive = nullptr;
			this->bunifuImageButton6->Location = System::Drawing::Point(1290, 0);
			this->bunifuImageButton6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton6->Name = L"bunifuImageButton6";
			this->bunifuImageButton6->Size = System::Drawing::Size(44, 64);
			this->bunifuImageButton6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton6->TabIndex = 1;
			this->bunifuImageButton6->TabStop = false;
			this->bunifuImageButton6->Zoom = 10;
			this->bunifuImageButton6->Click += gcnew System::EventHandler(this, &Home::bunifuImageButton6_Click);
			// 
			// bunifuImageButton5
			// 
			this->bunifuImageButton5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bunifuImageButton5->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton5.Image")));
			this->bunifuImageButton5->ImageActive = nullptr;
			this->bunifuImageButton5->Location = System::Drawing::Point(1340, 6);
			this->bunifuImageButton5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton5->Name = L"bunifuImageButton5";
			this->bunifuImageButton5->Size = System::Drawing::Size(43, 34);
			this->bunifuImageButton5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton5->TabIndex = 0;
			this->bunifuImageButton5->TabStop = false;
			this->bunifuImageButton5->Zoom = 10;
			this->bunifuImageButton5->Click += gcnew System::EventHandler(this, &Home::bunifuImageButton5_Click);
			// 
			// messageD
			// 
			this->messageD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"messageD.BackgroundImage")));
			this->messageD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->messageD->Location = System::Drawing::Point(1512, 4);
			this->messageD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->messageD->Name = L"messageD";
			this->messageD->Size = System::Drawing::Size(45, 48);
			this->messageD->TabIndex = 10;
			this->messageD->TabStop = false;
			this->messageD->Visible = false;
			// 
			// MessagesPic
			// 
			this->MessagesPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MessagesPic.BackgroundImage")));
			this->MessagesPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MessagesPic->Location = System::Drawing::Point(1139, 4);
			this->MessagesPic->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MessagesPic->Name = L"MessagesPic";
			this->MessagesPic->Size = System::Drawing::Size(30, 47);
			this->MessagesPic->TabIndex = 9;
			this->MessagesPic->TabStop = false;
			this->MessagesPic->Visible = false;
			// 
			// FriendsPic
			// 
			this->FriendsPic->BackColor = System::Drawing::Color::Transparent;
			this->FriendsPic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FriendsPic.BackgroundImage")));
			this->FriendsPic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->FriendsPic->Location = System::Drawing::Point(1175, 1);
			this->FriendsPic->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FriendsPic->Name = L"FriendsPic";
			this->FriendsPic->Size = System::Drawing::Size(41, 50);
			this->FriendsPic->TabIndex = 8;
			this->FriendsPic->TabStop = false;
			this->FriendsPic->Visible = false;
			this->FriendsPic->Click += gcnew System::EventHandler(this, &Home::FriendsPic_Click);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.ImageActive")));
			this->bunifuImageButton1->Location = System::Drawing::Point(1036, 0);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(41, 50);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 7;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &Home::bunifuImageButton1_Click);
			// 
			// bunifuImageButton2
			// 
			this->bunifuImageButton2->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.Image")));
			this->bunifuImageButton2->ImageActive = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.ImageActive")));
			this->bunifuImageButton2->Location = System::Drawing::Point(1000, 2);
			this->bunifuImageButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton2->Name = L"bunifuImageButton2";
			this->bunifuImageButton2->Size = System::Drawing::Size(30, 47);
			this->bunifuImageButton2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton2->TabIndex = 2;
			this->bunifuImageButton2->TabStop = false;
			this->bunifuImageButton2->Zoom = 10;
			this->bunifuImageButton2->Click += gcnew System::EventHandler(this, &Home::bunifuImageButton2_Click);
			// 
			// bunifuDragControl1
			// 
			this->bunifuDragControl1->Fixed = true;
			this->bunifuDragControl1->Horizontal = true;
			this->bunifuDragControl1->TargetControl = this->panel1;
			this->bunifuDragControl1->Vertical = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->panel1->Controls->Add(this->bunifuFlatButton2);
			this->panel1->Controls->Add(this->bunifuFlatButton1);
			this->panel1->Controls->Add(this->bunifuImageButton7);
			this->panel1->Controls->Add(this->friendD);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->FriendsPic);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->messageD);
			this->panel1->Controls->Add(this->bunifuImageButton6);
			this->panel1->Controls->Add(this->bunifuImageButton5);
			this->panel1->Controls->Add(this->bunifuImageButton2);
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Controls->Add(this->MessagesPic);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1386, 52);
			this->panel1->TabIndex = 0;
			// 
			// bunifuFlatButton2
			// 
			this->bunifuFlatButton2->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton2->BorderRadius = 5;
			this->bunifuFlatButton2->ButtonText = L"Home";
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
			this->bunifuFlatButton2->IconZoom = 80;
			this->bunifuFlatButton2->IsTab = false;
			this->bunifuFlatButton2->Location = System::Drawing::Point(856, 0);
			this->bunifuFlatButton2->Name = L"bunifuFlatButton2";
			this->bunifuFlatButton2->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton2->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton2->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton2->selected = false;
			this->bunifuFlatButton2->Size = System::Drawing::Size(129, 51);
			this->bunifuFlatButton2->TabIndex = 18;
			this->bunifuFlatButton2->Text = L"Home";
			this->bunifuFlatButton2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bunifuFlatButton2->Textcolor = System::Drawing::Color::White;
			this->bunifuFlatButton2->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton2_Click);
			// 
			// bunifuFlatButton1
			// 
			this->bunifuFlatButton1->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton1->BorderRadius = 5;
			this->bunifuFlatButton1->ButtonText = L"bunifuFlatButton1";
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
			this->bunifuFlatButton1->IconZoom = 80;
			this->bunifuFlatButton1->IsTab = false;
			this->bunifuFlatButton1->Location = System::Drawing::Point(672, 1);
			this->bunifuFlatButton1->Name = L"bunifuFlatButton1";
			this->bunifuFlatButton1->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton1->OnHovercolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->bunifuFlatButton1->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton1->selected = false;
			this->bunifuFlatButton1->Size = System::Drawing::Size(178, 51);
			this->bunifuFlatButton1->TabIndex = 17;
			this->bunifuFlatButton1->Text = L"bunifuFlatButton1";
			this->bunifuFlatButton1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bunifuFlatButton1->Textcolor = System::Drawing::Color::White;
			this->bunifuFlatButton1->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton1_Click);
			// 
			// bunifuImageButton7
			// 
			this->bunifuImageButton7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuImageButton7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton7.BackgroundImage")));
			this->bunifuImageButton7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton7.Image")));
			this->bunifuImageButton7->ImageActive = nullptr;
			this->bunifuImageButton7->Location = System::Drawing::Point(619, 17);
			this->bunifuImageButton7->Name = L"bunifuImageButton7";
			this->bunifuImageButton7->Size = System::Drawing::Size(33, 23);
			this->bunifuImageButton7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton7->TabIndex = 17;
			this->bunifuImageButton7->TabStop = false;
			this->bunifuImageButton7->Zoom = 10;
			// 
			// friendD
			// 
			this->friendD->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"friendD.BackgroundImage")));
			this->friendD->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->friendD->Location = System::Drawing::Point(1694, 3);
			this->friendD->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->friendD->Name = L"friendD";
			this->friendD->Size = System::Drawing::Size(45, 48);
			this->friendD->TabIndex = 11;
			this->friendD->TabStop = false;
			this->friendD->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(273, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(35, 34);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(308, -36);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(358, 134);
			this->panel2->TabIndex = 14;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Home::panel2_Paint_1);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(28, 56);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 17);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Home::textBox1_KeyDown);
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Home::textBox1_KeyUp);
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->AutoScroll = true;
			this->panel4->Location = System::Drawing::Point(384, 66);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(646, 720);
			this->panel4->TabIndex = 14;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Home::panel4_Paint);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(32, 8);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(95, 90);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Home::pictureBox2_Click);
			// 
			// profileName
			// 
			this->profileName->AutoSize = true;
			this->profileName->Cursor = System::Windows::Forms::Cursors::Hand;
			this->profileName->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->profileName->ForeColor = System::Drawing::Color::DarkBlue;
			this->profileName->Location = System::Drawing::Point(133, 38);
			this->profileName->Name = L"profileName";
			this->profileName->Size = System::Drawing::Size(133, 23);
			this->profileName->TabIndex = 16;
			this->profileName->Text = L"Profile Name";
			this->profileName->Click += gcnew System::EventHandler(this, &Home::profileName_Click);
			// 
			// bunifuFlatButton3
			// 
			this->bunifuFlatButton3->Activecolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton3->BorderRadius = 7;
			this->bunifuFlatButton3->ButtonText = L"News Feed";
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
			this->bunifuFlatButton3->IconZoom = 75;
			this->bunifuFlatButton3->IsTab = false;
			this->bunifuFlatButton3->Location = System::Drawing::Point(33, 124);
			this->bunifuFlatButton3->Name = L"bunifuFlatButton3";
			this->bunifuFlatButton3->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton3->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton3->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton3->selected = false;
			this->bunifuFlatButton3->Size = System::Drawing::Size(234, 48);
			this->bunifuFlatButton3->TabIndex = 19;
			this->bunifuFlatButton3->Text = L"News Feed";
			this->bunifuFlatButton3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton3->Textcolor = System::Drawing::Color::Black;
			this->bunifuFlatButton3->TextFont = (gcnew System::Drawing::Font(L"Maiandra GD", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton3->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton3_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(22, 115);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(254, 65);
			this->pictureBox3->TabIndex = 20;
			this->pictureBox3->TabStop = false;
			// 
			// bunifuFlatButton4
			// 
			this->bunifuFlatButton4->Activecolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton4->BorderRadius = 7;
			this->bunifuFlatButton4->ButtonText = L"Messenger";
			this->bunifuFlatButton4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton4->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton4->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton4->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton4.Iconimage")));
			this->bunifuFlatButton4->Iconimage_right = nullptr;
			this->bunifuFlatButton4->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton4->Iconimage_Selected = nullptr;
			this->bunifuFlatButton4->IconMarginLeft = 0;
			this->bunifuFlatButton4->IconMarginRight = 0;
			this->bunifuFlatButton4->IconRightVisible = true;
			this->bunifuFlatButton4->IconRightZoom = 0;
			this->bunifuFlatButton4->IconVisible = true;
			this->bunifuFlatButton4->IconZoom = 75;
			this->bunifuFlatButton4->IsTab = false;
			this->bunifuFlatButton4->Location = System::Drawing::Point(33, 207);
			this->bunifuFlatButton4->Name = L"bunifuFlatButton4";
			this->bunifuFlatButton4->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton4->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton4->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton4->selected = false;
			this->bunifuFlatButton4->Size = System::Drawing::Size(234, 48);
			this->bunifuFlatButton4->TabIndex = 21;
			this->bunifuFlatButton4->Text = L"Messenger";
			this->bunifuFlatButton4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton4->Textcolor = System::Drawing::Color::Black;
			this->bunifuFlatButton4->TextFont = (gcnew System::Drawing::Font(L"Maiandra GD", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton4->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton4_Click);
			// 
			// bunifuFlatButton5
			// 
			this->bunifuFlatButton5->Activecolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton5->BorderRadius = 7;
			this->bunifuFlatButton5->ButtonText = L"Friends";
			this->bunifuFlatButton5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton5->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton5->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton5->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton5.Iconimage")));
			this->bunifuFlatButton5->Iconimage_right = nullptr;
			this->bunifuFlatButton5->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton5->Iconimage_Selected = nullptr;
			this->bunifuFlatButton5->IconMarginLeft = 0;
			this->bunifuFlatButton5->IconMarginRight = 0;
			this->bunifuFlatButton5->IconRightVisible = true;
			this->bunifuFlatButton5->IconRightZoom = 0;
			this->bunifuFlatButton5->IconVisible = true;
			this->bunifuFlatButton5->IconZoom = 75;
			this->bunifuFlatButton5->IsTab = false;
			this->bunifuFlatButton5->Location = System::Drawing::Point(32, 289);
			this->bunifuFlatButton5->Name = L"bunifuFlatButton5";
			this->bunifuFlatButton5->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton5->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton5->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton5->selected = false;
			this->bunifuFlatButton5->Size = System::Drawing::Size(234, 48);
			this->bunifuFlatButton5->TabIndex = 22;
			this->bunifuFlatButton5->Text = L"Friends";
			this->bunifuFlatButton5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton5->Textcolor = System::Drawing::Color::Black;
			this->bunifuFlatButton5->TextFont = (gcnew System::Drawing::Font(L"Maiandra GD", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton5->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton5_Click);
			// 
			// bunifuFlatButton6
			// 
			this->bunifuFlatButton6->Activecolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton6->BorderRadius = 7;
			this->bunifuFlatButton6->ButtonText = L"Settings";
			this->bunifuFlatButton6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton6->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton6->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton6->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton6.Iconimage")));
			this->bunifuFlatButton6->Iconimage_right = nullptr;
			this->bunifuFlatButton6->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton6->Iconimage_Selected = nullptr;
			this->bunifuFlatButton6->IconMarginLeft = 0;
			this->bunifuFlatButton6->IconMarginRight = 0;
			this->bunifuFlatButton6->IconRightVisible = true;
			this->bunifuFlatButton6->IconRightZoom = 0;
			this->bunifuFlatButton6->IconVisible = true;
			this->bunifuFlatButton6->IconZoom = 70;
			this->bunifuFlatButton6->IsTab = false;
			this->bunifuFlatButton6->Location = System::Drawing::Point(33, 374);
			this->bunifuFlatButton6->Name = L"bunifuFlatButton6";
			this->bunifuFlatButton6->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton6->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton6->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton6->selected = false;
			this->bunifuFlatButton6->Size = System::Drawing::Size(234, 48);
			this->bunifuFlatButton6->TabIndex = 23;
			this->bunifuFlatButton6->Text = L"Settings";
			this->bunifuFlatButton6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton6->Textcolor = System::Drawing::Color::Black;
			this->bunifuFlatButton6->TextFont = (gcnew System::Drawing::Font(L"Maiandra GD", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton6->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton6_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rockwell", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->label1->Location = System::Drawing::Point(1049, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 23);
			this->label1->TabIndex = 24;
			this->label1->Text = L"People You May Know";
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->panel3->Location = System::Drawing::Point(1040, 83);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(410, 517);
			this->panel3->TabIndex = 25;
			// 
			// bunifuFlatButton7
			// 
			this->bunifuFlatButton7->Activecolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton7->BorderRadius = 7;
			this->bunifuFlatButton7->ButtonText = L"Log out";
			this->bunifuFlatButton7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton7->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton7->Iconcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton7->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuFlatButton7.Iconimage")));
			this->bunifuFlatButton7->Iconimage_right = nullptr;
			this->bunifuFlatButton7->Iconimage_right_Selected = nullptr;
			this->bunifuFlatButton7->Iconimage_Selected = nullptr;
			this->bunifuFlatButton7->IconMarginLeft = 0;
			this->bunifuFlatButton7->IconMarginRight = 0;
			this->bunifuFlatButton7->IconRightVisible = true;
			this->bunifuFlatButton7->IconRightZoom = 0;
			this->bunifuFlatButton7->IconVisible = true;
			this->bunifuFlatButton7->IconZoom = 70;
			this->bunifuFlatButton7->IsTab = false;
			this->bunifuFlatButton7->Location = System::Drawing::Point(33, 453);
			this->bunifuFlatButton7->Name = L"bunifuFlatButton7";
			this->bunifuFlatButton7->Normalcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->bunifuFlatButton7->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton7->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton7->selected = false;
			this->bunifuFlatButton7->Size = System::Drawing::Size(234, 48);
			this->bunifuFlatButton7->TabIndex = 26;
			this->bunifuFlatButton7->Text = L"Log out";
			this->bunifuFlatButton7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton7->Textcolor = System::Drawing::Color::Black;
			this->bunifuFlatButton7->TextFont = (gcnew System::Drawing::Font(L"Maiandra GD", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton7->Click += gcnew System::EventHandler(this, &Home::bunifuFlatButton7_Click);
			// 
			// menuPanel
			// 
			this->menuPanel->Controls->Add(this->pictureBox2);
			this->menuPanel->Controls->Add(this->bunifuFlatButton7);
			this->menuPanel->Controls->Add(this->profileName);
			this->menuPanel->Controls->Add(this->bunifuFlatButton3);
			this->menuPanel->Controls->Add(this->bunifuFlatButton6);
			this->menuPanel->Controls->Add(this->bunifuFlatButton4);
			this->menuPanel->Controls->Add(this->bunifuFlatButton5);
			this->menuPanel->Controls->Add(this->pictureBox3);
			this->menuPanel->Location = System::Drawing::Point(53, 66);
			this->menuPanel->Name = L"menuPanel";
			this->menuPanel->Size = System::Drawing::Size(310, 515);
			this->menuPanel->TabIndex = 0;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1386, 788);
			this->Controls->Add(this->menuPanel);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Home";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Facebook";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->messageD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MessagesPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FriendsPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->friendD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->menuPanel->ResumeLayout(false);
			this->menuPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
		
		
		
	}
			 
	private: System::Void bunifuImageButton4_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
	}
private: System::Void bunifuImageButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	panel4->Controls->Clear();
	bunifuImageButton2->Image = MessagesPic->BackgroundImage;
	
	AllConversations^ conver = gcnew	AllConversations(FacebookSys::user_email);
	panel4->Controls->Add(conver);
}
private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	


	

	panel4->Controls->Clear();
	AccountsList^ requests = gcnew AccountsList("Requests");
	for each (String^ mail in FacebookSys::AllAccounts[FacebookSys::user_email]->Getrequests())
	{
		requests->AddAccount(mail);
	}
	panel4->Controls->Add(requests);
	
	
	
}
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void bunifuImageButton5_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bunifuTextbox1_OnTextChange(System::Object^  sender, System::EventArgs^  e) {
	AccountsList^a = gcnew AccountsList("Search Result");
	a->AddAccount("Friends");
	panel4->Controls->Clear();
	panel4->Controls->Add(a);
}
private: System::Void panel4_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

}
private: System::Void bunifuImageButton3_Click(System::Object^  sender, System::EventArgs^  e) {


	
}

		 public:bool shiftispressed = false;

private: System::Void bunifuMetroTextbox1_OnValueChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel2_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = true;
	if (e->KeyCode == Keys::Enter && shiftispressed == false)
	{
		//seacrch code
		AccountsList^ searchList = gcnew AccountsList("Search Result");

		for each (String^ user in FacebookSys::SearchAccountsinDB(textBox1->Text))
		{
			
			searchList->AddAccount(user);
		}
		panel4->Controls->Clear();
		panel4->Controls->Add(searchList);
	}
}
private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = false;
}
private: System::Void bunifuImageButton6_Click(System::Object^  sender, System::EventArgs^  e) {
	WindowState = FormWindowState::Minimized;
}
private: System::Void bunifuFlatButton3_Click(System::Object^  sender, System::EventArgs^  e) {
	pictureBox3->Location = System::Drawing::Point::Point(bunifuFlatButton3->Location.X-11, bunifuFlatButton3->Location.Y - 9);

	panel4->Controls->Clear();
	
	newsFeed^news = gcnew newsFeed(FacebookSys::user_email, "NewsFeed");

	panel4->Controls->Add(news);
	
}
private: System::Void bunifuFlatButton4_Click(System::Object^  sender, System::EventArgs^  e) {
	
	pictureBox3->Location = System::Drawing::Point::Point(bunifuFlatButton3->Location.X - 11, bunifuFlatButton4->Location.Y - 9);
	panel4->Controls->Clear();

	AllConversations^ conver = gcnew	AllConversations(FacebookSys::user_email);
	panel4->Controls->Add(conver);
}
private: System::Void bunifuFlatButton5_Click(System::Object^  sender, System::EventArgs^  e) {
	panel4->Controls->Clear();
	pictureBox3->Location = System::Drawing::Point::Point(bunifuFlatButton3->Location.X - 11, bunifuFlatButton5->Location.Y - 9);

	AccountsList^friends = gcnew AccountsList(panel4->Width, "Friends");
	for each(String^ my_friend in FacebookSys::AllAccounts[FacebookSys::user_email]->Getfriends())
		friends->AddAccount(my_friend);
	panel4->Controls->Add(friends);
}
private: System::Void bunifuFlatButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	panel4->Controls->Clear();

	newsFeed^news = gcnew newsFeed(FacebookSys::user_email, "NewsFeed");

	panel4->Controls->Add(news);
}
private: System::Void FriendsPic_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void profileName_Click(System::Object^  sender, System::EventArgs^  e) {
	UserProfile^ myprofile = gcnew UserProfile(FacebookSys::user_email);
	myprofile->Show();
}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
	UserProfile^ myprofile = gcnew UserProfile(FacebookSys::user_email);
	myprofile->Show();
}
private: System::Void bunifuFlatButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	UserProfile^ myprofile = gcnew UserProfile(FacebookSys::user_email);
	myprofile->Show();
}
private: System::Void bunifuFlatButton6_Click(System::Object^  sender, System::EventArgs^  e) {
	panel4->Controls->Clear();
	pictureBox3->Location = System::Drawing::Point::Point(bunifuFlatButton3->Location.X - 11, bunifuFlatButton6->Location.Y - 9);
	AccountSettings^settings = gcnew AccountSettings();
	panel4->Controls->Add(settings);
}
private: System::Void bunifuFlatButton7_Click(System::Object^  sender, System::EventArgs^  e) {
	FacebookSys::logout();
	
	l->Show();
	this->Hide();
}
};
}
