// user.h file by: Adhithyaa Arul Murugan Alwar
// This file is a header file for the User class

#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include "post.h"
#include "incoming_post.h"

class User{
public:
	//Default Constructor
	User();
	//Constructor
	User(std::size_t id_, std::string fullName_, std::size_t birthYear_, std::size_t zip_, std::vector<std::size_t> friends_);
	//Functions
	void addFriend(std::size_t id);
	void deleteFriend(std::size_t id);
	void addPost(Post* newPost);
	std::string displayPosts(std::size_t howMany, bool showOnlyPublic);
	//Getters
	std::size_t getID();
	std::string getFullName();
	std::size_t getBirthYear();
	std::size_t getZipCode();
	std::vector<std::size_t> getFriends();
private:
	std::size_t id;
	std::string fullName;
	std::size_t birthYear;
	std::size_t zip;
	std::vector<std::size_t> friends;
	std::vector<Post*> messages;
};

#endif