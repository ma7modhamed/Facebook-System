#include "Comment.h"



Comment::Comment()
{
}
Comment::Comment(int id, String^ text, String^ commenter)
{
	this->ID = id;
	this->commenter_Email =commenter;
	this->text = text;
	replies = gcnew Dictionary<int, Reply^>();
	this->react = gcnew Reactors();
}
void Comment::addReplay(int id, Reply^ r)
{
	replies->Add(id, r);
}
void Comment::addReact(String^ e_mail, String^ TypeOfReaction)
{
	react->addReact(e_mail, TypeOfReaction);
}
void Comment::addReactToReply(int reply_id, String^ e_mail, String^ TypeOfReaction)
{
	replies[reply_id]->addReact(e_mail, TypeOfReaction);
}
int Comment::GetCommentId()
{
	return ID;
}
String^ Comment::GetCommentText()
{
	return text;
}
String^ Comment::GetCommenterE_mail()
{
	return  commenter_Email;
}
Reactors^ Comment::GetCommentReactors()
{
	return react;
}
Dictionary<int, Reply^>^ Comment::GetCommentReplies()
{
	return replies;
}

void Comment::DeleteReact(String^ E_mail, String^ Old_Reaction)
{
	react->DeleteReact(E_mail, Old_Reaction);
}
void Comment::UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	react->UpdateReact(E_mail,Old_Reaction,New_Reaction);
}
void Comment::DeleteReactReply(int reply_id, String^ E_mail, String^ Old_Reaction)
{
	replies[reply_id]->DeleteReact(E_mail, Old_Reaction);
}
void Comment::UpdateReactReply(int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	replies[reply_id]->UpdateReact(E_mail, Old_Reaction, New_Reaction);
}