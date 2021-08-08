#include "Reply.h"



Reply::Reply()
{
}
Reply::Reply(int id, String^ text, String^ e_mail)
{
	this->ID = id;
	this->replier_email = e_mail;
	this->text = text;
	this->react = gcnew Reactors();

}
void Reply::addReact(String^ e_mail, String^ TypeOfReaction)
{
	react->addReact(e_mail, TypeOfReaction);
}
int Reply::getReplyId()
{
	return ID;
}
String^ Reply::GetReplyText()
{
	return text;
}
String^ Reply::GetReplierE_mail()
{
	return replier_email;
}
Reactors^ Reply::GetReplierReact()
{
	return react;
}

void Reply::DeleteReact(String^ E_mail, String^ Old_Reaction)
{
	react->DeleteReact(E_mail, Old_Reaction);
}
void Reply::UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	react->UpdateReact(E_mail, Old_Reaction, New_Reaction);
}