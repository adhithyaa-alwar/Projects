// post.h file by: Adhithyaa Arul Murugan Alwar
// This file is a header file for the Post class

#ifndef POST_H
#define POST_H
#include <string>

class Post{
public:
	// Constructors
	Post();
	Post(std::size_t messageId_, std::string message_, std::size_t likes_);
	// Functions
	virtual std::string displayPost();
	// Getters
	std::size_t getMessageId();
	std::string getMessage();
	std::size_t getPostLikeCount();

private:
	std::size_t messageId;
	std::string message;
	std::size_t likes;

};

#endif