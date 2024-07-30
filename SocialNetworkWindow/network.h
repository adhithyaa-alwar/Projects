// network.h file by: Adhithyaa Arul Murugan Alwar
// This file is a header file for the Network class

#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <string>
#include <fstream>
#include "user.h"
#include "post.h"
#include "incoming_post.h"
#include <iostream>


class Network{
public:
	// Default Constructor
	Network();
	//Destructor
	~Network();
	// Functions
	int readUsers(char* fileName);
	int writeUsers(char *fileName);
	void addUser(User* newUser);
	int addConnection(std::string friend1, std::string friend2);
	int removeConnection(std::string friend1, std::string friend2);
	std::vector<std::size_t> shortestPath(std::size_t from, std::size_t to);
	std::vector<std::size_t> distanceUser(std::size_t from, std::size_t& to, std::size_t distance);
	std::vector<std::size_t> suggestFriends(std::size_t who, std::size_t& score);
	std::vector<std::vector<std::size_t>> groups();

	void addPost(std::size_t ownerId_, std::string message_, std::size_t likes_, bool incoming_, std::size_t author_, bool isPublic_);
	std::string displayPosts(std::string name_, std::size_t howMany_, bool showOnlyPublic_);
	int readPosts(char* filename);

	// Getters
	std::size_t getId(std::string name);
	std::size_t numUsers();
	User* getUser(std::size_t id);
	// Helper Functions
	std::vector<std::size_t> depthFirst(std::size_t source, std::vector<bool>& visited);
private:
	std::vector<User*> users;
	size_t numMessages;
};

#endif