#pragma once
#include"Reactors.h"
#include"Comment.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
public ref class UserPost
{

	String^post_text;
	String^Poster_Mail;
	List<String^>^TaggedPeaple;
	String^ isPublic;
	//object from class reactors
	Reactors^ reactors;
	//list of comments of class comment
	Dictionary<int, Comment^>^comments;
public:
	//		friend FBAccount;
	UserPost();
	UserPost(String^ isPublic, String^ Poster_Mail, String^ text);
	void addTaggedUser(String^ user_email);
	void addReactors(String^ e_mail, String^ typeOfReaction);
	void addReactorsToComment(int id, String^ e_mail, String^ typeOfReaction);
	void addReactorsToReply(int comment_id, int reply_id, String^ e_mail, String^ typeOfReaction);
	void addComment(int comment_id, Comment^ c);
	void addReplayToComment(int comment_id, int replay_id, Reply^ c);

	String^ Getpost_text();
	String^ GetPoster_Mail();
	List<String^>^ GetTaggedPeaple();
	String^ isPostPublic();
	Reactors^ Getreactors();
	String^ getPrivacy();
	Dictionary<int, Comment^>^ Getcomments();
	void DeleteReact( String^ E_mail, String^ Old_Reaction);
	void UpdateReact( String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void DeleteReactComment(int comment_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactComment(int comment_id , String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void DeleteReactReply( int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactReply( int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	bool CheckIfTagged(String^ user_email);
};