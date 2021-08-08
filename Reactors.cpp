#include "Reactors.h"



Reactors::Reactors()
{
	totalReactors = gcnew Dictionary<String^, String^>();
	ReactorsCount = gcnew Dictionary<String^, int>();
	ReactorsCount["like"] = 0; 
	ReactorsCount["love"] = 0;
	ReactorsCount["haha"] = 0;
	ReactorsCount["wow"] = 0;
	ReactorsCount["sad"] = 0;
	ReactorsCount["angry"] = 0;
}
void Reactors::addReact(String^ e_mail, String^ typeOfReaction)
{
	totalReactors->Add(e_mail, typeOfReaction);
	if (typeOfReaction == "wow")
	{
		if (ReactorsCount->ContainsKey("wow"))
		{
			ReactorsCount["wow"]++;
		}
		else
		{
			ReactorsCount->Add("wow", 1);
		}
	}
	else if (typeOfReaction == "sad")
	{
		if (ReactorsCount->ContainsKey("sad"))
		{
			ReactorsCount["sad"]++;
		}
		else
		{
			ReactorsCount->Add("sad", 1);
		}
	}
	else if (typeOfReaction == "angry")
	{
		if (ReactorsCount->ContainsKey("angry"))
		{
			ReactorsCount["angry"]++;
		}
		else
		{
			ReactorsCount->Add("angry", 1);
		}
	}
	else if (typeOfReaction == "love")
	{
		if (ReactorsCount->ContainsKey("love"))
		{
			ReactorsCount["love"]++;
		}
		else
		{
			ReactorsCount->Add("love", 1);
		}
	}
	else if (typeOfReaction == "haha")
	{
		if (ReactorsCount->ContainsKey("haha"))
		{
			ReactorsCount["haha"]++;
		}
		else
		{
			ReactorsCount->Add("haha", 1);
		}
	}
	else if (typeOfReaction == "like")
	{
		if (ReactorsCount->ContainsKey("like"))
		{
			ReactorsCount["like"]++;
		}
		else
		{
			ReactorsCount->Add("like", 1);
		}
	}

}

Dictionary<String^, int>^  Reactors::GetReactorsCount()
{
	return ReactorsCount;
}
Dictionary<String^, String^>^  Reactors::GettotalReactors()
{
	return totalReactors;
}
void Reactors::DeleteReact(String^ E_mail,String^ OldReaction)
{
	ReactorsCount[OldReaction]--;
	totalReactors->Remove(E_mail);
}
void Reactors::UpdateReact(String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	ReactorsCount[Old_Reaction]--;
	totalReactors[E_mail] = New_Reaction;
	ReactorsCount[New_Reaction]++;
}