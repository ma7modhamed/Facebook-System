#include "UserPost.h"
#include "FacebookSys.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;

UserPost::UserPost()
{
}

UserPost::UserPost(String^ isPublic, String^ Poster_Mail, String^ text)
{
	this->isPublic = isPublic;
	this->Poster_Mail = Poster_Mail;
	this->post_text = text;
	this->TaggedPeaple = gcnew List<String^>();
	this->reactors = gcnew Reactors();
	this->comments = gcnew Dictionary<int, Comment^>();

}
void UserPost::addTaggedUser(String^ user_email)
{
	TaggedPeaple->Add(user_email);
}
void UserPost::addReactors(String^ e_mail, String^ typeOfReaction)
{
	reactors->addReact(e_mail, typeOfReaction);
}
void UserPost::addReactorsToComment(int comment_id, String^ e_mail, String^ typeOfReaction)
{
	comments[comment_id]->addReact(e_mail, typeOfReaction);
}
void UserPost::addReactorsToReply(int comment_id, int reply_id, String^ e_mail, String^ typeOfReaction)
{
	comments[comment_id]->addReactToReply(reply_id, e_mail, typeOfReaction);
}
void UserPost::addComment(int comment_id, Comment^ c)
{
	comments->Add(comment_id, c);
}
void UserPost::addReplayToComment(int comment_id, int reply_id, Reply^ r)
{
	comments[comment_id]->addReplay(reply_id, r);
}
String^ UserPost::Getpost_text()
{
	return post_text;
}
String^ UserPost::GetPoster_Mail()
{
	return Poster_Mail;
}
List<String^>^ UserPost::GetTaggedPeaple()
{
	return TaggedPeaple;
}
String^ UserPost::isPostPublic()
{
	return isPublic;
}
Reactors^ UserPost::Getreactors()
{
	return reactors;
}
Dictionary<int, Comment^>^ UserPost::Getcomments()
{
	return comments;
}

void UserPost::DeleteReact(String^ E_mail, String^ Old_Reaction)
{
	reactors->DeleteReact(E_mail, Old_Reaction);
}
void UserPost::UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	reactors->UpdateReact(E_mail, Old_Reaction, New_Reaction);
}
void UserPost::DeleteReactComment(int comment_id, String^ E_mail, String^ Old_Reaction)
{
	comments[comment_id]->DeleteReact(E_mail, Old_Reaction);
}
void UserPost::UpdateReactComment(int comment_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	comments[comment_id]->UpdateReact(E_mail, Old_Reaction, New_Reaction);
}
void UserPost::DeleteReactReply(int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction)
{
	comments[comment_id]->DeleteReactReply(reply_id, E_mail, Old_Reaction);
}
void UserPost::UpdateReactReply(int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	comments[comment_id]->UpdateReactReply(reply_id, E_mail, Old_Reaction, New_Reaction);
}
bool UserPost::CheckIfTagged(String^ user_email)
{
	return TaggedPeaple->Contains(user_email);
}
String^ UserPost::getPrivacy()
{
	return isPublic;
}