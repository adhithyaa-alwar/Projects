// incoming_post.h file by: Adhithyaa Arul Murugan Alwar
// This file is a header file for the Incoming Post class

#ifndef INCOMINGPOST_H
#define INCOMINGPOST_H
#include <vector>
#include "post.h"


class IncomingPost : public Post{
public:
	IncomingPost();
	IncomingPost(std::size_t messageId_, std::string message_, std::size_t likes_, bool isPublic_, std::string authorName_);
	std::string displayPost();
private:
	bool isPublic;
};

#endif