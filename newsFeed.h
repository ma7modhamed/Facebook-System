#pragma once
#include"Post.h"
#include"UserPost.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;

namespace FacebookSystem {

	/// <summary>
	/// Summary for newsFeed
	/// </summary>
	public ref class newsFeed : public System::Windows::Forms::UserControl
	{
		Dictionary<int, UserPost^>^ Profile_Posts = gcnew Dictionary<int, UserPost^>();
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton1;
	private: Bunifu::Framework::UI::BunifuThinButton2^  PostButton;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label2;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton2;
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton3;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: Bunifu::Framework::UI::BunifuFlatButton^  TagButton;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;





			 Dictionary<int, String^>^ NewFeed_List = gcnew Dictionary<int, String^>();
			 List<String^>^ searchedFriendsToTag = gcnew List<String^>();
	public:
		newsFeed(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		

		}
		newsFeed(String^ User_Email,String^ state)
		{
			InitializeComponent();
			//Profile_Posts = FacebookSys::AllAccounts[User.Value]->GetMyPosts(); //note: returns myposts Dictionary that is declared in line 20 in FBAccount.h
			if (state == "Profile")
			{
				if (User_Email != FacebookSys::user_email)
				{
					panel2->Visible = false;
					panel5->Visible = false;
					flowLayoutPanel1->Top = panel2->Top;
					this->Height -= panel2->Height;
				}
				this->Height = 446;
				for each(KeyValuePair<int, UserPost^> MyPost in FacebookSys::AllAccounts[User_Email]->GetmyPosts())
				{
					if (FacebookSys::AllAccounts[FacebookSys::user_email]->checkIfFriend(User_Email))
						AddNewPost(MyPost.Key, MyPost.Value);
					else
					{
						if (MyPost.Value->getPrivacy()=="Public")
							AddNewPost(MyPost.Key, MyPost.Value);
					}
				}

			}
			else if(state=="NewsFeed")
			{
				//NewFeed_List = FacebookSys::AllAccounts[User_Email]->getMyNewsFeedList(); //note: returns newsFeed Dictionary that is declared in line 21 in FBAccount.h
				for each (KeyValuePair<int ,String^> post in FacebookSys::AllAccounts[User_Email]->GetnewsFeed())
				{
					AddNewPost(post.Key,FacebookSys::AllAccounts[post.Value]->getMypost(post.Key));
				}
			}
			else if (state == "Friendship")
			{
				panel2->Visible = false;
				panel2->Visible = false;
				panel5->Visible = false;
				flowLayoutPanel1->Top = panel2->Top;
				
				for each (KeyValuePair<int,String^> commonposts in FacebookSys::AllAccounts[FacebookSys::user_email] + FacebookSys::AllAccounts[User_Email])
				{
					AddNewPost(commonposts.Key, FacebookSys::AllAccounts[commonposts.Value]->getMypost(commonposts.Key));
				}
			}

		}
		bool noPost()
		{
			if (flowLayoutPanel1->Controls->Count == 0)
				return true;
			else
				return false;
		}
		void AddNewPost(int id, UserPost^ post)
		{
			Post^l = gcnew Post(id,post );
			
			flowLayoutPanel1->Controls->Add(l);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~newsFeed()
		{
			if (components)
			{
				delete components;
			}
			
		}
	private: System::Windows::Forms::Panel^  panel2;
	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(newsFeed::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->TagButton = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuFlatButton1 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->PostButton = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->bunifuFlatButton2 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->bunifuFlatButton3 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->TagButton);
			this->panel2->Controls->Add(this->bunifuImageButton1);
			this->panel2->Controls->Add(this->bunifuFlatButton1);
			this->panel2->Controls->Add(this->PostButton);
			this->panel2->Controls->Add(this->pictureBox5);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(36, 44);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(520, 178);
			this->panel2->TabIndex = 5;
			// 
			// TagButton
			// 
			this->TagButton->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->TagButton->BackColor = System::Drawing::Color::WhiteSmoke;
			this->TagButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->TagButton->BorderRadius = 0;
			this->TagButton->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TagButton->ButtonText = L"Tag Friends";
			this->TagButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TagButton->DisabledColor = System::Drawing::Color::Gray;
			this->TagButton->Iconcolor = System::Drawing::Color::Transparent;
			this->TagButton->Iconimage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TagButton.Iconimage")));
			this->TagButton->Iconimage_right = nullptr;
			this->TagButton->Iconimage_right_Selected = nullptr;
			this->TagButton->Iconimage_Selected = nullptr;
			this->TagButton->IconMarginLeft = 0;
			this->TagButton->IconMarginRight = 0;
			this->TagButton->IconRightVisible = true;
			this->TagButton->IconRightZoom = 0;
			this->TagButton->IconVisible = true;
			this->TagButton->IconZoom = 90;
			this->TagButton->IsTab = false;
			this->TagButton->Location = System::Drawing::Point(153, 135);
			this->TagButton->Name = L"TagButton";
			this->TagButton->Normalcolor = System::Drawing::Color::WhiteSmoke;
			this->TagButton->OnHovercolor = System::Drawing::Color::Gainsboro;
			this->TagButton->OnHoverTextColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->TagButton->selected = false;
			this->TagButton->Size = System::Drawing::Size(151, 35);
			this->TagButton->TabIndex = 23;
			this->TagButton->Text = L"Tag Friends";
			this->TagButton->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->TagButton->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->TagButton->TextFont = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TagButton->Click += gcnew System::EventHandler(this, &newsFeed::TagButton_Click);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(391, 142);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(18, 21);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 16;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &newsFeed::bunifuImageButton1_Click);
			// 
			// bunifuFlatButton1
			// 
			this->bunifuFlatButton1->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuFlatButton1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton1->BorderRadius = 0;
			this->bunifuFlatButton1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bunifuFlatButton1->ButtonText = L"Public";
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
			this->bunifuFlatButton1->IconZoom = 50;
			this->bunifuFlatButton1->IsTab = false;
			this->bunifuFlatButton1->Location = System::Drawing::Point(309, 135);
			this->bunifuFlatButton1->Name = L"bunifuFlatButton1";
			this->bunifuFlatButton1->Normalcolor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton1->OnHovercolor = System::Drawing::Color::Gainsboro;
			this->bunifuFlatButton1->OnHoverTextColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bunifuFlatButton1->selected = false;
			this->bunifuFlatButton1->Size = System::Drawing::Size(105, 35);
			this->bunifuFlatButton1->TabIndex = 15;
			this->bunifuFlatButton1->Text = L"Public";
			this->bunifuFlatButton1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bunifuFlatButton1->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bunifuFlatButton1->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->Click += gcnew System::EventHandler(this, &newsFeed::bunifuFlatButton1_Click);
			// 
			// PostButton
			// 
			this->PostButton->ActiveBorderThickness = 1;
			this->PostButton->ActiveCornerRadius = 10;
			this->PostButton->ActiveFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->PostButton->ActiveForecolor = System::Drawing::Color::White;
			this->PostButton->ActiveLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->PostButton->BackColor = System::Drawing::Color::White;
			this->PostButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PostButton.BackgroundImage")));
			this->PostButton->ButtonText = L"Post";
			this->PostButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PostButton->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PostButton->ForeColor = System::Drawing::Color::White;
			this->PostButton->IdleBorderThickness = 1;
			this->PostButton->IdleCornerRadius = 10;
			this->PostButton->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->PostButton->IdleForecolor = System::Drawing::Color::White;
			this->PostButton->IdleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->PostButton->Location = System::Drawing::Point(421, 135);
			this->PostButton->Margin = System::Windows::Forms::Padding(4);
			this->PostButton->Name = L"PostButton";
			this->PostButton->Size = System::Drawing::Size(81, 32);
			this->PostButton->TabIndex = 14;
			this->PostButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->PostButton->Click += gcnew System::EventHandler(this, &newsFeed::PostButton_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Location = System::Drawing::Point(16, 14);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(47, 41);
			this->pictureBox5->TabIndex = 11;
			this->pictureBox5->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(69, 14);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(434, 106);
			this->textBox1->TabIndex = 0;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(3, 79);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(298, 202);
			this->checkedListBox1->TabIndex = 23;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::BottomUp;
			this->flowLayoutPanel1->Location = System::Drawing::Point(30, 237);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(520, 106);
			this->flowLayoutPanel1->TabIndex = 6;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->bunifuFlatButton2);
			this->panel1->Controls->Add(this->bunifuFlatButton3);
			this->panel1->Location = System::Drawing::Point(219, 222);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(225, 157);
			this->panel1->TabIndex = 17;
			this->panel1->Visible = false;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &newsFeed::panel1_Paint);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(123, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Your Friends only";
			this->label3->Click += gcnew System::EventHandler(this, &newsFeed::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(171, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Any one";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Who Can See this \?";
			// 
			// bunifuFlatButton2
			// 
			this->bunifuFlatButton2->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->bunifuFlatButton2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton2->BorderRadius = 0;
			this->bunifuFlatButton2->ButtonText = L"Public";
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
			this->bunifuFlatButton2->IconZoom = 48;
			this->bunifuFlatButton2->IsTab = false;
			this->bunifuFlatButton2->Location = System::Drawing::Point(0, 24);
			this->bunifuFlatButton2->Name = L"bunifuFlatButton2";
			this->bunifuFlatButton2->Normalcolor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton2->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton2->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton2->selected = false;
			this->bunifuFlatButton2->Size = System::Drawing::Size(225, 53);
			this->bunifuFlatButton2->TabIndex = 17;
			this->bunifuFlatButton2->Text = L"Public";
			this->bunifuFlatButton2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton2->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bunifuFlatButton2->TextFont = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->Click += gcnew System::EventHandler(this, &newsFeed::bunifuFlatButton2_Click);
			// 
			// bunifuFlatButton3
			// 
			this->bunifuFlatButton3->Activecolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(139)), static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->bunifuFlatButton3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton3->BorderRadius = 0;
			this->bunifuFlatButton3->ButtonText = L"Friends";
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
			this->bunifuFlatButton3->Location = System::Drawing::Point(0, 88);
			this->bunifuFlatButton3->Name = L"bunifuFlatButton3";
			this->bunifuFlatButton3->Normalcolor = System::Drawing::Color::WhiteSmoke;
			this->bunifuFlatButton3->OnHovercolor = System::Drawing::Color::Silver;
			this->bunifuFlatButton3->OnHoverTextColor = System::Drawing::Color::White;
			this->bunifuFlatButton3->selected = false;
			this->bunifuFlatButton3->Size = System::Drawing::Size(225, 53);
			this->bunifuFlatButton3->TabIndex = 22;
			this->bunifuFlatButton3->Text = L"Friends";
			this->bunifuFlatButton3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuFlatButton3->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->bunifuFlatButton3->TextFont = (gcnew System::Drawing::Font(L"Times New Roman", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton3->Click += gcnew System::EventHandler(this, &newsFeed::bunifuFlatButton3_Click_1);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->checkedListBox1);
			this->panel3->Controls->Add(this->panel4);
			this->panel3->Location = System::Drawing::Point(183, 222);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(306, 312);
			this->panel3->TabIndex = 24;
			this->panel3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Search Your Friends to tag";
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Controls->Add(this->textBox2);
			this->panel4->Location = System::Drawing::Point(3, 14);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(213, 82);
			this->panel4->TabIndex = 25;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(218)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->textBox2->Location = System::Drawing::Point(19, 29);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(175, 18);
			this->textBox2->TabIndex = 0;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &newsFeed::textBox2_TextChanged);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->label5);
			this->panel5->Controls->Add(this->pictureBox1);
			this->panel5->Location = System::Drawing::Point(30, 7);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(520, 36);
			this->panel5->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label5->Location = System::Drawing::Point(51, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(95, 19);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Write Post";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(24, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(24, 27);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// newsFeed
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"newsFeed";
			this->Size = System::Drawing::Size(586, 712);
			this->Load += gcnew System::EventHandler(this, &newsFeed::newsFeed_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void newsFeed_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//UserPost^ MyPost = gcnew UserPost(String^ , String^ Poster_Mail, String^ text);
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel1->Visible == false)
	{
		panel1->Visible = true;
		panel1->BringToFront();
	}
	else
	{
		panel1->Visible = false;
		panel1->SendToBack();
	}
}
private: System::Void bunifuFlatButton3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void PostButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->Text != "")
	{
		int post_id = FacebookSys::addPost(bunifuFlatButton1->Text, textBox1->Text);
		UserPost^post = gcnew UserPost(bunifuFlatButton1->Text, FacebookSys::user_email, textBox1->Text);
		FacebookSys::AllAccounts[FacebookSys::user_email]->addPost(post_id, post);
		FacebookSys::AllAccounts[FacebookSys::user_email]->addtoNewsfeed(post_id, FacebookSys::user_email);
		
		
		for (int i = 0; i < checkedListBox1->CheckedItems->Count; i++)
		{	
			int index = checkedListBox1->Items->IndexOf(checkedListBox1->CheckedItems[i]->ToString());
			
			String^ taggedMail = searchedFriendsToTag[index];
			FacebookSys::AllAccounts[FacebookSys::user_email]->addTaggedUserToPost(post_id, taggedMail);
			FacebookSys::AddTaggedFriendtoPost(post_id, taggedMail);

		}
		checkedListBox1->Items->Clear();
		AddNewPost(post_id, post);
		textBox1->Text = "Write a Post...";
		
	}

	
}
private: System::Void bunifuFlatButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	

}
private: System::Void bunifuFlatButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	bunifuFlatButton1->Text = bunifuFlatButton2->Text;
	bunifuFlatButton1->Iconimage = bunifuFlatButton2->Iconimage;
	panel1->Visible = false;
}
private: System::Void bunifuFlatButton3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	bunifuFlatButton1->Text = bunifuFlatButton3->Text;
	bunifuFlatButton1->Iconimage = bunifuFlatButton3->Iconimage;
	panel1->Visible = false;
}
private: System::Void TagButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (panel3->Visible == false)
		panel3->Visible = true;
	else
		panel3->Visible = false;
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//searching my friends
	checkedListBox1->Items->Clear();
	searchedFriendsToTag->Clear();
	for each (String^ email in FacebookSys::SearchFriendsDB(textBox2->Text, FacebookSys::user_email))
	{
		searchedFriendsToTag->Add(email);
		checkedListBox1->Items->Add(FacebookSys::AllAccounts[email]->GetAccountUserName());
	}
	
}
};
}
