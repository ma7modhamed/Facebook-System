#pragma once
#include"UserPost.h"
#include"Conversation.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
ref class FBAccount
{

	String^ AccountName;
	String^Mail;
	String^Password;
	String^Gender;
	String^BirthDate;
	Dictionary<int, UserPost^>^ myPosts;//key= id of post from database
	Dictionary<int, String^>^ newsFeed;//key= id of post from database ,value=e_mail who made the post
	List<String^>^friends;
	List<String^>^  followed_users;
	//	Dictionary<int, List<String^>^> Conversations;

	//List<List<String^>^>^Converstions;
	Dictionary<int, Conversation^>^ myConversations;//key = id of conversation from database
	List<String^>^requests;//friend that has sent request to me

	List<String^>^requestedFriends;


public:
	FBAccount();
	FBAccount(String^ accountName, String^ Password, String^ E_mail, String^ Gender, String^ Birth_Date);
	void addFriendOrfollowed(String^ reciever, String^ state);
	void addRequest(String^ Reciever);
	void addConversation(int id, Conversation^ myconversation);
	Dictionary<int, Conversation^>^ getmyConversations();
	void addPost(int id, UserPost^ post);
	void addtoNewsfeed(int id, String^ User_email);
	void addConversationUsers(int id, String^ UserEmail);
	void addConversationMessages(int id, String^ UserEmail, String^ text);
	bool checkIfFriend(String^ user_email);
	bool checkIfFollowing(String^ user_email);
	void addCommentToPost(int post_id, int comment_id, Comment^ c);
	void addReplyToPost(int post_id, int comment_id, int replay_id, Reply^ c);
	void addTaggedUserToPost(int post_id, String^ E_mail);
	UserPost^ getMypost(int post_id);
	void addReactToPost(int post_id, String^ E_mail, String^ typeOfReaction);
	void addReactToComment(int post_id, int comment_id, String^ E_mail, String^ typeOfReaction);
	void addReactToReply(int post_id, int comment_id, int reply_id, String^ E_mail, String^ typeOfReaction);
	String^ GetAccountMail();
	String^ GetAccountUserName();
	String^ GetAccountPassword();
	String^ GetAccountGender();
	String^ GetAccountBirthDate();
	Dictionary<int, UserPost^>^ GetmyPosts();
	Dictionary<int, String^>^ GetnewsFeed();
	List<String^>^ Getfriends();
	List<String^>^  Getfollowed_users();
	Dictionary<int, Conversation^>^ GetmyConversations();
	List<String^>^Getrequests();
	List<String^>^GetrequestedFriends();
	void DeleteReactPost(int post_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactPost(int post_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void DeleteReactComment(int post_id,int comment_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactComment(int post_id ,int comment_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void DeleteReactReply(int post,int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction);
	void UpdateReactReply(int post,int comment_id, int reply_id, String^ E_mail, String^ Old_Reaction, String^ New_Reaction);
	void Delete_Request(String^ sender);
	void Delete_FriendShip(String^ second_email);
	void Delete_Following(String^Second_email);
	List<String^>^ operator&(FBAccount^ const& account);
	Dictionary<int, String^>^ operator+(FBAccount^ const& account);
	void EditMyAccount(String^ name, String^password, String^gender, String^birthdate);
	~FBAccount();




};

