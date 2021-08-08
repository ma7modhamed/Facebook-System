#pragma once
#include"Reactors.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
public ref class Reply//:public Comment
{

	int ID;
	String^ text;
	String^ replier_email;
	Reactors^ react;
	//object of class reactors
public:

	Reply();
	Reply(int id, String^ text, String^ e_mail);
	void addReact(String^ e_mail, String^ typeOfReaction);
	int getReplyId();
	String^ GetReplierE_mail();
	String^ GetReplyText();
	Reactors^ GetReplierReact();
	void DeleteReact(String^ E_mail, String^ Old_Reaction);
	void UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
};

