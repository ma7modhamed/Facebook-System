#include "FBAccount.h"
#include"FacebookSys.h"



FBAccount::FBAccount()
{
	AccountName = "UNKNOWN";
	Mail = "UNKNOWN";
	Password = "UNKNOWN";
	Gender = "UNKNOWN";
	BirthDate = "UNKNOWN";
	//Converstions = gcnew List<List<String^>^>();
	myConversations = gcnew Dictionary<int, Conversation^>();
	myPosts = gcnew Dictionary<int, UserPost^>();
	newsFeed = gcnew Dictionary<int, String^>();
	friends = gcnew List<String^>();
	followed_users = gcnew List<String^>();
	requests = gcnew List<String^>();
	requestedFriends = gcnew List<String^>();
}
FBAccount::FBAccount(String^ accountName, String^ Password, String^ E_mail, String^ Gender, String^ Birth_Date)
{
	this->AccountName = accountName;
	this->Password = Password;
	this->Mail = E_mail;
	this->Gender = Gender;
	this->BirthDate = Birth_Date;
	//Converstions = gcnew List<List<String^>^>();
	myConversations = gcnew Dictionary<int, Conversation^>();
	myPosts = gcnew Dictionary<int, UserPost^>();
	newsFeed = gcnew Dictionary<int, String^>();
	friends = gcnew List<String^>();
	followed_users = gcnew List<String^>();
	requests = gcnew List<String^>();
	requestedFriends = gcnew List<String^>();

}
void FBAccount::addFriendOrfollowed(String^ reciever, String^ state)
{

	if (state == "Follower")
	{
		followed_users->Add(reciever);
		for each(KeyValuePair<int, UserPost^> post in FacebookSys::AllAccounts[reciever]->myPosts)
		{
			if (!FacebookSys::AllAccounts[this->Mail]->newsFeed->ContainsKey(post.Key))
			{
				if(FacebookSys::AllAccounts[post.Value->GetPoster_Mail()]->myPosts[post.Key]->isPostPublic()=="Public")
				FacebookSys::AllAccounts[this->Mail]->newsFeed->Add(post.Key, reciever);
			}
		}
	}
	else if (state = "Friend")
	{
		friends->Add(reciever);

		FacebookSys::AllAccounts[reciever]->friends->Add(this->Mail);
		
		for each(KeyValuePair<int, UserPost^> post in FacebookSys::AllAccounts[reciever]->myPosts)
		{
			if (!FacebookSys::AllAccounts[this->Mail]->newsFeed->ContainsKey(post.Key))
			{
				FacebookSys::AllAccounts[this->Mail]->newsFeed->Add(post.Key, reciever);
			}
		}
	}

}
void FBAccount::addRequest(String^ reciever)
{
	if (this->Mail == FacebookSys::user_email)  // I sent request 
	{
		requestedFriends->Add(reciever);
	}
	else if (reciever == FacebookSys::user_email)   // I get a request 
	{
		FacebookSys::AllAccounts[reciever]->requests->Add(this->Mail);  // I can use it cuz I`m in the class however it`s private 
	}

}
void FBAccount::addConversation(int id, Conversation^ myconversation)
{
	myConversations->Add(id, myconversation);
}
void  FBAccount::addConversationUsers(int id, String^ UserEmail)
{
	myConversations[id]->addUsers(UserEmail);
}
Dictionary<int, Conversation^>^ FBAccount::getmyConversations()
{
	return myConversations;
}
void FBAccount::addConversationMessages(int id, String^ UserEmail, String^ text)
{
	myConversations[id]->AddMessage(UserEmail, text);
}
void FBAccount::addPost(int id, UserPost^ post)
{
	myPosts->Add(id, post);
}
bool FBAccount::checkIfFriend(String^ user_email)
{
	return friends->Contains(user_email);
}
bool FBAccount::checkIfFollowing(String^ user_email)
{
	return followed_users->Contains(user_email);
}
void FBAccount::addtoNewsfeed(int id, String^ User_email)
{
	newsFeed->Add(id, User_email);
}
void FBAccount::addCommentToPost(int post_id, int comment_id, Comment^ c)
{
	myPosts[post_id]->addComment(comment_id, c);
}
void FBAccount::addReplyToPost(int post_id, int comment_id, int replay_id, Reply^ r)
{
	myPosts[post_id]->addReplayToComment(comment_id, replay_id, r);
}
void FBAccount::addTaggedUserToPost(int id, String^ E_mail)
{
	myPosts[id]->addTaggedUser(E_mail);
	FacebookSys::AllAccounts[E_mail]->myPosts->Add(id, myPosts[id]);
}
UserPost^ FBAccount::getMypost(int id)
{
	return myPosts[id];
}
void FBAccount::addReactToPost(int post_id, String^ E_mail, String^ typeOfReaction)
{
	myPosts[post_id]->addReactors(E_mail, typeOfReaction);
}
void FBAccount::addReactToComment(int post_id, int comment_id, String^ E_mail, String^ typeOfReaction)
{
	myPosts[post_id]->addReactorsToComment(comment_id, E_mail, typeOfReaction);
}
void FBAccount::addReactToReply(int post_id, int comment_id, int reply_id, String^ E_mail, String^ typeOfReaction)
{
	myPosts[post_id]->addReactorsToReply(comment_id, reply_id, E_mail, typeOfReaction);
}
String^ FBAccount::GetAccountMail()
{
	return Mail;
}
String^ FBAccount::GetAccountUserName()
{
	return AccountName;
}
String^ FBAccount::GetAccountPassword()
{
	return Password;
}
String^ FBAccount::GetAccountGender()
{
	return Gender;
}
String^ FBAccount::GetAccountBirthDate()
{
	return BirthDate;
}
Dictionary<int, UserPost^>^ FBAccount::GetmyPosts()
{
	return myPosts;
}
Dictionary<int, String^>^ FBAccount::GetnewsFeed()
{
	return newsFeed;
}
List<String^>^ FBAccount::Getfriends()
{
	return friends;
}
List<String^>^  FBAccount::Getfollowed_users()
{
	return followed_users;
}
Dictionary<int, Conversation^>^ FBAccount::GetmyConversations()
{
	return myConversations;
}
List<String^>^ FBAccount::Getrequests()
{
	return requests;
}
List<String^>^ FBAccount::GetrequestedFriends()
{
	return requestedFriends;
}
void FBAccount::DeleteReactPost(int post_id, String^ E_mail, String^ Old_Reaction)
{
	myPosts[post_id]->DeleteReact(E_mail, Old_Reaction);
}
void FBAccount::UpdateReactPost(int post_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	myPosts[post_id]->UpdateReact(E_mail, Old_Reaction, New_Reaction);
}
void FBAccount::DeleteReactComment(int post_id, int comment_id, String^ E_mail, String^ Old_Reaction)
{
	myPosts[post_id]->DeleteReactComment(comment_id, E_mail, Old_Reaction);
}
void FBAccount::UpdateReactComment(int post_id, int comment_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	myPosts[post_id]->UpdateReactComment(comment_id, E_mail, Old_Reaction,New_Reaction);
}
void FBAccount::DeleteReactReply(int post_id, int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction)
{
	myPosts[post_id]->DeleteReactReply(comment_id, reply_id, E_mail, Old_Reaction);
}
void FBAccount::UpdateReactReply(int post_id, int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction)
{
	myPosts[post_id]->UpdateReactReply(comment_id, reply_id, E_mail, Old_Reaction, New_Reaction);
}
void FBAccount::Delete_Request(String^ sender)
{
	requests->Remove(sender);
	FacebookSys::AllAccounts[sender]->requestedFriends->Remove(this->Mail);
}
void FBAccount::Delete_FriendShip(String^ second_email)
{
	friends->Remove(second_email);
	List<int>^ Removed_Posts = gcnew List<int>();
	for each (KeyValuePair<int, String^> post in newsFeed)
	{
		if (post.Value == second_email)
		{
			if (!followed_users->Contains(second_email))
			{
				Removed_Posts->Add(post.Key);
			}
			else if (followed_users->Contains(second_email))
			{
				if (FacebookSys::AllAccounts[second_email]->myPosts[post.Key]->isPostPublic() == "Friends")
				{
					Removed_Posts->Add(post.Key);
				}
			}
			else
			{
				Removed_Posts->Add(post.Key);
			}
		}
	}
		for each (int index in Removed_Posts)
		{
			newsFeed->Remove(index);
		}
		Removed_Posts->Clear();
		for each  (KeyValuePair<int, UserPost^> post in myPosts)
		{
			if (post.Value->GetPoster_Mail() == second_email)
			{
				Removed_Posts->Add(post.Key);
			}
		}
		for each (int index in Removed_Posts)
		{
			myPosts->Remove(index);
		}
		Removed_Posts->Clear();
	
}
void FBAccount::Delete_Following(String^Second_email)
{
	for each  (KeyValuePair<int, String^> post in newsFeed)
	{
		if (post.Value == Second_email)
		{
			myPosts->Remove(post.Key);
		}
	}
}
List<String^>^ FBAccount::operator&(FBAccount^ const& account)
{
	List<String^>^ mutualFriend = gcnew List<String^>();
	for each (String^ MyFriend  in friends)
	{
		if (account->friends->Contains(MyFriend))
		{
			mutualFriend->Add(MyFriend);
		}
	}
	return mutualFriend;
}
Dictionary<int, String^>^ FBAccount::operator+(FBAccount^ const& account)
{
	Dictionary<int, String^>^ FriendShip_Posts = gcnew Dictionary<int, String^>();
	for each (KeyValuePair <int, UserPost^> post in myPosts)
	{
		if (post.Value->GetPoster_Mail() == account->Mail)
		{
			if (post.Value->CheckIfTagged(this->Mail))
			{
				FriendShip_Posts->Add(post.Key, account->Mail);
			}
		}
		if (post.Value->GetPoster_Mail() == this->Mail)
		{
			if (post.Value->CheckIfTagged(account->Mail))
			{
				FriendShip_Posts->Add(post.Key, this->Mail);
			}
		}
	}
	return FriendShip_Posts;
}
void FBAccount::EditMyAccount(String^ name, String^password, String^gender, String^birthdate)
{
	this->AccountName = name;
	this->Password = password;
	this->Gender = gender;
	this->BirthDate = birthdate;
}
FBAccount::~FBAccount()
{

}

