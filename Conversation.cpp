#include "Conversation.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;


Conversation::Conversation()
{
	this->messages = gcnew List< KeyValuePair<String^, String^>>();
	this->Users_Emails = gcnew List<String^>();

}
void Conversation::AddMessage(String^ sender, String^ text)
{
	KeyValuePair<String^, String^> message(sender, text);//cannot assign a value to the keyvaluepair

	this->messages->Add(message);
}
void Conversation::addUsers(String^ UserEmail)
{
	Users_Emails->Add(UserEmail);
}
List < KeyValuePair<String^, String^>>^ Conversation::GetMessages()
{
	return messages;
}
List<String^>^ Conversation::GetUserEmails()
{
	return Users_Emails;
}
