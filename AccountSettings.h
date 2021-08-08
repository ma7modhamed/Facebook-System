#pragma once
#include"FacebookSys.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace FacebookSystem {

	/// <summary>
	/// Summary for AccountSettings
	/// </summary>
	public ref class AccountSettings : public System::Windows::Forms::UserControl
	{
	public:
		AccountSettings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			mailLabel->Text = FacebookSys::user_email;
			AccName->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountUserName();
			Password->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountPassword();
			dateTimePicker1->Text = FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountBirthDate();
			if (FacebookSys::AllAccounts[FacebookSys::user_email]->GetAccountGender() == "Male")
				radioButton1->Checked = true;
			else
				radioButton2->Checked = true;

		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccountSettings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: Bunifu::Framework::UI::BunifuMetroTextbox^  AccName;

	private: Bunifu::Framework::UI::BunifuMetroTextbox^  Password;
	protected:




	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton1;
	private: Bunifu::Framework::UI::BunifuThinButton2^  bunifuThinButton21;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  mailLabel;

	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: Bunifu::Framework::UI::BunifuImageButton^  bunifuImageButton2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountSettings::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->AccName = (gcnew Bunifu::Framework::UI::BunifuMetroTextbox());
			this->Password = (gcnew Bunifu::Framework::UI::BunifuMetroTextbox());
			this->bunifuImageButton1 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->bunifuThinButton21 = (gcnew Bunifu::Framework::UI::BunifuThinButton2());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mailLabel = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->bunifuImageButton2 = (gcnew Bunifu::Framework::UI::BunifuImageButton());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(41, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Account Settings";
			// 
			// AccName
			// 
			this->AccName->BorderColorFocused = System::Drawing::Color::Blue;
			this->AccName->BorderColorIdle = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->AccName->BorderColorMouseHover = System::Drawing::Color::Blue;
			this->AccName->BorderThickness = 3;
			this->AccName->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->AccName->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F));
			this->AccName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->AccName->isPassword = false;
			this->AccName->Location = System::Drawing::Point(150, 47);
			this->AccName->Margin = System::Windows::Forms::Padding(4);
			this->AccName->Name = L"AccName";
			this->AccName->Size = System::Drawing::Size(367, 36);
			this->AccName->TabIndex = 1;
			this->AccName->Text = L"bunifuMetroTextbox1";
			this->AccName->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			// 
			// Password
			// 
			this->Password->BorderColorFocused = System::Drawing::Color::Blue;
			this->Password->BorderColorIdle = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Password->BorderColorMouseHover = System::Drawing::Color::Blue;
			this->Password->BorderThickness = 3;
			this->Password->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->Password->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9.75F));
			this->Password->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Password->isPassword = true;
			this->Password->Location = System::Drawing::Point(150, 100);
			this->Password->Margin = System::Windows::Forms::Padding(4);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(367, 36);
			this->Password->TabIndex = 4;
			this->Password->Text = L"bunifuMetroTextbox4";
			this->Password->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			// 
			// bunifuImageButton1
			// 
			this->bunifuImageButton1->BackColor = System::Drawing::Color::Transparent;
			this->bunifuImageButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton1.Image")));
			this->bunifuImageButton1->ImageActive = nullptr;
			this->bunifuImageButton1->Location = System::Drawing::Point(471, 107);
			this->bunifuImageButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton1->Name = L"bunifuImageButton1";
			this->bunifuImageButton1->Size = System::Drawing::Size(34, 20);
			this->bunifuImageButton1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton1->TabIndex = 5;
			this->bunifuImageButton1->TabStop = false;
			this->bunifuImageButton1->Zoom = 10;
			this->bunifuImageButton1->Click += gcnew System::EventHandler(this, &AccountSettings::bunifuImageButton1_Click);
			// 
			// bunifuThinButton21
			// 
			this->bunifuThinButton21->ActiveBorderThickness = 1;
			this->bunifuThinButton21->ActiveCornerRadius = 20;
			this->bunifuThinButton21->ActiveFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->bunifuThinButton21->ActiveForecolor = System::Drawing::Color::DarkGray;
			this->bunifuThinButton21->ActiveLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuThinButton21->BackColor = System::Drawing::SystemColors::Control;
			this->bunifuThinButton21->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuThinButton21.BackgroundImage")));
			this->bunifuThinButton21->ButtonText = L"Save";
			this->bunifuThinButton21->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bunifuThinButton21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bunifuThinButton21->ForeColor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleBorderThickness = 1;
			this->bunifuThinButton21->IdleCornerRadius = 20;
			this->bunifuThinButton21->IdleFillColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuThinButton21->IdleForecolor = System::Drawing::Color::White;
			this->bunifuThinButton21->IdleLineColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->bunifuThinButton21->Location = System::Drawing::Point(430, 247);
			this->bunifuThinButton21->Margin = System::Windows::Forms::Padding(4);
			this->bunifuThinButton21->Name = L"bunifuThinButton21";
			this->bunifuThinButton21->Size = System::Drawing::Size(75, 33);
			this->bunifuThinButton21->TabIndex = 6;
			this->bunifuThinButton21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->bunifuThinButton21->Click += gcnew System::EventHandler(this, &AccountSettings::bunifuThinButton21_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(51, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Account Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(51, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"E-Mail";
			// 
			// mailLabel
			// 
			this->mailLabel->AutoSize = true;
			this->mailLabel->Location = System::Drawing::Point(255, 11);
			this->mailLabel->Name = L"mailLabel";
			this->mailLabel->Size = System::Drawing::Size(35, 13);
			this->mailLabel->TabIndex = 9;
			this->mailLabel->Text = L"E-Mail";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(150, 154);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(172, 20);
			this->dateTimePicker1->TabIndex = 10;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(182, 202);
			this->radioButton1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(47, 17);
			this->radioButton1->TabIndex = 11;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Male";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(244, 202);
			this->radioButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(59, 17);
			this->radioButton2->TabIndex = 12;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Female";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// bunifuImageButton2
			// 
			this->bunifuImageButton2->BackColor = System::Drawing::Color::White;
			this->bunifuImageButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bunifuImageButton2.Image")));
			this->bunifuImageButton2->ImageActive = nullptr;
			this->bunifuImageButton2->Location = System::Drawing::Point(292, 73);
			this->bunifuImageButton2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bunifuImageButton2->Name = L"bunifuImageButton2";
			this->bunifuImageButton2->Size = System::Drawing::Size(34, 20);
			this->bunifuImageButton2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->bunifuImageButton2->TabIndex = 14;
			this->bunifuImageButton2->TabStop = false;
			this->bunifuImageButton2->Zoom = 10;
			this->bunifuImageButton2->Click += gcnew System::EventHandler(this, &AccountSettings::bunifuImageButton2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(104, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(177, 17);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Enter Your Password First ..";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->AccName);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->bunifuImageButton1);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->bunifuThinButton21);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->mailLabel);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->Password);
			this->panel1->Location = System::Drawing::Point(5, 110);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(535, 294);
			this->panel1->TabIndex = 16;
			this->panel1->Visible = false;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AccountSettings::panel1_Paint);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(53, 206);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(42, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Gender";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(51, 159);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Birthdate";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(51, 113);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(107, 70);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(226, 27);
			this->textBox1->TabIndex = 17;
			this->textBox1->UseSystemPasswordChar = true;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AccountSettings::textBox1_KeyDown);
			// 
			// AccountSettings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label4);
			this->Controls->Add(this->bunifuImageButton2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AccountSettings";
			this->Size = System::Drawing::Size(540, 421);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bunifuImageButton2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bunifuImageButton1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Password->isPassword==true)
			Password->isPassword = false;
		else
			Password->isPassword = true;
		
	}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
		 public: int x = 0;
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Enter)
	{
		if (textBox1->Text == Password->Text)
			panel1->Visible = true;
		else
		{
			x++;
			if (x > 5)
			{
				MessageBox::Show("Too Larg InCorrect Password .. Bye");
				Application::Exit();
			}
				
		}
	}
}
private: System::Void bunifuThinButton21_Click(System::Object^  sender, System::EventArgs^  e) {
	String^gender;
	if (radioButton1->Checked)
		gender = "Male";
	else if (radioButton2->Checked)
		gender = "Female";
	FacebookSys::EditAccountInDB(AccName->Text, Password->Text, gender, dateTimePicker1->Text);
	FacebookSys::AllAccounts[FacebookSys::user_email]->EditMyAccount(AccName->Text, Password->Text, gender, dateTimePicker1->Text);
}
private: System::Void bunifuImageButton2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->UseSystemPasswordChar == true)
		textBox1->UseSystemPasswordChar = false;
	else
		textBox1->UseSystemPasswordChar = true;
}
};
}
