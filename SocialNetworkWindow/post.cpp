// post.cpp file by: Adhithyaa Arul Murugan Alwar
// This file contains the implementation of the functions for the Post class

#include <string>
#include "post.h"

//pre: None
//post: Provides default values for the social network post
Post::Post(){
	messageId = 0;
	message = "";
	likes = 0;	
}

//pre: messageId_ >= 0, likes_ >= 0 and message has to be a string
//post: Constructs a post with the given parameters
Post::Post(std::size_t messageId_, std::string message_, std::size_t likes_){
	messageId = messageId_;
	message = message_;
	likes = likes_;
}

//pre: None
//post: Returns the contents of the post, along with the likes the post received
std::string Post::displayPost(){
	std::string postMessage;
	postMessage = message + '\n' + "Liked by " + std::to_string(likes) + " people" + '\n';
    return postMessage;
}

//pre: None
//post: Returns message ID
std::size_t Post::getMessageId(){
	return messageId;
}

//pre: None
//post: Returns message
std::string Post::getMessage(){
	return message;
}

//pre: None
//post: Returns post like count
std::size_t Post::getPostLikeCount(){
	return likes;
}
