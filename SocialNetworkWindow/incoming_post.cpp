// incoming_post.cpp file by: Adhithyaa Arul Murugan Alwar
// This file contains the implementation of the functions for the Incoming Post class
#include "incoming_post.h"

// Pre: None
// Post: Creates a default incoming post
IncomingPost::IncomingPost(){
	isPublic = false;
}

// Pre: Valid author name, message id, message has values, and valid like count
// Post: Constructs an incoming post with the given values
IncomingPost::IncomingPost(std::size_t messageId_, std::string message_, std::size_t likes_, bool isPublic_, std::string authorName_):Post(messageId_, message_ + '\n' + "from " + authorName_, likes_){
	isPublic = isPublic_;
}

// Pre: None
// Post: Displays post, along with whether its public or private
std::string IncomingPost::displayPost(){
	std::string output;
	if(isPublic){
		output = "Public: " + Post::displayPost();
	}
	else{
		output = "Private: " + Post::displayPost();
	}
	return output;
}