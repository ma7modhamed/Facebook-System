#pragma once
#include"FBAccount.h"
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
using namespace System::Data::SqlClient;

ref class FacebookSys
{
public:
	static String^ user_email = "";
	static Dictionary<String^, FBAccount^>^AllAccounts = gcnew Dictionary<String^, FBAccount^>();
	
	
	static String^ hahaimage = System::IO::Directory::GetCurrentDirectory() +L"\\Facbook Matrial\\Constant Reacts\\hahaC.PNG";
	static String^ likeimage = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\likeC.PNG";
	static String^ loveimage = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\loveC.PNG";
	static String^ wowimage = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\wowC.PNG";
	static String^ sadimage = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\sadC.PNG";
	static String^ angryimage = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\angryC.PNG";
	static String^ noLike_Image = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\Constant Reacts\\Like-512.PNG";
	static String^ femaleicon_image = System::IO::Directory::GetCurrentDirectory() + L"\\Facbook Matrial\\UserFemaleIcon.png";
	static Dictionary<String^, String^>^reactionsImagesPath = gcnew Dictionary<String^, String^>();
	
	static SqlConnection^ Con = gcnew SqlConnection("Data Source=ENG-MAHMOUD\\MAHMOUD_DEIF;Initial Catalog=Facebook Management System;Integrated Security=True");
	static void load();
	static void loadAccountsDetails();
	static void loadFriendship();
	static void loadRequests();
	static void loadMyconversations();
	static void loadConversationUsers();
	static void loadConversationMessages();
	static void loadComments();
	static void loadReplays();
	static void loadPosts();
	static void loadTaggedUsers();
	static void loadReactPosts();
	static void loadReactComments();
	static void loadReactReplys();
	static void logout();
	static String^ Log_in(String^, String^);
	static void Sign_up(String^, String^, String^, String^, String^);
	static int Makeing_Conversation();
	static void Make_Messages(String^, int);
	static void UsersConversations(String^, int);
	static int addPost(String^, String^);
	static void Like_Post(int, String^);
	static int insertCommentDB(String^, int);
	static void like_comment(int, String^);
	static void insetFriendshiptDB(String^ reciever, String^ state);
	static void request(String^);
	static void Post_taggedUser(int, String^);
	static int make_Reply(int, String^, String^);
	static void like_Reply(int,  String^);
	static void DeleteReactPost(int post_id);
	static void UpdateReactPost(int post_id,String^ New_Reaction);
	static void DeleteReactComment(int comment_id);
	static void UpdateReactComment(int comment_id,  String^ New_Reaction);
	static void DeleteReactReply(int reply_id);
	static void UpdateReactReply(int reply_id, String^ New_Reaction);
	static List<String^>^ SearchAccountsinDB(String^);
	static void DeleteRequest(String^ sender);
	static void Delete_Friendship(String ^ second_email);
	static List<String^>^ SearchFriendsDB(String^,String^);
	static void AddTaggedFriendtoPost(int pID, String^mail);
	static void EditAccountInDB(String^name, String^password, String^gender, String^birthdate);
	void Unfollow(String ^ second_email);
	FacebookSys();
};

