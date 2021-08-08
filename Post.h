#pragma once
#include"commentControl.h"
#include"FacebookSys.h"
#include"UserPost.h"
#include"Users.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;


namespace FacebookSystem {

	/// <summary>
	/// Summary for Post
	/// </summary>
	public ref class Post : public System::Windows::Forms::UserControl
	{
	public:
		int totalReactors = 0, like_count = 0, love_count = 0, haha_count = 0, angry_count = 0, sad_count = 0, wow_count = 0;
		int Commentscount = 0; bool ReactedByMe=false;
		String^ reactTypebyme = "", ^poster_mail = "";
		
		List<String^>^ ReactionPriority = gcnew List<String^>();
		
	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton2;
	public:

	public:
		int post_id = 0;
		void DrawPost(UserPost^ post)
		{
			like_count = post->Getreactors()->GetReactorsCount()["like"];
			love_count = post->Getreactors()->GetReactorsCount()["love"];
			haha_count = post->Getreactors()->GetReactorsCount()["haha"];
			angry_count = post->Getreactors()->GetReactorsCount()["angry"];
			wow_count = post->Getreactors()->GetReactorsCount()["wow"];
			sad_count = post->Getreactors()->GetReactorsCount()["sad"];
			totalReactors = like_count + haha_count + love_count + wow_count + sad_count + angry_count;
			Commentscount = post->Getcomments()->Count;

			if (post->Getreactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
			{
				ReactedByMe = true;
				reactTypebyme = post->Getreactors()->GettotalReactors()[FacebookSys::user_email];
			}
			else
				ReactedByMe = false;
			List<String^>^ reaction = gcnew List<String^>();
			if (totalReactors == 0 && Commentscount == 0)
			{
				panel3->Visible = false;
				panel4->Top = panel2->Bottom;
				linkLabel1->Visible = false;
			}
			if (Commentscount != 0)
			{
				if (totalReactors == 0)
				{
					pictureBox2->Visible = false;
					pictureBox3->Visible = false;
					pictureBox4->Visible = false;
					reactions_label->Visible = false;
				}
				//hide reactors image and its count

				panel3->Visible = true;
				commentscount_label->Visible = true;
				linkLabel1->Visible = true;
				label4->Visible = true;
				commentscount_label->Text = Commentscount.ToString();
				panel3->Top = panel2->Bottom;
				panel4->Top = panel3->Bottom;
				linkLabel1->Top = panel4->Bottom;
				flowLayoutPanel1->Top = linkLabel1->Bottom;

			}
			if (totalReactors != 0)
			{
				if (Commentscount == 0)
				{
					commentscount_label->Visible = false;
					label4->Visible = false;
					linkLabel1->Visible = false;
				}
				reactions_label->Text = totalReactors.ToString();
				panel3->Visible = true;
				commentscount_label->Text = Commentscount.ToString();
				panel3->Top = panel2->Bottom;
				panel4->Top = panel3->Bottom;
				linkLabel1->Top = panel4->Bottom;
				flowLayoutPanel1->Top = linkLabel1->Bottom;
				pictureBox2->Visible = true;
				pictureBox3->Visible = true;
				pictureBox4->Visible = true;
				reactions_label->Visible = true;

				if (ReactedByMe)
				{

					if (reactTypebyme == "like")
					{
						bunifuFlatButton1->Text = "Like";
						bunifuFlatButton1->Textcolor = Color::FromArgb(64, 128, 255);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["like"]);
					}
					if (reactTypebyme == "love")
					{
						bunifuFlatButton1->Text = "Love";
						bunifuFlatButton1->Textcolor = Color::FromArgb(243, 82, 105);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["love"]);
					}
					if (reactTypebyme == "sad")
					{
						bunifuFlatButton1->Text = "Sad";
						bunifuFlatButton1->Textcolor = Color::FromArgb(240, 186, 21);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["sad"]);

					}
					if (reactTypebyme == "angry")
					{
						bunifuFlatButton1->Text = "Angry";
						bunifuFlatButton1->Textcolor = Color::FromArgb(247, 113, 75);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["angry"]);
					}
					if (reactTypebyme == "haha")
					{
						bunifuFlatButton1->Text = "Haha";
						bunifuFlatButton1->Textcolor = Color::FromArgb(240, 186, 21);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["haha"]);
					}
					if (reactTypebyme == "wow")
					{
						bunifuFlatButton1->Text = "Wow";
						bunifuFlatButton1->Textcolor = Color::FromArgb(240, 186, 21);
						bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::reactionsImagesPath["wow"]);
					}


				}
				int index=0;
				for each  (KeyValuePair<String^, int> r in post->Getreactors()->GetReactorsCount())
				{
					
					
	
					if (r.Value == 0)
					{
						continue;
					}
					index = 0;
					
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
						if (r.Value > post->Getreactors()->GetReactorsCount()[reaction[i]])
						{
							reaction->Insert(index, r.Key);
							break;
						}
						else if (r.Value == post->Getreactors()->GetReactorsCount()[reaction[i]])
						{
							if (ReactionPriority->IndexOf(r.Key) < ReactionPriority->IndexOf(reaction[i]))
							{
								reaction->Insert(index, r.Key);
								break;
							}
							else
							{
								index++;
								if (index == reaction->Count)
								{
									reaction->Insert(index, r.Key);
								}
							}
						}
						else
						{
							index++;
							if(index==reaction->Count)
							{
								reaction->Insert(index, r.Key);
							}
						}
					}

				}
				
				/*for each (String^ var in reaction)
				{
					MessageBox::Show(var);
				}*/
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
		Post(void)
		{
		InitializeComponent();
		}
			Post(int p_id, UserPost^ post)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
				UserName->Text = FacebookSys::AllAccounts[post->GetPoster_Mail()]->GetAccountUserName();
				Posttxt->Text = post->Getpost_text();
				post_id = p_id;
				poster_mail = post->GetPoster_Mail();
				label2->Text = post->getPrivacy();
				if (post->getPrivacy() == "Friends")
				{
					pictureBox7->Location = pictureBox6->Location;
					pictureBox7->Visible = true;
					pictureBox6->Visible = false;

				}
					
				Graphics^g = CreateGraphics();
				SizeF^ ss = g->MeasureString(Posttxt->Text, Posttxt->Font, 580);
				Posttxt->Height = Math::Round(ss->Height + 10, 0);
				panel2->Top = Posttxt->Bottom - 60;
				panel3->Top = panel2->Bottom;
				panel4->Top = panel3->Bottom;
				linkLabel1->Top = panel4->Bottom;
				flowLayoutPanel1->Top = linkLabel1->Bottom;
				if (post->GetTaggedPeaple()->Count == 0)
					panel5->Visible = false;
				else if (post->GetTaggedPeaple()->Count == 1)
				{
					panel5->Visible = true;
					firstTagged->Text = FacebookSys::AllAccounts[post->GetTaggedPeaple()[0]]->GetAccountUserName();
					
				}
				else
				{
					panel5->Visible = true;
					firstTagged->Text = FacebookSys::AllAccounts[post->GetTaggedPeaple()[0]]->GetAccountUserName() + " and "+ (post->GetTaggedPeaple()->Count - 1).ToString() + " others";
					
				}

				if (FacebookSys::AllAccounts[poster_mail]->GetAccountGender()=="Female")
					pictureBox1->BackgroundImage = Image::FromFile(FacebookSys::femaleicon_image);
				if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountGender()=="Female")
					pictureBox5->BackgroundImage= Image::FromFile(FacebookSys::femaleicon_image);
				ReactionPriority->Add("like");
				
				ReactionPriority->Add("love");
				
				ReactionPriority->Add("haha");
				
				ReactionPriority->Add("wow");
				
				ReactionPriority->Add("sad");
				
				ReactionPriority->Add("angry");
				
				
				DrawPost(post);


				
			}
			
			void ReactToPost(String^ New_Reaction_Type)
			{
				if (FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getreactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
				{
					FacebookSys::UpdateReactPost(post_id, New_Reaction_Type);
					String^ Old_reaction_Type = FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getreactors()->GettotalReactors()[FacebookSys::user_email];
					FacebookSys::AllAccounts[poster_mail]->UpdateReactPost(post_id, FacebookSys::user_email, Old_reaction_Type, New_Reaction_Type);
				}
				else
				{
					FacebookSys::Like_Post(post_id, New_Reaction_Type);
					FacebookSys::AllAccounts[poster_mail]->addReactToPost(post_id,FacebookSys::user_email, New_Reaction_Type);
				}
			}
			void addComment(String^ PosterMail, int Post_id, int comment_id, Comment^ comment)
			{
				commentControl^c = gcnew commentControl(PosterMail, Post_id, comment_id, comment);
				flowLayoutPanel1->Controls->Add(c);

			}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  firstTagged;
private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	

			 

	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Post()
		{
			if (components)
			{
				delete components;
				
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  UserName;
	protected:






	private: System::Windows::Forms::Label^  LikeLabel;


	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton3;

	private: Bunifu::Framework::UI::BunifuFlatButton^  bunifuFlatButton1;


	private: System::Windows::Forms::Panel^  panel1;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton6;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton4;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  LoveLabel;
	private: System::Windows::Forms::Label^  HahaLabel;
	private: System::Windows::Forms::Label^  WowLabel;
	private: System::Windows::Forms::Label^  SadLabel;
	private: System::Windows::Forms::Label^  AngryLabel;
	private: System::Windows::Forms::Label^  Posttxt;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  commentscount_label;
private: System::Windows::Forms::Label^  reactions_label;


	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;



	private: WindowsFormsControlLibrary1::BunifuCustomTextbox^  bunifuCustomTextbox1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;











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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Post::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->UserName = (gcnew System::Windows::Forms::Label());
			this->LikeLabel = (gcnew System::Windows::Forms::Label());
			this->bunifuImageButton3 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuFlatButton1 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton6 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton2 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton4 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuImageButton5 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->LoveLabel = (gcnew System::Windows::Forms::Label());
			this->HahaLabel = (gcnew System::Windows::Forms::Label());
			this->WowLabel = (gcnew System::Windows::Forms::Label());
			this->SadLabel = (gcnew System::Windows::Forms::Label());
			this->AngryLabel = (gcnew System::Windows::Forms::Label());
			this->Posttxt = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->bunifuFlatButton2 = (gcnew Bunifu::Framework::UI::BunifuFlatButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->commentscount_label = (gcnew System::Windows::Forms::Label());
			this->reactions_label = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->bunifuCustomTextbox1 = (gcnew WindowsFormsControlLibrary1::BunifuCustomTextbox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->firstTagged = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton3))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(41, 4);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(51, 49);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// UserName
			// 
			this->UserName->AutoSize = true;
			this->UserName->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UserName->ForeColor = System::Drawing::Color::DarkBlue;
			this->UserName->Location = System::Drawing::Point(98, 4);
			this->UserName->Name = L"UserName";
			this->UserName->Size = System::Drawing::Size(102, 23);
			this->UserName->TabIndex = 3;
			this->UserName->Text = L"UNKNOWN";
			this->UserName->Click += gcnew System::EventHandler(this, &Post::label1_Click);
			this->UserName->MouseLeave += gcnew System::EventHandler(this, &Post::label1_MouseLeave);
			this->UserName->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::label1_MouseMove);
			// 
			// LikeLabel
			// 
			this->LikeLabel->AutoSize = true;
			this->LikeLabel->BackColor = System::Drawing::Color::DimGray;
			this->LikeLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LikeLabel->Location = System::Drawing::Point(21, 1);
			this->LikeLabel->Name = L"LikeLabel";
			this->LikeLabel->Size = System::Drawing::Size(25, 13);
			this->LikeLabel->TabIndex = 7;
			this->LikeLabel->Text = L"Like";
			this->LikeLabel->Visible = false;
			// 
			// bunifuImageButton3
			// 
			this->bunifuImageButton3->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton3.Image")));
			this->bunifuImageButton3->ImageActive = nullptr;
			this->bunifuImageButton3->Location = System::Drawing::Point(113, 2);
			this->bunifuImageButton3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton3->Name = L"bunifuImageButton3";
			this->bunifuImageButton3->Size = System::Drawing::Size(68, 58);
			this->bunifuImageButton3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton3->TabIndex = 9;
			this->bunifuImageButton3->TabStop = false;
			this->bunifuImageButton3->Zoom = 10;
			this->bunifuImageButton3->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton3_Click);
			this->bunifuImageButton3->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton3_MouseLeave);
			this->bunifuImageButton3->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton3_MouseHover);
			this->bunifuImageButton3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton3_MouseMove);
			// 
			// bunifuFlatButton1
			// 
			this->bunifuFlatButton1->Activecolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton1->BorderRadius = 0;
			this->bunifuFlatButton1->ButtonText = L"Like";
			this->bunifuFlatButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton1->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton1->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
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
			this->bunifuFlatButton1->IconZoom = 60;
			this->bunifuFlatButton1->IsTab = false;
			this->bunifuFlatButton1->Location = System::Drawing::Point(3, 79);
			this->bunifuFlatButton1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->bunifuFlatButton1->Name = L"bunifuFlatButton1";
			this->bunifuFlatButton1->Normalcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->OnHovercolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton1->OnHoverTextColor = System::Drawing::Color::Black;
			this->bunifuFlatButton1->selected = false;
			this->bunifuFlatButton1->Size = System::Drawing::Size(82, 37);
			this->bunifuFlatButton1->TabIndex = 10;
			this->bunifuFlatButton1->Text = L"Like";
			this->bunifuFlatButton1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->bunifuFlatButton1->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuFlatButton1->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton1->Click += gcnew System::EventHandler(this, &Post::bunifuFlatButton1_Click);
			this->bunifuFlatButton1->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuFlatButton1_MouseLeave);
			this->bunifuFlatButton1->MouseHover += gcnew System::EventHandler(this, &Post::bunifuFlatButton1_MouseHover);
			this->bunifuFlatButton1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuFlatButton1_MouseMove);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Controls->Add(this->bunifuImageButton6);
			this->panel1->Controls->Add(this->bunifuImageButton2);
			this->panel1->Controls->Add(this->bunifuImageButton4);
			this->panel1->Controls->Add(this->bunifuImageButton5);
			this->panel1->Controls->Add(this->bunifuImageButton3);
			this->panel1->Location = System::Drawing::Point(3, 15);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(343, 63);
			this->panel1->TabIndex = 13;
			this->panel1->Visible = false;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Post::panel1_Paint);
			this->panel1->MouseLeave += gcnew System::EventHandler(this, &Post::panel1_MouseLeave);
			this->panel1->MouseHover += gcnew System::EventHandler(this, &Post::panel1_MouseHover);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::panel1_MouseMove);
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(284, 2);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(57, 58);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 10;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton1_Click_1);
			this->bunifuImageButton1->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton1_MouseLeave_1);
			this->bunifuImageButton1->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton1_MouseHover_1);
			this->bunifuImageButton1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton1_MouseMove_1);
			// 
			// bunifuImageButton6
			// 
			this->bunifuImageButton6->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton6.Image")));
			this->bunifuImageButton6->ImageActive = nullptr;
			this->bunifuImageButton6->Location = System::Drawing::Point(230, 2);
			this->bunifuImageButton6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton6->Name = L"bunifuImageButton6";
			this->bunifuImageButton6->Size = System::Drawing::Size(59, 58);
			this->bunifuImageButton6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton6->TabIndex = 15;
			this->bunifuImageButton6->TabStop = false;
			this->bunifuImageButton6->Zoom = 10;
			this->bunifuImageButton6->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton6_Click);
			this->bunifuImageButton6->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton6_MouseLeave);
			this->bunifuImageButton6->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton6_MouseHover);
			this->bunifuImageButton6->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton6_MouseMove);
			// 
			// bunifuImageButton2
			// 
			this->bunifuImageButton2->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.Image")));
			this->bunifuImageButton2->ImageActive = nullptr;
			this->bunifuImageButton2->Location = System::Drawing::Point(57, 2);
			this->bunifuImageButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton2->Name = L"bunifuImageButton2";
			this->bunifuImageButton2->Size = System::Drawing::Size(66, 58);
			this->bunifuImageButton2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton2->TabIndex = 11;
			this->bunifuImageButton2->TabStop = false;
			this->bunifuImageButton2->Zoom = 10;
			this->bunifuImageButton2->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton2_Click);
			this->bunifuImageButton2->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton2_MouseLeave);
			this->bunifuImageButton2->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton2_MouseHover);
			this->bunifuImageButton2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton2_MouseMove);
			// 
			// bunifuImageButton4
			// 
			this->bunifuImageButton4->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton4.Image")));
			this->bunifuImageButton4->ImageActive = nullptr;
			this->bunifuImageButton4->Location = System::Drawing::Point(3, 2);
			this->bunifuImageButton4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton4->Name = L"bunifuImageButton4";
			this->bunifuImageButton4->Size = System::Drawing::Size(61, 58);
			this->bunifuImageButton4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton4->TabIndex = 12;
			this->bunifuImageButton4->TabStop = false;
			this->bunifuImageButton4->Zoom = 10;
			this->bunifuImageButton4->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton4_Click);
			this->bunifuImageButton4->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton4_MouseLeave);
			this->bunifuImageButton4->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton4_MouseHover);
			this->bunifuImageButton4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton4_MouseMove);
			// 
			// bunifuImageButton5
			// 
			this->bunifuImageButton5->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->bunifuImageButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton5.Image")));
			this->bunifuImageButton5->ImageActive = nullptr;
			this->bunifuImageButton5->Location = System::Drawing::Point(177, 2);
			this->bunifuImageButton5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton5->Name = L"bunifuImageButton5";
			this->bunifuImageButton5->Size = System::Drawing::Size(54, 58);
			this->bunifuImageButton5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton5->TabIndex = 14;
			this->bunifuImageButton5->TabStop = false;
			this->bunifuImageButton5->Zoom = 10;
			this->bunifuImageButton5->Click += gcnew System::EventHandler(this, &Post::bunifuImageButton5_Click);
			this->bunifuImageButton5->MouseLeave += gcnew System::EventHandler(this, &Post::bunifuImageButton5_MouseLeave);
			this->bunifuImageButton5->MouseHover += gcnew System::EventHandler(this, &Post::bunifuImageButton5_MouseHover);
			this->bunifuImageButton5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuImageButton5_MouseMove);
			// 
			// timer1
			// 
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Post::timer1_Tick);
			// 
			// LoveLabel
			// 
			this->LoveLabel->AutoSize = true;
			this->LoveLabel->BackColor = System::Drawing::Color::DimGray;
			this->LoveLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LoveLabel->Location = System::Drawing::Point(77, 1);
			this->LoveLabel->Name = L"LoveLabel";
			this->LoveLabel->Size = System::Drawing::Size(30, 13);
			this->LoveLabel->TabIndex = 14;
			this->LoveLabel->Text = L"Love";
			this->LoveLabel->Visible = false;
			// 
			// HahaLabel
			// 
			this->HahaLabel->AutoSize = true;
			this->HahaLabel->BackColor = System::Drawing::Color::DimGray;
			this->HahaLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->HahaLabel->Location = System::Drawing::Point(135, 1);
			this->HahaLabel->Name = L"HahaLabel";
			this->HahaLabel->Size = System::Drawing::Size(31, 13);
			this->HahaLabel->TabIndex = 15;
			this->HahaLabel->Text = L"haha";
			this->HahaLabel->Visible = false;
			// 
			// WowLabel
			// 
			this->WowLabel->AutoSize = true;
			this->WowLabel->BackColor = System::Drawing::Color::DimGray;
			this->WowLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->WowLabel->Location = System::Drawing::Point(193, 1);
			this->WowLabel->Name = L"WowLabel";
			this->WowLabel->Size = System::Drawing::Size(29, 13);
			this->WowLabel->TabIndex = 16;
			this->WowLabel->Text = L"wow";
			this->WowLabel->Visible = false;
			// 
			// SadLabel
			// 
			this->SadLabel->AutoSize = true;
			this->SadLabel->BackColor = System::Drawing::Color::DimGray;
			this->SadLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->SadLabel->Location = System::Drawing::Point(249, 1);
			this->SadLabel->Name = L"SadLabel";
			this->SadLabel->Size = System::Drawing::Size(25, 13);
			this->SadLabel->TabIndex = 17;
			this->SadLabel->Text = L"Sad";
			this->SadLabel->Visible = false;
			// 
			// AngryLabel
			// 
			this->AngryLabel->AutoSize = true;
			this->AngryLabel->BackColor = System::Drawing::Color::DimGray;
			this->AngryLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->AngryLabel->Location = System::Drawing::Point(295, 1);
			this->AngryLabel->Name = L"AngryLabel";
			this->AngryLabel->Size = System::Drawing::Size(36, 13);
			this->AngryLabel->TabIndex = 18;
			this->AngryLabel->Text = L"Angry";
			this->AngryLabel->Visible = false;
			// 
			// Posttxt
			// 
			this->Posttxt->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Posttxt->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Posttxt->Location = System::Drawing::Point(21, 65);
			this->Posttxt->Name = L"Posttxt";
			this->Posttxt->Size = System::Drawing::Size(502, 119);
			this->Posttxt->TabIndex = 19;
			this->Posttxt->Text = L"Post";
			this->Posttxt->Click += gcnew System::EventHandler(this, &Post::Posttxt_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowLayoutPanel1->Location = System::Drawing::Point(72, 362);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(0, 0);
			this->flowLayoutPanel1->TabIndex = 20;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Controls->Add(this->LikeLabel);
			this->panel2->Controls->Add(this->bunifuFlatButton1);
			this->panel2->Controls->Add(this->AngryLabel);
			this->panel2->Controls->Add(this->WowLabel);
			this->panel2->Controls->Add(this->LoveLabel);
			this->panel2->Controls->Add(this->HahaLabel);
			this->panel2->Controls->Add(this->SadLabel);
			this->panel2->Controls->Add(this->bunifuFlatButton2);
			this->panel2->Location = System::Drawing::Point(91, 142);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(347, 119);
			this->panel2->TabIndex = 21;
			// 
			// bunifuFlatButton2
			// 
			this->bunifuFlatButton2->Activecolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->BackColor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bunifuFlatButton2->BorderRadius = 0;
			this->bunifuFlatButton2->ButtonText = L"Comment";
			this->bunifuFlatButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuFlatButton2->DisabledColor = System::Drawing::Color::Gray;
			this->bunifuFlatButton2->Font = (gcnew System::Drawing::Font(L"Tahoma", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
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
			this->bunifuFlatButton2->IconZoom = 60;
			this->bunifuFlatButton2->IsTab = false;
			this->bunifuFlatButton2->Location = System::Drawing::Point(102, 80);
			this->bunifuFlatButton2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->bunifuFlatButton2->Name = L"bunifuFlatButton2";
			this->bunifuFlatButton2->Normalcolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->OnHovercolor = System::Drawing::Color::Transparent;
			this->bunifuFlatButton2->OnHoverTextColor = System::Drawing::Color::Blue;
			this->bunifuFlatButton2->selected = false;
			this->bunifuFlatButton2->Size = System::Drawing::Size(110, 37);
			this->bunifuFlatButton2->TabIndex = 12;
			this->bunifuFlatButton2->Text = L"Comment";
			this->bunifuFlatButton2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->bunifuFlatButton2->Textcolor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuFlatButton2->TextFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bunifuFlatButton2->Click += gcnew System::EventHandler(this, &Post::bunifuFlatButton2_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel3->Controls->Add(this->pictureBox3);
			this->panel3->Controls->Add(this->pictureBox2);
			this->panel3->Controls->Add(this->pictureBox4);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->commentscount_label);
			this->panel3->Controls->Add(this->reactions_label);
			this->panel3->Location = System::Drawing::Point(3, 263);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(519, 27);
			this->panel3->TabIndex = 22;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(95, 1);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(23, 24);
			this->pictureBox3->TabIndex = 30;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(72, 1);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(23, 24);
			this->pictureBox2->TabIndex = 29;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox4->Location = System::Drawing::Point(119, 1);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(23, 24);
			this->pictureBox4->TabIndex = 25;
			this->pictureBox4->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(267, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Comments";
			// 
			// commentscount_label
			// 
			this->commentscount_label->AutoSize = true;
			this->commentscount_label->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commentscount_label->Location = System::Drawing::Point(226, 4);
			this->commentscount_label->Name = L"commentscount_label";
			this->commentscount_label->Size = System::Drawing::Size(41, 13);
			this->commentscount_label->TabIndex = 27;
			this->commentscount_label->Text = L"label3";
			// 
			// reactions_label
			// 
			this->reactions_label->AutoSize = true;
			this->reactions_label->Cursor = System::Windows::Forms::Cursors::Hand;
			this->reactions_label->Font = (gcnew System::Drawing::Font(L"Tahoma", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reactions_label->Location = System::Drawing::Point(147, 3);
			this->reactions_label->Name = L"reactions_label";
			this->reactions_label->Size = System::Drawing::Size(41, 13);
			this->reactions_label->TabIndex = 26;
			this->reactions_label->Text = L"label2";
			this->reactions_label->Click += gcnew System::EventHandler(this, &Post::reactions_label_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->bunifuCustomTextbox1);
			this->panel4->Controls->Add(this->pictureBox5);
			this->panel4->Location = System::Drawing::Point(8, 288);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(515, 52);
			this->panel4->TabIndex = 23;
			// 
			// bunifuCustomTextbox1
			// 
			this->bunifuCustomTextbox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->bunifuCustomTextbox1->BorderColor = System::Drawing::Color::SeaGreen;
			this->bunifuCustomTextbox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuCustomTextbox1->Location = System::Drawing::Point(110, 6);
			this->bunifuCustomTextbox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuCustomTextbox1->Multiline = true;
			this->bunifuCustomTextbox1->Name = L"bunifuCustomTextbox1";
			this->bunifuCustomTextbox1->Size = System::Drawing::Size(334, 42);
			this->bunifuCustomTextbox1->TabIndex = 26;
			this->bunifuCustomTextbox1->Text = L"Write a Comment";
			this->bunifuCustomTextbox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Post::bunifuCustomTextbox1_MouseClick);
			this->bunifuCustomTextbox1->TextChanged += gcnew System::EventHandler(this, &Post::bunifuCustomTextbox1_TextChanged);
			this->bunifuCustomTextbox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Post::bunifuCustomTextbox1_KeyDown_1);
			this->bunifuCustomTextbox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Post::bunifuCustomTextbox1_KeyUp);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox5->Location = System::Drawing::Point(59, 3);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(45, 45);
			this->pictureBox5->TabIndex = 24;
			this->pictureBox5->TabStop = false;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->Location = System::Drawing::Point(215, 345);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(121, 17);
			this->linkLabel1->TabIndex = 25;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"View all Comments";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Post::linkLabel1_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 14);
			this->label1->TabIndex = 26;
			this->label1->Text = L"with";
			// 
			// firstTagged
			// 
			this->firstTagged->AutoSize = true;
			this->firstTagged->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->firstTagged->ForeColor = System::Drawing::Color::DarkBlue;
			this->firstTagged->Location = System::Drawing::Point(47, 5);
			this->firstTagged->Name = L"firstTagged";
			this->firstTagged->Size = System::Drawing::Size(76, 17);
			this->firstTagged->TabIndex = 27;
			this->firstTagged->Text = L"UNKNOWN";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->firstTagged);
			this->panel5->Controls->Add(this->label1);
			this->panel5->Location = System::Drawing::Point(288, 2);
			this->panel5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(235, 28);
			this->panel5->TabIndex = 30;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox6->Location = System::Drawing::Point(101, 29);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(19, 19);
			this->pictureBox6->TabIndex = 31;
			this->pictureBox6->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(125, 31);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 32;
			this->label2->Text = L"Public";
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(167, 29);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(21, 19);
			this->pictureBox7->TabIndex = 33;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			// 
			// Post
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->Posttxt);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->UserName);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Post";
			this->Size = System::Drawing::Size(526, 466);
			this->Load += gcnew System::EventHandler(this, &Post::Post_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton3))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton5))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show("Liked");
	}
private: System::Void Post_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bunifuImageButton1_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bunifuImageButton1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

}
private: System::Void bunifuImageButton1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void bunifuImageButton1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	

}
		 public: bool like = false, love = false, haha = false, wow = false, sad = false, angry = false, p = false,like_button=false;
private: System::Void bunifuFlatButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getreactors()->GettotalReactors()->ContainsKey(FacebookSys::user_email))
	{
		FacebookSys::DeleteReactPost(post_id);
		String^ reaction_Type = FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getreactors()->GettotalReactors()[FacebookSys::user_email];
		FacebookSys::AllAccounts[poster_mail]->DeleteReactPost(post_id, FacebookSys::user_email, reaction_Type);
		bunifuFlatButton1->Iconimage = Image::FromFile(FacebookSys::noLike_Image);
		bunifuFlatButton1->Text = "Like";
		bunifuFlatButton1->Textcolor = Color::FromArgb(50, 0, 100);
	}
	else
	{
		FacebookSys::Like_Post(post_id, "like");
		FacebookSys::AllAccounts[poster_mail]->addReactToPost(post_id, FacebookSys::user_email, "like");
	}
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void bunifuFlatButton1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	panel1->Visible = true;
	panel2->BringToFront();
}
private: System::Void bunifuFlatButton1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	like_button = false;
	timer1->Start();
}
private: System::Void bunifuFlatButton1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	

}
private: System::Void panel1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	p = false;
	

	
}
private: System::Void bunifuImageButton1_MouseLeave_1(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	angry = false;
	AngryLabel->Visible = false;
}
private: System::Void bunifuImageButton4_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	if (like == false && love == false && wow == false && sad == false && angry == false && haha == false && p == false && like_button == false)
	{
		panel1->Visible = false;
		panel2->SendToBack();

	}
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	like = false;
	timer1->Start();
	LikeLabel->Visible = false;
}
private: System::Void bunifuImageButton2_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton3_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton5_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton6_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton1_MouseMove_1(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
}
private: System::Void bunifuImageButton4_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	like = true;
	LikeLabel->Visible = true;
}
private: System::Void bunifuImageButton2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	love = true;
	LoveLabel->Visible = true;
}
private: System::Void bunifuImageButton2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	love = false;
	LoveLabel->Visible = false;
}
private: System::Void bunifuImageButton3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	haha = true;
	HahaLabel->Visible = true;
}
private: System::Void bunifuImageButton3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	haha = false;
	HahaLabel->Visible = false;
}
private: System::Void bunifuImageButton5_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	wow = true;
	WowLabel->Visible = true;
}
private: System::Void bunifuImageButton5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	wow = false;
	WowLabel->Visible = false;
}
private: System::Void bunifuImageButton6_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	sad = true;
	SadLabel->Visible = true;
}
private: System::Void bunifuImageButton6_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	timer1->Start();
	sad = false;
	SadLabel->Visible = false;
}
private: System::Void bunifuImageButton1_MouseHover_1(System::Object^  sender, System::EventArgs^  e) {
	timer1->Stop();
	angry = true;
	AngryLabel->Visible = true;
}
private: System::Void bunifuImageButton4_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("like");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

}
private: System::Void bunifuMetroTextbox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	
}
private: System::Void bunifuMetroTextbox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
		MessageBox::Show("Mdddddddddddddddddd");
}
private: System::Void bunifuCustomTextbox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	
}
private: System::Void bunifuCustomTextbox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (bunifuCustomTextbox1->Text != "")
	{
		Graphics^g = CreateGraphics();

		SizeF^ ss = g->MeasureString(bunifuCustomTextbox1->Text, bunifuCustomTextbox1->Font, 350);
		bunifuCustomTextbox1->Height = Math::Round(ss->Height + 10, 0);
		panel4->Height = bunifuCustomTextbox1->Height + 8;
		//panel4->Top = panel3->Bottom;
		linkLabel1->Top = panel4->Bottom;
		flowLayoutPanel1->Top = linkLabel1->Bottom;
		bunifuCustomTextbox1->Select();
	}
	
	
}

private: System::Void bunifuFlatButton2_Click(System::Object^  sender, System::EventArgs^  e) {
//	bunifuCustomTextbox1->Select();
	
	
	
}
private: System::Void panel1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	p = true;

}
		 public:bool shiftispressed = false;
private: System::Void Posttxt_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bunifuCustomTextbox1_KeyDown_1(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = true;
	if (e->KeyCode == Keys::Enter && shiftispressed == false)
	{
		if (bunifuCustomTextbox1->Text != "")
		{
			//here is the action with Enter when writing a comment 
			int comment_id = FacebookSys::insertCommentDB(bunifuCustomTextbox1->Text, post_id);
			Comment^newComment = gcnew Comment(comment_id, bunifuCustomTextbox1->Text, FacebookSys::user_email);
			FacebookSys::AllAccounts[poster_mail]->addCommentToPost(post_id, comment_id, newComment);
			addComment(poster_mail, post_id, comment_id, newComment);
			linkLabel1->Text = "Hide all Comments";
			DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
			bunifuCustomTextbox1->Text = "Write a Comment";
		}
	}
		
}

private: System::Void bunifuCustomTextbox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::ShiftKey)
		shiftispressed = false;
}
private: System::Void bunifuMetroTextbox1_OnValueChanged(System::Object^  sender, System::EventArgs^  e) {

}

private: System::Void bunifuCustomTextbox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (bunifuCustomTextbox1->Text == "Write a Comment")
	bunifuCustomTextbox1->Text = "";
}
private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) 
{

	if (flowLayoutPanel1->Controls->Count == 0)
	{
		linkLabel1->Text = "Hide all Comments";
		for each (KeyValuePair<int, Comment^> comment in FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getcomments())
		{
			addComment(poster_mail, post_id,  comment.Key, comment.Value);
		}
		
	}
	else
	{
		linkLabel1->Text = "View all Comments";
		flowLayoutPanel1->Controls->Clear();
	}
	LikeLabel->Top = panel4->Bottom;
	flowLayoutPanel1->Top = linkLabel1->Bottom;
	
}
private: System::Void label1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	UserName->ForeColor = Color::MediumBlue;
}
private: System::Void label1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
	UserName->ForeColor = Color::DarkBlue;
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void bunifuImageButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("love");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void bunifuImageButton3_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("haha");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void bunifuImageButton5_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("wow");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void bunifuImageButton6_Click(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("sad");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void bunifuImageButton1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	ReactToPost("angry");
	panel1->Visible = false;
	DrawPost(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id));
}
private: System::Void reactions_label_Click(System::Object^  sender, System::EventArgs^  e) {
	Users^ reactors = gcnew Users(FacebookSys::AllAccounts[poster_mail]->getMypost(post_id)->Getreactors());
	reactors->ShowDialog();
}
};
}
