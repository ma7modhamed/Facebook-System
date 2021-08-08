#pragma once
#include"ReplyControl.h"
#include"Reply.h"
#include"Comment.h"
#include"Users.h"
#include"FacebookSys.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for commentControl
	/// </summary>
	public ref class commentControl : public System::Windows::Forms::UserControl
	{
	public:
		int totalReactors = 0, like_count = 0, love_count = 0, haha_count = 0, angry_count = 0, sad_count = 0, wow_count = 0;
		 bool ReactedByMe = false;
		 String^ reactTypebyme = "", ^poster_mail = "";
		 int post_id = 0, comm_id = 0, repliesCount = 0;
		 List<String^>^ ReactionPriority = gcnew List<String^>();
		 
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	public:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  reactions_label;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: WindowsFormsControlLibrary1::BunifuCustomTextbox^  bunifuCustomTextbox1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel3;
			 //Dictionary<int, Reply^>^ Comment_replies = gcnew Dictionary<int, Reply^>();
	public:
		commentControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		commentControl(String^ PosterMail, int Post_id, int comment_id, Comment^ comment)
		{
			InitializeComponent();
			UserName->Text = FacebookSys::AllAccounts[comment->GetCommenterE_mail()]->GetAccountUserName();  //userName Of the commenter
			Comment_Text->Text = comment->GetCommentText();
			post_id = Post_id;
			poster_mail = PosterMail;
			comm_id = comment_id;
			Graphics^g = CreateGraphics();
			SizeF^ ss = g->MeasureString(Comment_Text->Text, Comment_Text->Font, 286);
			Comment_Text->Height = Math::Round(ss->Height + 10, 0);
			panel1->Top = Comment_Text->Bottom-55;
			panel3->Top = Comment_Text->Bottom;
			panel4->Top = panel1->Bottom;
			linkLabel1->Top = panel4->Bottom;
			flowLayoutPanel1->Top = linkLabel1->Bottom;
			
			ReactionPriority->Add("like");
		
			ReactionPriority->Add("love");
	
			ReactionPriority->Add("haha");
	
			ReactionPriority->Add("wow");
	
			ReactionPriority->Add("sad");
	
			ReactionPriority->Add("angry");
		
			if(FacebookSys::AllAccounts[ comment->GetCommenterE_mail()]->GetAccountGender()=="Female")
				pictureBox1->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
			if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountGender() == "Female")
				pictureBox5->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
			DrawComment(comment);
		}
		void DrawComment(Comment^ comment)
		{
			like_count = comment->GetCommentReactors()->GetReactorsCount()["like"];
			love_count = comment->GetCommentReactors()->GetReactorsCount()["love"];
			haha_count = comment->GetCommentReactors()->GetReactorsCount()["haha"];
			angry_count = comment->GetCommentReactors()->GetReactorsCount()["angry"];
			wow_count = comment->GetCommentReactors()->GetReactorsCount()["wow"];
			sad_count = comment->GetCommentReactors()->GetReactorsCount()["sad"];
			totalReactors = like_count + haha_count + love_count + wow_count + sad_count + angry_count;
			repliesCount = comment->GetCommentReplies()->Count;

			if (comment->GetCommentReactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
			{
				ReactedByMe = true;
				reactTypebyme = comment->GetCommentReactors()->GettotalReactors()[FacebookSys::user_email];
			}
			else
				ReactedByMe = false;
			List<String^>^ reaction = gcnew List<String^>();
			if (totalReactors == 0 && repliesCount == 0)
			{
				panel3->Visible = false;
				linkLabel1->Visible = false;
			}
			if (totalReactors == 0 && repliesCount != 0)
			{
				panel3->Visible = false;

			}
			if (totalReactors != 0)
			{
				panel3->Visible = true;
				reactions_label->Text= totalReactors.ToString();
				if (ReactedByMe)
				{
					if (reactTypebyme == "like")
					{
						bunifuThinButton21->ButtonText = "Like";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(64, 128, 255);
					}
					if (reactTypebyme == "love")
					{
						bunifuThinButton21->ButtonText = "Love";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(243, 82, 105);
					}
					if (reactTypebyme == "sad")
					{
						bunifuThinButton21->ButtonText = "Sad";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(240, 186, 21);
						

					}
					if (reactTypebyme == "angry")
					{
						bunifuThinButton21->ButtonText = "Angry";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(247, 113, 75);
					}
					if (reactTypebyme == "haha")
					{
						bunifuThinButton21->ButtonText = "Haha";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(240, 186, 21);
					}
					if (reactTypebyme == "wow")
					{
						bunifuThinButton21->ButtonText = "Wow";
						bunifuThinButton21->IdleForecolor = Color::FromArgb(240, 186, 21);
					}

				}
				int index;
				for each  (KeyValuePair<String^, int> r in comment->GetCommentReactors()->GetReactorsCount())
				{

					index = 0;
					if (r.Value == 0)
					{
						continue;
					}
					if (reaction->Count == 0)
					{
						reaction->Insert(index, r.Key);
					}
					for (int i = 0; i < reaction->Count; i++)
					{
						if (r.Key == reaction[i])
						{
							continue;
						}
						if (r.Value > comment->GetCommentReactors()->GetReactorsCount()[reaction[i]])
						{
							reaction->Insert(index, r.Key);
							break;
						}
						else if (r.Value == comment->GetCommentReactors()->GetReactorsCount()[reaction[i]])
						{
							if (ReactionPriority->IndexOf(r.Key) < ReactionPriority->IndexOf(reaction[i]))
							{
								reaction->Insert(index, r.Key);
								break;
							}
						}
						else
						{
							index++;
						}
					}

				}
				if (repliesCount == 0)
				{
					linkLabel1->Visible = false;
				}
				if (reaction->Count < 3)
				{
					index = reaction->Count;
					if (reaction->Count == 1)
					{
						pictureBox3->Visible = false;
						pictureBox4->Visible = false;
					}
					else
					{
						pictureBox4->Visible = false;
					}
				}
				else
				{
					index = 3;
				}
				for (int i = 0; i < index; i++)
				{
					if (i == 0)
						pictureBox2->BackgroundImage = Image::FromFile(FacebookSys::reactionsImagesPath[reaction[i]]);
					else if (i == 1)
						pictureBox3->BackgroundImage = Image::FromFile(FacebookSys::reactionsImagesPath[reaction[i]]);
					else if (i == 2)
						pictureBox4->BackgroundImage = Image::FromFile(FacebookSys::reactionsImagesPath[reaction[i]]);
				}
			}

		}
		void ReactToComment(String^ New_Reaction_Type)
		{
			if (FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
			{
				FacebookSys::UpdateReactComment(comm_id, New_Reaction_Type);
				String^ Old_reaction_Type = FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReactors()->GettotalReactors()[FacebookSys::user_email];
				FacebookSys::AllAccounts[poster_mail]->UpdateReactComment(post_id,comm_id, FacebookSys::user_email, Old_reaction_Type, New_Reaction_Type);
			}
			else
			{
				FacebookSys::like_comment(comm_id, New_Reaction_Type);
				FacebookSys::AllAccounts[poster_mail]->addReactToComment(post_id,comm_id, FacebookSys::user_email, New_Reaction_Type);
			}
		}
		void AddReply(int p_id,String^ p_mail,int C_id,int r_id,Reply^ r)
		{
			ReplyControl^ reply = gcnew ReplyControl(p_id, p_mail, C_id, r_id, r);
			flowLayoutPanel1->Controls->Add(reply);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~commentControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  Comment_Text;

	private: System::Windows::Forms::Label^  UserName;

	private: Bunifu::Framework::UI::BunifuThinButton2^  bunifuThinButton21;
	private: Bunifu::Framework::UI::BunifuThinButton2^  bunifuThinButton22;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton6;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton4;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton5;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton3;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  LikeLabel;
	private: System::Windows::Forms::Label^  AngryLabel;
	private: System::Windows::Forms::Label^  WowLabel;
	private: System::Windows::Forms::Label^  LoveLabel;
	private: System::Windows::Forms::Label^  HahaLabel;
	private: System::Windows::Forms::Label^  SadLabel;
	private: System::Windows::Forms::Timer^  timer1;




	private: System::Windows::Forms::LinkLabel^  linkLabel1;







	private: System::ComponentModel::IContainer^  components;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(commentControl::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Comment_Text = (gcnew System::Windows::Forms::Label());
			this->UserName = (gcnew System::Windows::Forms::Label());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->bunifuThinButton22 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LikeLabel = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton6 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton2 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton4 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton5 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton3 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->AngryLabel = (gcnew System::Windows::Forms::Label());
			this->WowLabel = (gcnew System::Windows::Forms::Label());
			this->LoveLabel = (gcnew System::Windows::Forms::Label());
			this->HahaLabel = (gcnew System::Windows::Forms::Label());
			this->SadLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->reactions_label = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->bunifuCustomTextbox1 = (gcnew WindowsFormsControlLibrary1::BunifuCustomTextbox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(8, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(59, 60);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// Comment_Text
			// 
			this->Comment_Text->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Comment_Text->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Comment_Text->Location = System::Drawing::Point(76, 42);
			this->Comment_Text->Name = L"Comment_Text";
			this->Comment_Text->Size = System::Drawing::Size(368, 32);
			this->Comment_Text->TabIndex = 20;
			this->Comment_Text->Text = L"Comment";
			this->Comment_Text->Click += gcnew System::EventHandler(this, &commentControl::Posttxt_Click);
			// 
			// UserName
			// 
			this->UserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->UserName->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserName->ForeColor = System::Drawing::Color::DarkBlue;
			this->UserName->Location = System::Drawing::Point(76, 5);
			this->UserName->Name = L"UserName";
			this->UserName->Size = System::Drawing::Size(146, 21);
			this->UserName->TabIndex = 21;
			this->UserName->Text = L"Comment";
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 20;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->BackColor = System::Drawing::Color::White;
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"Like";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 20;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::DimGray;
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton21->Location = System::Drawing::Point(10, 80);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(74, 27);
			this->bunifuThinButton21->TabIndex = 22;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &commentControl::bunifuThinButton21_Click);
			this->bunifuThinButton21->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuThinButton21_MouseHover);
			this->bunifuThinButton21->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuThinButton21_MouseLeave);
			// 
			// bunifuThinButton22
			// 
			this->bunifuThinButton22->ActiveBorderThickness = 1;
			this->bunifuThinButton22->ActiveCornerRadius = 20;
			this->bunifuThinButton22->ActiveFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->ActiveForecolor = System::Drawing::Color::Black;
			this->bunifuThinButton22->ActiveLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->BackColor = System::Drawing::Color::White;
			this->bunifuThinButton22->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton22.BackgroundImage")));
			this->bunifuThinButton22->ButtonText = L"Reply";
			this->bunifuThinButton22->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton22->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton22->ForeColor = System::Drawing::Color::SeaGreen;
			this->bunifuThinButton22->IdleBorderThickness = 1;
			this->bunifuThinButton22->IdleCornerRadius = 20;
			this->bunifuThinButton22->IdleFillColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->IdleForecolor = System::Drawing::Color::DimGray;
			this->bunifuThinButton22->IdleLineColor = System::Drawing::Color::Transparent;
			this->bunifuThinButton22->Location = System::Drawing::Point(82, 80);
			this->bunifuThinButton22->Margin = System::Windows::Forms::Padding(5);
			this->bunifuThinButton22->Name = L"bunifuThinButton22";
			this->bunifuThinButton22->Size = System::Drawing::Size(69, 27);
			this->bunifuThinButton22->TabIndex = 23;
			this->bunifuThinButton22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton22->Click += gcnew System::EventHandler(this, &commentControl::bunifuThinButton22_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->LikeLabel);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->AngryLabel);
			this->panel1->Controls->Add(this->bunifuThinButton22);
			this->panel1->Controls->Add(this->WowLabel);
			this->panel1->Controls->Add(this->LoveLabel);
			this->panel1->Controls->Add(this->bunifuThinButton21);
			this->panel1->Controls->Add(this->HahaLabel);
			this->panel1->Controls->Add(this->SadLabel);
			this->panel1->Location = System::Drawing::Point(80, 105);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(313, 109);
			this->panel1->TabIndex = 24;
			// 
			// LikeLabel
			// 
			this->LikeLabel->AutoSize = true;
			this->LikeLabel->BackColor = System::Drawing::Color::DimGray;
			this->LikeLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LikeLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LikeLabel->Location = System::Drawing::Point(20, 0);
			this->LikeLabel->Name = L"LikeLabel";
			this->LikeLabel->Size = System::Drawing::Size(23, 12);
			this->LikeLabel->TabIndex = 26;
			this->LikeLabel->Text = L"Like";
			this->LikeLabel->Visible = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->bunifuImageButton1);
			this->panel2->Controls->Add(this->bunifuImageButton6);
			this->panel2->Controls->Add(this->bunifuImageButton2);
			this->panel2->Controls->Add(this->bunifuImageButton4);
			this->panel2->Controls->Add(this->bunifuImageButton5);
			this->panel2->Controls->Add(this->bunifuImageButton3);
			this->panel2->Location = System::Drawing::Point(5, 13);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(304, 67);
			this->panel2->TabIndex = 25;
			this->panel2->Visible = false;
			this->panel2->MouseLeave += gcnew System::EventHandler(this, &commentControl::panel2_MouseLeave);
			this->panel2->MouseHover += gcnew System::EventHandler(this, &commentControl::panel2_MouseHover);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(254, 4);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(51, 60);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 10;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton1_Click);
			this->bunifuImageButton1->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton1_MouseLeave);
			this->bunifuImageButton1->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton1_MouseHover);
			// 
			// bunifuImageButton6
			// 
			this->bunifuImageButton6->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton6.Image")));
			this->bunifuImageButton6->ImageActive = nullptr;
			this->bunifuImageButton6->Location = System::Drawing::Point(206, 4);
			this->bunifuImageButton6->Name = L"bunifuImageButton6";
			this->bunifuImageButton6->Size = System::Drawing::Size(50, 60);
			this->bunifuImageButton6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton6->TabIndex = 15;
			this->bunifuImageButton6->TabStop = false;
			this->bunifuImageButton6->Zoom = 10;
			this->bunifuImageButton6->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton6_Click);
			this->bunifuImageButton6->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton6_MouseLeave);
			this->bunifuImageButton6->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton6_MouseHover);
			// 
			// bunifuImageButton2
			// 
			this->bunifuImageButton2->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.Image")));
			this->bunifuImageButton2->ImageActive = nullptr;
			this->bunifuImageButton2->Location = System::Drawing::Point(52, 4);
			this->bunifuImageButton2->Name = L"bunifuImageButton2";
			this->bunifuImageButton2->Size = System::Drawing::Size(54, 60);
			this->bunifuImageButton2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton2->TabIndex = 11;
			this->bunifuImageButton2->TabStop = false;
			this->bunifuImageButton2->Zoom = 10;
			this->bunifuImageButton2->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton2_Click);
			this->bunifuImageButton2->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton2_MouseLeave);
			this->bunifuImageButton2->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton2_MouseHover);
			// 
			// bunifuImageButton4
			// 
			this->bunifuImageButton4->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton4.Image")));
			this->bunifuImageButton4->ImageActive = nullptr;
			this->bunifuImageButton4->Location = System::Drawing::Point(3, 3);
			this->bunifuImageButton4->Name = L"bunifuImageButton4";
			this->bunifuImageButton4->Size = System::Drawing::Size(48, 60);
			this->bunifuImageButton4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton4->TabIndex = 12;
			this->bunifuImageButton4->TabStop = false;
			this->bunifuImageButton4->Zoom = 10;
			this->bunifuImageButton4->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton4_Click);
			this->bunifuImageButton4->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton4_MouseLeave);
			this->bunifuImageButton4->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton4_MouseHover);
			// 
			// bunifuImageButton5
			// 
			this->bunifuImageButton5->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton5.Image")));
			this->bunifuImageButton5->ImageActive = nullptr;
			this->bunifuImageButton5->Location = System::Drawing::Point(157, 4);
			this->bunifuImageButton5->Name = L"bunifuImageButton5";
			this->bunifuImageButton5->Size = System::Drawing::Size(55, 60);
			this->bunifuImageButton5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton5->TabIndex = 14;
			this->bunifuImageButton5->TabStop = false;
			this->bunifuImageButton5->Zoom = 10;
			this->bunifuImageButton5->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton5_Click);
			this->bunifuImageButton5->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton5_MouseLeave);
			this->bunifuImageButton5->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton5_MouseHover);
			// 
			// bunifuImageButton3
			// 
			this->bunifuImageButton3->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton3.Image")));
			this->bunifuImageButton3->ImageActive = nullptr;
			this->bunifuImageButton3->Location = System::Drawing::Point(105, 4);
			this->bunifuImageButton3->Name = L"bunifuImageButton3";
			this->bunifuImageButton3->Size = System::Drawing::Size(56, 60);
			this->bunifuImageButton3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton3->TabIndex = 9;
			this->bunifuImageButton3->TabStop = false;
			this->bunifuImageButton3->Zoom = 10;
			this->bunifuImageButton3->Click += gcnew System::EventHandler(this, &commentControl::bunifuImageButton3_Click);
			this->bunifuImageButton3->MouseLeave += gcnew System::EventHandler(this, &commentControl::bunifuImageButton3_MouseLeave);
			this->bunifuImageButton3->MouseHover += gcnew System::EventHandler(this, &commentControl::bunifuImageButton3_MouseHover);
			// 
			// AngryLabel
			// 
			this->AngryLabel->AutoSize = true;
			this->AngryLabel->BackColor = System::Drawing::Color::DimGray;
			this->AngryLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AngryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->AngryLabel->Location = System::Drawing::Point(264, 0);
			this->AngryLabel->Name = L"AngryLabel";
			this->AngryLabel->Size = System::Drawing::Size(34, 12);
			this->AngryLabel->TabIndex = 31;
			this->AngryLabel->Text = L"Angry";
			this->AngryLabel->Visible = false;
			// 
			// WowLabel
			// 
			this->WowLabel->AutoSize = true;
			this->WowLabel->BackColor = System::Drawing::Color::DimGray;
			this->WowLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WowLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->WowLabel->Location = System::Drawing::Point(175, 0);
			this->WowLabel->Name = L"WowLabel";
			this->WowLabel->Size = System::Drawing::Size(27, 12);
			this->WowLabel->TabIndex = 29;
			this->WowLabel->Text = L"wow";
			this->WowLabel->Visible = false;
			// 
			// LoveLabel
			// 
			this->LoveLabel->AutoSize = true;
			this->LoveLabel->BackColor = System::Drawing::Color::DimGray;
			this->LoveLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoveLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LoveLabel->Location = System::Drawing::Point(70, 0);
			this->LoveLabel->Name = L"LoveLabel";
			this->LoveLabel->Size = System::Drawing::Size(27, 12);
			this->LoveLabel->TabIndex = 27;
			this->LoveLabel->Text = L"Love";
			this->LoveLabel->Visible = false;
			// 
			// HahaLabel
			// 
			this->HahaLabel->AutoSize = true;
			this->HahaLabel->BackColor = System::Drawing::Color::DimGray;
			this->HahaLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HahaLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->HahaLabel->Location = System::Drawing::Point(124, 0);
			this->HahaLabel->Name = L"HahaLabel";
			this->HahaLabel->Size = System::Drawing::Size(27, 12);
			this->HahaLabel->TabIndex = 28;
			this->HahaLabel->Text = L"haha";
			this->HahaLabel->Visible = false;
			// 
			// SadLabel
			// 
			this->SadLabel->AutoSize = true;
			this->SadLabel->BackColor = System::Drawing::Color::DimGray;
			this->SadLabel->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SadLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SadLabel->Location = System::Drawing::Point(222, 0);
			this->SadLabel->Name = L"SadLabel";
			this->SadLabel->Size = System::Drawing::Size(22, 12);
			this->SadLabel->TabIndex = 30;
			this->SadLabel->Text = L"Sad";
			this->SadLabel->Visible = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(88, 312);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(313, 11);
			this->flowLayoutPanel1->TabIndex = 25;
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &commentControl::timer1_Tick);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(189, 288);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(127, 21);
			this->linkLabel1->TabIndex = 28;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"View all Replies";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &commentControl::linkLabel1_LinkClicked);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(78, 5);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(23, 23);
			this->pictureBox3->TabIndex = 34;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(55, 5);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(23, 23);
			this->pictureBox2->TabIndex = 33;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(101, 5);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(23, 23);
			this->pictureBox4->TabIndex = 31;
			this->pictureBox4->TabStop = false;
			// 
			// reactions_label
			// 
			this->reactions_label->AutoSize = true;
			this->reactions_label->Cursor = System::Windows::Forms::Cursors::Hand;
			this->reactions_label->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reactions_label->Location = System::Drawing::Point(3, 7);
			this->reactions_label->Name = L"reactions_label";
			this->reactions_label->Size = System::Drawing::Size(43, 14);
			this->reactions_label->TabIndex = 32;
			this->reactions_label->Text = L"label2";
			this->reactions_label->Click += gcnew System::EventHandler(this, &commentControl::reactions_label_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Location = System::Drawing::Point(2, 4);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(51, 53);
			this->pictureBox5->TabIndex = 24;
			this->pictureBox5->TabStop = false;
			// 
			// bunifuCustomTextbox1
			// 
			this->bunifuCustomTextbox1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->bunifuCustomTextbox1->BorderColor = System::Drawing::Color::SeaGreen;
			this->bunifuCustomTextbox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuCustomTextbox1->Location = System::Drawing::Point(57, 9);
			this->bunifuCustomTextbox1->Multiline = true;
			this->bunifuCustomTextbox1->Name = L"bunifuCustomTextbox1";
			this->bunifuCustomTextbox1->Size = System::Drawing::Size(251, 39);
			this->bunifuCustomTextbox1->TabIndex = 26;
			this->bunifuCustomTextbox1->Text = L"Write a Reply";
			this->bunifuCustomTextbox1->TextChanged += gcnew System::EventHandler(this, &commentControl::bunifuCustomTextbox1_TextChanged);
			this->bunifuCustomTextbox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &commentControl::bunifuCustomTextbox1_KeyDown);
			this->bunifuCustomTextbox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &commentControl::bunifuCustomTextbox1_KeyUp);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->bunifuCustomTextbox1);
			this->panel4->Controls->Add(this->pictureBox5);
			this->panel4->Location = System::Drawing::Point(111, 218);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(321, 64);
			this->panel4->TabIndex = 27;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->pictureBox3);
			this->panel3->Controls->Add(this->reactions_label);
			this->panel3->Controls->Add(this->pictureBox2);
			this->panel3->Controls->Add(this->pictureBox4);
			this->panel3->Location = System::Drawing::Point(318, 77);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(126, 39);
			this->panel3->TabIndex = 35;
			// 
			// commentControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->Comment_Text);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Name = L"commentControl";
			this->Size = System::Drawing::Size(534, 343);
			this->Load += gcnew System::EventHandler(this, &commentControl::commentControl_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bunifuCustomLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Posttxt_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void commentControl_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void bunifuCustomLabel1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void bunifuThinButton21_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	panel2->Visible = true;
	panel1->BringToFront();
	Like_button = true;
	timer1->Stop();
}
	public:bool Like_button = false, like = false, love = false, haha = false, sad = false, angry = false, wow = false, pa = false;
private: System::Void bunifuImageButton4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	LikeLabel->Visible = true;
	like = true;
	timer1->Stop();


}
private: System::Void bunifuImageButton4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	LikeLabel->Visible = false;
	like = false;
	timer1->Start();
}
private: System::Void bunifuThinButton21_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	Like_button = false;
	timer1->Start();
}
private: System::Void bunifuImageButton2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	LoveLabel->Visible = true;
	love = true;
	timer1->Stop();
}
private: System::Void bunifuImageButton2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	LoveLabel->Visible = false;
	love = false;
	timer1->Start();
}
private: System::Void bunifuImageButton3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	HahaLabel->Visible = true;
	haha = true;
	timer1->Stop();
}
private: System::Void bunifuImageButton3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	HahaLabel->Visible = false;
	haha = false;
	timer1->Start();
}
private: System::Void bunifuImageButton5_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	WowLabel->Visible = true;
	wow = true;
	timer1->Stop();
}
private: System::Void bunifuImageButton5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	WowLabel->Visible = false;
	wow = false;
	timer1->Start();
}
private: System::Void bunifuImageButton6_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	SadLabel->Visible = true;
	sad = true;
	timer1->Stop();
}
private: System::Void bunifuImageButton6_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	SadLabel->Visible = false;
	sad = false;
	timer1->Start();
}
private: System::Void bunifuImageButton1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	AngryLabel->Visible = true;
	angry = true;
	timer1->Stop();
}
private: System::Void bunifuImageButton1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	AngryLabel->Visible = false;
	angry = false;
	timer1->Start();
}
private: System::Void panel2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	pa = true;
	timer1->Stop();
}
private: System::Void panel2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	pa = false;
	timer1->Start();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (like == false && love == false && haha == false && wow == false && sad == false && angry == false && pa == false)
	{
		panel1->SendToBack();
		panel2->Visible = false;
	}
}
private: System::Void bunifuThinButton22_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void bunifuCustomTextbox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (bunifuCustomTextbox1->Text != "")
	{
		Graphics^g = CreateGraphics();

		SizeF^ ss = g->MeasureString(bunifuCustomTextbox1->Text, bunifuCustomTextbox1->Font, 350);
		bunifuCustomTextbox1->Height = Math::Round(ss->Height + 10, 0);
		panel4->Height = bunifuCustomTextbox1->Height+8;
		//panel4->Top = panel1->Bottom;
		flowLayoutPanel1->Top = panel4->Bottom;


	}
}
private: System::Void bunifuCustomTextbox1_Enter(System::Object^  sender, System::EventArgs^  e) {

	if (bunifuCustomTextbox1->Text == "Write a Reply")
		bunifuCustomTextbox1->Text = "";
}


private: System::Void bunifuCustomTextbox1_Leave(System::Object^  sender, System::EventArgs^  e) {
	if (bunifuCustomTextbox1->Text == "")
		bunifuCustomTextbox1->Text = "Write a Reply";
}
		 public:bool shiftispressed = false;
private: System::Void bunifuCustomTextbox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = true;
	if (e->KeyCode == Keys::Enter&&shiftispressed == false)
	{
		if (bunifuCustomTextbox1->Text != "")
		{
			//here is the code of enter a reply...
			int reply_id = FacebookSys::make_Reply(comm_id, bunifuCustomTextbox1->Text, FacebookSys::user_email);
			Reply^newReply = gcnew Reply(reply_id, bunifuCustomTextbox1->Text, FacebookSys::user_email);
			FacebookSys::AllAccounts[poster_mail]->addReplyToPost(post_id, comm_id, reply_id, newReply);
			AddReply(post_id, poster_mail, comm_id, reply_id, newReply);
			DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
			bunifuCustomTextbox1->Text = "Write a Reply";
		}
	}
}
private: System::Void bunifuCustomTextbox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = false;
}
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
	if (flowLayoutPanel1->Controls->Count == 0)
	{
		linkLabel1->Text = "Hide all Replies";
		for each(KeyValuePair<int, Reply^> reply in FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReplies())
		{
			AddReply(post_id, poster_mail, comm_id, reply.Key, reply.Value);
		}
	}
	else
	{
		linkLabel1->Text = "View all Replies";
		flowLayoutPanel1->Controls->Clear();
	}
	linkLabel1->Top = panel4->Bottom;
	flowLayoutPanel1->Top = linkLabel1->Bottom;
}
private: System::Void bunifuThinButton21_Click(System::Object^  sender, System::EventArgs^  e) {
	if (FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
	{
		FacebookSys::DeleteReactComment(comm_id);
		String^ reaction_Type = FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReactors()->GettotalReactors()[FacebookSys::user_email];
		FacebookSys::AllAccounts[poster_mail]->DeleteReactComment(post_id,comm_id, FacebookSys::user_email, reaction_Type);
		bunifuThinButton21->ButtonText = "Like";
		bunifuThinButton21->IdleForecolor = Color::DimGray;
	}
	else
	{
		FacebookSys::like_comment(comm_id, "like");
		FacebookSys::AllAccounts[poster_mail]->addReactToComment(post_id,comm_id, FacebookSys::user_email, "like");
	}
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton4_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("like");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("love");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton3_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("haha");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton5_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("wow");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton6_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("sad");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToComment("angry");
	DrawComment(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]);
}
private: System::Void reactions_label_Click(System::Object^  sender, System::EventArgs^  e) {
	Users^ commentReactors = gcnew Users(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments()[comm_id]->GetCommentReactors());
	commentReactors->ShowDialog();
}
};
}
