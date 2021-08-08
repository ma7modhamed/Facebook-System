#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
public ref class Reactors
{
	Dictionary<String^, int>^ ReactorsCount;
	Dictionary<String^, String^>^totalReactors; //key is e_mail and value is the type of reaction
public:
	Reactors();
	void addReact(String^ e_mail, String^ typeOfReaction);
	Dictionary<String^, int>^  GetReactorsCount();
	Dictionary<String^, String^>^  GettotalReactors();
	void DeleteReact(String^ E_mail, String^ Old_Reaction);
	void UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
};

