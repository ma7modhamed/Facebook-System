#pragma once
#include"Reply.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
public ref class Comment
{
private:
	int ID;
	String^text;
	String^ commenter_Email;
	Reactors^ react;
	Dictionary<int, Reply^>^replies;
public:
	Comment();
	Comment(int id, String^ text, String^ commenter);
	void addReplay(int id, Reply^ r);
	void addReact(String^ e_mail, String^ typeOfReaction);
	void addReactToReply(int reply_id, String^ e_mail, String^ TypeOfReaction);
	int GetCommentId();
	String^ GetCommentText();
	String^ GetCommenterE_mail();
	Reactors^ GetCommentReactors();
	Dictionary<int, Reply^>^ GetCommentReplies();
	void DeleteReact(String^ E_mail, String^ Old_Reaction);
	void UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void DeleteReactReply( int reply_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactReply( int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
};

