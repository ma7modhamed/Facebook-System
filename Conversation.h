#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
ref class Conversation
{

	List < KeyValuePair<String^, String^>>^ messages;//key is sender email , value is the message sent
	List<String^>^ Users_Emails;
public:
	Conversation();
	void addUsers(String^ UserEmail);
	void AddMessage(String^ sender, String^ text);
	List < KeyValuePair<String^, String^>>^ GetMessages();
	List<String^>^ GetUserEmails();
};

