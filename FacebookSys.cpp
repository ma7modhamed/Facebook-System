#include "FacebookSys.h"
#include"Comment.h"
#include"Reply.h"
using namespace System::Data::SqlClient;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Media;
FacebookSys::FacebookSys()
{
}
void FacebookSys::logout()
{
	Con->Close();
	AllAccounts->Clear();
	user_email = "";
}

void FacebookSys::load()
{
	
		Con->Open();
	loadAccountsDetails();
	loadFriendship();
	loadRequests();
	loadMyconversations();
	loadConversationUsers();
	loadConversationMessages();
	loadPosts();
	loadComments();
	loadReplays();
	loadTaggedUsers();
	loadReactPosts();
	loadReactComments();
	loadReactReplys();
	
}
void FacebookSys::loadAccountsDetails()
{

	SqlCommand^ com = gcnew SqlCommand("[dbo].[Account]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[0]=username ,reader[1]=password,reader[2]=e_mail,reader[3]=gender,reader[4]=birth_data
		FBAccount^ account = gcnew FBAccount(reader[0]->ToString(), reader[1]->ToString(), reader[2]->ToString(), reader[3]->ToString(), reader[4]->ToString());
		AllAccounts->Add(reader[2]->ToString(), account);

	}

	reader->Close();

}
void FacebookSys::loadFriendship()
{

	SqlCommand^ com = gcnew SqlCommand("[dbo].[Friends]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[0]=first_Email ,reader[1]=second_email,reader[2]=type_of_Relation
		AllAccounts[reader[0]->ToString()]->addFriendOrfollowed(reader[1]->ToString(), reader[2]->ToString());
	}

	reader->Close();

}
void FacebookSys::loadRequests()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[load_Requests]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlParameter^ p1 = gcnew SqlParameter("@User_mail", FacebookSys::user_email);
	com->Parameters->Add(p1);
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[0]=sender ,reader[1]=reciever
		AllAccounts[reader[0]->ToString()]->addRequest(reader[1]->ToString());
	}

	reader->Close();
}
void FacebookSys::loadMyconversations()
{


	SqlCommand^ com = gcnew SqlCommand("[dbo].[get_myConversation]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlParameter^ p1 = gcnew SqlParameter("@User_mail", FacebookSys::user_email);
	com->Parameters->Add(p1);
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{

		Conversation^ oldConversation = gcnew Conversation();
		//reader[0]=id of the conversation
		AllAccounts[FacebookSys::user_email]->addConversation((int)reader[0], oldConversation);
	}
	reader->Close();
}


void FacebookSys::loadConversationUsers()
{

	if (FacebookSys::user_email != "")
	{
		Dictionary<int, Conversation^>^ myConversation = AllAccounts[FacebookSys::user_email]->getmyConversations();
		for each (KeyValuePair<int, Conversation^> var in myConversation)
		{
			SqlCommand^ com = gcnew SqlCommand("[dbo].[Get_List_Users]", Con);
			com->CommandType = CommandType::StoredProcedure;
			SqlParameter^ p1 = gcnew SqlParameter("@id", var.Key);
			com->Parameters->Add(p1);
			SqlDataReader^ reader = com->ExecuteReader();
			
			while (reader->Read())
			{
				//var.key=id of the conversation  , reader[0]=user_email that belong to that conversation
				AllAccounts[FacebookSys::user_email]->addConversationUsers(var.Key, reader[0]->ToString());
			}
			reader->Close();
		}


	}
}
void FacebookSys::loadConversationMessages()
{
	if (AllAccounts->ContainsKey(user_email))
	{
		Dictionary<int, Conversation^>^ myConversation = AllAccounts[FacebookSys::user_email]->getmyConversations();
		for each (KeyValuePair<int, Conversation^> var in myConversation)
		{
			SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_Messages]", Con);
			com->CommandType = CommandType::StoredProcedure;
			SqlParameter^ p1 = gcnew SqlParameter("@id", var.Key);
			com->Parameters->Add(p1);
			SqlDataReader^ reader = com->ExecuteReader();
			while (reader->Read())
			{
				//var.key=id of the conversation ,reader[0]=e_mail of message sender ,reader[1]=message text
				AllAccounts[FacebookSys::user_email]->addConversationMessages(var.Key, reader[0]->ToString(), reader[1]->ToString());
			}
			reader->Close();
		}

	}
}
void FacebookSys::loadPosts()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_Posts]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[1]=privacy ,reader[2]=user_email who made the post ,reader[3]=post_Text
		UserPost^ post = gcnew UserPost(reader[1]->ToString(), reader[2]->ToString(), reader[3]->ToString());
		AllAccounts[reader[2]->ToString()]->addPost((int)reader[0], post);
		if (reader[2]->ToString() == FacebookSys::user_email)
		{
			//reader[0]=id of the post
			AllAccounts[FacebookSys::user_email]->addtoNewsfeed((int)reader[0], FacebookSys::user_email);
		}
		else
		{
			bool IsFriend = AllAccounts[FacebookSys::user_email]->checkIfFriend(reader[2]->ToString());
			if (IsFriend)
			{
				AllAccounts[FacebookSys::user_email]->addtoNewsfeed((int)reader[0], reader[2]->ToString());
			}
			else if (AllAccounts[FacebookSys::user_email]->checkIfFollowing(reader[2]->ToString()))
			{
				if (reader[1]->ToString() == "Public")
				{
					AllAccounts[FacebookSys::user_email]->addtoNewsfeed((int)reader[0], reader[2]->ToString());
				}
			}

		}

	}
	reader->Close();
}

void FacebookSys::loadComments()
{

	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_Comments]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[0]=id of the comment,reader[3]=comment_text,reader[1]=e_mail who made the text
		Comment^ oldComment = gcnew Comment((int)reader[0], reader[3]->ToString(), reader[1]->ToString());
		//reader[4]=user_email who made the post ,reader[2]
		AllAccounts[reader[4]->ToString()]->addCommentToPost((int)reader[2], (int)reader[0], oldComment);
	}
	reader->Close();
}
void FacebookSys::loadReplays()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_Replies]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[0]=id of the reply ,reader[2]=reply_text, reader[1]=user_email who made the reply
		Reply^ reply = gcnew Reply((int)reader[0], reader[2]->ToString(), reader[1]->ToString());
		//reader[5]=e_mail who made the post , reader[4]=post_id, reader[3]=comment_id
		AllAccounts[reader[5]->ToString()]->addReplyToPost((int)reader[4], (int)reader[3], (int)reader[0], reply);
	}
	reader->Close();
}

void FacebookSys::loadTaggedUsers()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_Tagged]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[2]=user_email who made the post, reader[0]=post_id, reader[1]=user_email that has been tagged
		AllAccounts[reader[2]->ToString()]->addTaggedUserToPost((int)reader[0], reader[1]->ToString());
		
	}
	reader->Close();
}
void FacebookSys::loadReactPosts()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_React_Posts]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[3]=user_email who made the post ,reader[1]=post_id, reader[0]=user_email who reacted to the post 
		//reader[2]=type of reaction
		AllAccounts[reader[3]->ToString()]->addReactToPost((int)reader[1], reader[0]->ToString(), reader[2]->ToString());
	}
	reader->Close();
}
void FacebookSys::loadReactComments()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_React_Comment]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[4]=user_email who made the post ,reader[3]=post_id,reader[0]=comment_id, reader[1]=user_email who reacted to the post 
		//reader[2]=type of reaction
		AllAccounts[reader[4]->ToString()]->addReactToComment((int)reader[3], (int)reader[0], reader[1]->ToString(), reader[2]->ToString());
	}
	reader->Close();
}
void FacebookSys::loadReactReplys()
{
	SqlCommand^ com = gcnew SqlCommand("[dbo].[Load_React_Reply]", Con);
	com->CommandType = CommandType::StoredProcedure;
	SqlDataReader^ reader = com->ExecuteReader();
	while (reader->Read())
	{
		//reader[5]=user_email who made the post ,reader[4]=post_id,reader[3]=comment_id,reader[0]=reply_id, reader[1]=user_email who reacted to the post 
		//reader[2]=type of reaction
		AllAccounts[reader[5]->ToString()]->addReactToReply((int)reader[4], (int)reader[3], (int)reader[0], reader[1]->ToString(), reader[2]->ToString());
	}
	reader->Close();
}

void FacebookSys::Sign_up(String^ Name, String^ Password, String^ E_mail, String^ Gender, String^ Birth_date)
{
	Con->Open();
	SqlCommand^ com1 = gcnew SqlCommand("[dbo].[Check_Register]", Con);
	com1->CommandType = CommandType::StoredProcedure;
	SqlParameter^ p1 = gcnew SqlParameter("@Email", E_mail);
	com1->Parameters->Add(p1);
	if ((int)com1->ExecuteScalar() == 0)
	{
		SqlCommand^ com2 = gcnew SqlCommand("insert into [FaceBook User] Values('" + Name + "','" + Password + "','" + E_mail + "','" + Gender + "','" + Birth_date + "')", Con);
		com2->CommandType = CommandType::Text;
		com2->ExecuteNonQuery();
	}
	else
		MessageBox::Show("E-Mail is already used");
	
	Con->Close();
}
int FacebookSys::Makeing_Conversation()
{
	
	SqlCommand^ com1 = gcnew SqlCommand("insert into Conversation Values('" + FacebookSys::user_email + "')", Con);
	com1->CommandType = CommandType::Text;
	com1->ExecuteNonQuery();
	SqlCommand^ com2 = gcnew SqlCommand("[dbo].[return_ID]", Con);
	com2->CommandType = CommandType::StoredProcedure;
	SqlParameter^ p1 = gcnew SqlParameter("@email",FacebookSys::user_email);
	com2->Parameters->Add(p1);
	int Conversation_ID = (int)com2->ExecuteScalar();
	return Conversation_ID;
}
void FacebookSys::Make_Messages(String^Message_Text, int conversation_id)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Message Values('" + Message_Text + "','" + FacebookSys::user_email + "','" + conversation_id + "')", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();

	

}
void FacebookSys::UsersConversations(String^Email, int conversation_ID)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Users_Conversation Values('" + conversation_ID + "','" + Email + "')", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	
}
int FacebookSys::addPost(String^ option, String^ Post_Text)
{
	
	SqlCommand^ com1 = gcnew SqlCommand("insert into [FaceBook Posts] values('" + option + "','" + FacebookSys::user_email + "','" + Post_Text + "')", Con);
	com1->CommandType = CommandType::Text;  // why we have to specify the query type
	com1->ExecuteNonQuery();  // apply the command 
	SqlCommand^ com2 = gcnew SqlCommand("select Max(Post_ID) from [FaceBook Posts] where Email_FK='" + FacebookSys::user_email + "' ", Con);
	com2->CommandType = CommandType::Text;
	int post_id = (int)com2->ExecuteScalar();
	
	return post_id;
}
void FacebookSys::Like_Post(int post_fk, String^ reaction_type)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Like_Post (Liker_Email,Post_FK ,type_react) values('" + FacebookSys::user_email + "' ,'" + post_fk + "' ,'" + reaction_type + "');", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	
}
void  FacebookSys::insetFriendshiptDB(String^ reciever, String^ state)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Friendship (Email_FK , Second_Email , State) values('" + FacebookSys::user_email + "','" + reciever + "','" + state + "')", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	
}
int FacebookSys::insertCommentDB(String^ text, int post_fc)
{
	
	SqlCommand^ qwe = gcnew SqlCommand("INSERT INTO comment VALUES('" + FacebookSys::user_email + "','" + post_fc + "','" + text + "')", Con);
	qwe->CommandType = CommandType::Text;
	qwe->ExecuteNonQuery();
	SqlCommand^ com2 = gcnew SqlCommand("select Max(commend_ID) from comment where Email_FK='" + FacebookSys::user_email + "'", Con);
	com2->CommandType = CommandType::Text;
	int comment_id = (int)com2->ExecuteScalar();
	
	return comment_id;
}
void FacebookSys::like_comment(int comm_fc, String^ type_react)
{
	
	SqlCommand^ qwe = gcnew SqlCommand("INSERT INTO Like_Comment VALUES('" + comm_fc + "','" + FacebookSys::user_email + "','" + type_react + "')", Con);
	qwe->CommandType = CommandType::Text;
	qwe->ExecuteNonQuery();
	
}
void FacebookSys::request(String^ reciever_email)
{
	
	SqlCommand^ qwe = gcnew SqlCommand("INSERT INTO Request VALUES('" + FacebookSys::user_email + "','" + reciever_email + "')", Con);
	qwe->CommandType = CommandType::Text;
	qwe->ExecuteNonQuery();

	
}
void FacebookSys::Post_taggedUser(int Post_Fk, String^ email)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Post_tagged_Users values( '" + Post_Fk + "','" + email + "');", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	
}
int FacebookSys::make_Reply(int Com_Fk, String^ text, String^ email_Fk)
{
	
	SqlCommand^ com = gcnew SqlCommand("insert into Reply values( '" + Com_Fk + "', '" + text + "', '" + email_Fk + "')", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	SqlCommand^ com2 = gcnew SqlCommand("select Max(replay_id) from Reply where Email_FK='" + FacebookSys::user_email + "'", Con);
	com2->CommandType = CommandType::Text;
	int Reply_id = (int)com2->ExecuteScalar();
	
	return Reply_id;
}
void FacebookSys::like_Reply(int reply_Fk, String^ type_react) {
	
	SqlCommand^ com = gcnew SqlCommand("insert into Like_Reply values('" + reply_Fk + "', '" + FacebookSys::user_email + "','" + type_react + "' );", Con);
	com->CommandType = CommandType::Text;
	com->ExecuteNonQuery();
	
}
String^ FacebookSys::Log_in(String^ Mail, String^password)
{
	Con->Open();
	SqlCommand^cmd = gcnew SqlCommand("[dbo].[Check_Login]", Con);
		cmd->CommandType = CommandType::StoredProcedure;
		SqlParameter ^email = gcnew SqlParameter("@Email", Mail);
		SqlParameter ^pass = gcnew SqlParameter("@password", password);
		cmd->Parameters->Add(email);
		cmd->Parameters->Add(pass);
		SqlDataReader^ reader = cmd->ExecuteReader();
		String^ e_mail="";
		while (reader->Read())
		{
			e_mail = reader[0]->ToString();
		}
	Con->Close();
	return e_mail;
}
void FacebookSys::DeleteReactPost(int post_id)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[delete_likePost]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@post_id", post_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->ExecuteNonQuery();
}
void FacebookSys::UpdateReactPost(int post_id, String^ New_Reaction)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[update_likePost]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@post_id", post_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	SqlParameter ^Reaction = gcnew SqlParameter("@type_react", New_Reaction);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->Parameters->Add(Reaction);
	cmd->ExecuteNonQuery();
}
void FacebookSys::DeleteReactComment(int comment_id)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[delete_LikeComment]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@comment_id", comment_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->ExecuteNonQuery();
}
void FacebookSys::UpdateReactComment(int comment_id, String^ New_Reaction)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[update_likeComment]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@comment_id", comment_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	SqlParameter ^Reaction = gcnew SqlParameter("@type_react", New_Reaction);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->Parameters->Add(Reaction);
	cmd->ExecuteNonQuery();
}
void FacebookSys::DeleteReactReply(int reply_id)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[delete_LikeReply]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@Reply_id", reply_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->ExecuteNonQuery();
}
void FacebookSys::UpdateReactReply(int reply_id, String^ New_Reaction)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[update_likeReply]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^id = gcnew SqlParameter("@Reply_id", reply_id);
	SqlParameter ^e_mail = gcnew SqlParameter("@mail", FacebookSys::user_email);
	SqlParameter ^Reaction = gcnew SqlParameter("@type_react", New_Reaction);
	cmd->Parameters->Add(id);
	cmd->Parameters->Add(e_mail);
	cmd->Parameters->Add(Reaction);
	cmd->ExecuteNonQuery();
}
List<String^>^ FacebookSys::SearchAccountsinDB(String^ user)
{
	List<String^>^ foundAccounts = gcnew List<String^>();
	SqlCommand^ cmd = gcnew SqlCommand("[Search_Emails]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^p1= gcnew SqlParameter("@username", user);
	cmd->Parameters->Add(p1);
	SqlDataReader^ reader = cmd->ExecuteReader();
	
	while (reader->Read())
	{
		foundAccounts->Add(reader[0]->ToString());
	}
	reader->Close();
	return foundAccounts;
}
void FacebookSys::DeleteRequest(String^ sender)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[Delete_Request]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^first = gcnew SqlParameter("@first_email", sender);
	SqlParameter ^second = gcnew SqlParameter("@second_email", FacebookSys::user_email);
	cmd->Parameters->Add(first);
	cmd->Parameters->Add(second);
	cmd->ExecuteNonQuery();
}

void FacebookSys::Delete_Friendship(String ^ second_email)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[delete_Friend]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^ sender = gcnew SqlParameter("@sender", FacebookSys::user_email);
	SqlParameter ^reciever = gcnew SqlParameter("@reciever", second_email);
	cmd->Parameters->Add(sender);
	cmd->Parameters->Add(reciever);
	cmd->ExecuteNonQuery();
}
void FacebookSys::Unfollow(String ^ second_email)
{
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[unfollowed]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^ sender = gcnew SqlParameter("@first", FacebookSys::user_email);
	SqlParameter ^reciever = gcnew SqlParameter("@second", second_email);
	cmd->Parameters->Add(sender);
	cmd->Parameters->Add(reciever);
	cmd->ExecuteNonQuery();
}
List<String^>^ FacebookSys::SearchFriendsDB(String^ name,String^ email)
{
	List<String^>^ accounts = gcnew List<String^> ();
	SqlCommand^ cmd = gcnew SqlCommand("[dbo].[search_friend]", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter ^ Name = gcnew SqlParameter("@userName", name);
	SqlParameter ^ mail = gcnew SqlParameter("@Email", email);
	cmd->Parameters->Add(Name);
	cmd->Parameters->Add(mail);
	SqlDataReader^ reader = cmd->ExecuteReader();
	while (reader->Read())
	{
		accounts->Add(reader[0]->ToString());
	}
	reader->Close();
	return accounts;
}
void FacebookSys::AddTaggedFriendtoPost(int pID, String^mail)
{
	SqlCommand^ cmd = gcnew SqlCommand("tagged", Con);
	cmd->CommandType = CommandType::StoredProcedure;
	SqlParameter^ po_id = gcnew SqlParameter("@post_fk", pID);
	SqlParameter^ mil = gcnew SqlParameter("@email", mail);
	cmd->Parameters->Add(po_id);
	cmd->Parameters->Add(mil);
	cmd->ExecuteNonQuery();

	
}
void FacebookSys::EditAccountInDB(String^name, String^password, String^gender, String^birthdate)
{
		SqlCommand^ cmd = gcnew SqlCommand("[dbo].[Change]", Con);
		cmd->CommandType = CommandType::StoredProcedure;
		SqlParameter^ N = gcnew SqlParameter("@UserName", name);
		 SqlParameter^ P = gcnew SqlParameter("@Password", password);
		 SqlParameter^ M = gcnew SqlParameter("@Email", user_email);

		 SqlParameter^ G = gcnew SqlParameter("@Gender", gender);
		 SqlParameter^ B = gcnew SqlParameter("@Birthdate", birthdate);
		 cmd->Parameters->Add(N);
		 cmd->Parameters->Add(P);
		 cmd->Parameters->Add(M);
		 cmd->Parameters->Add(G);
		 cmd->Parameters->Add(B);
		 cmd->ExecuteNonQuery();


		 
		
}