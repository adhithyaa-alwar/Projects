// user.cpp file by: Adhithyaa Arul Murugan Alwar
// This file contains the implementation of the constructors and functions of the User class
#include "user.h"

// pre: None
// post: Provides default values to user
User::User(){
	id = 0;
	fullName = "";
	birthYear = 2000;
	zip = 10000;
}

// pre: id_ >= 0 and id is unique, fullName_ does not have numbers, birthYear_ is a valid 4 digit year, zip_ is a valid 5 digit zipcode, vector of friends has real ids.
// post: Constructs a new user with a unique id and all the information provided.
User::User(std::size_t id_, std::string fullName_, std::size_t birthYear_, std::size_t zip_, std::vector<std::size_t> friends_){
	id = id_;
	fullName = fullName_;
	birthYear = birthYear_;
	zip = zip_;
	friends = friends_;

}

// pre: None
// post: Returns ID
std::size_t User::getID(){
	return id;
}

// pre: None
// post: Returns full name
std::string User::getFullName(){
	return fullName;
}

// pre: None
// post: Returns birth year
std::size_t User::getBirthYear(){
	return birthYear;
}

// pre: None
// post: Returns zip code
std::size_t User::getZipCode(){
	return zip;
}

// pre: None
// post: Returns list of friends
std::vector<std::size_t> User::getFriends(){
	return friends;
}

// pre: id >= 0
// post: adds id to the friends list of the user as long as valid id is provided and id is not on friends list 
void User::addFriend(std::size_t id){
	for(auto i = friends.begin(); i != friends.end(); i++){
		if(*i == id){
			return;
		}
	}
	friends.push_back(id);
}

// pre: id >= 0
// post: removes id from the friends list of the user as long as valid id is provided and id is on the friends list 
void User::deleteFriend(std::size_t id){
	for(auto i = friends.begin(); i < friends.end(); i++){
		if(*i == id){
			friends.erase(i);
			return;
		}
	}
}

// pre: Valid Post given
// post: Adds a post into the messages vector
void User::addPost(Post* newPost){
	messages.push_back(newPost);
}

// pre: howMany > 0
// post: Returns a string that displays the specified number of public posts
std::string User::displayPosts(std::size_t howMany, bool showOnlyPublic){
	int postsCounted = 0;
	std::string listOfUserPosts;
	if(!showOnlyPublic){
		for(int i = messages.size() - 1; i >= 0; i--){
			if(postsCounted >= howMany){
				break;
			}
			else{
				listOfUserPosts += '\n';
				listOfUserPosts += messages[i]->displayPost();
				listOfUserPosts += '\n';			
			}
			postsCounted++;
		}		
	}
	else{
		for(int i = messages.size() - 1; i >= 0; i--){
			if(postsCounted >= howMany){
				break;
			}
			else{
				std::string tempPost = messages[i]->displayPost().substr(0, 7);
				if(tempPost != "Private"){
					listOfUserPosts += '\n';
					listOfUserPosts += messages[i]->displayPost();
					listOfUserPosts += '\n';
					postsCounted++;	
				}
			}
		}		
	}
	return listOfUserPosts;
}
