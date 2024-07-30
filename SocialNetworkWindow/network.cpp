// network.cpp file by: Adhithyaa Arul Murugan Alwar
// This file contains the implementation of the constructors and functions of the Network class

#include <cctype>
#include <queue>
#include "user.h"
#include "network.h"
#include "post.h"
#include "incoming_post.h"
#include <iterator>
#include <algorithm>

// pre: N/A 
// post: Users vector initialized by default
Network::Network(){
	numMessages = 0;
	// Nothing to be done here as vector is initialized already
}

// pre: N/A
// post: The vector users will be cleared of memory
Network::~Network(){
	users.clear(); // A vector function used to clear all memory of the users
}

// pre: Valid file given, user information given in correct format
// post: Reads user information from file into network if information given in correct format
int Network::readUsers(char* fileName){
	if(!users.empty()){
		return -1;
	}
	std::ifstream userReading(fileName);
	std::ifstream testIfEmpty(fileName);
	std::size_t id;
	std::string name;
	std::size_t year;
	std::size_t zip;
	std::vector<std::size_t> listOfFriends;
	int lineTracker = 1;	
	std::string userInfo;
	// If there is nothing to read, returns -1
	if(!std::getline(testIfEmpty, userInfo)){
		return -1;
	}
	testIfEmpty.close();
	while(std::getline(userReading, userInfo)){
		// If-statement to check whether the number of users is a number
		if(lineTracker == 1){
			for(int i = 0; i < userInfo.size(); i++){
				if(isalpha(userInfo[i])){
					return -1;
				}
			}
			if(std::stoi(userInfo) == 0){ // Returns -1 if there are no users
				return -1;
			}
		}
		else if(lineTracker % 5 == 2){
			for(int i = 0; i < userInfo.size(); i++){
				if(isalpha(userInfo[i])){
					return -1;
				}
			}
			id = std::stoi(userInfo);
			userReading.ignore(256, '\t'); // This line ignores the string until tab occurs 
		}
		else if(lineTracker % 5 == 3){
			for(int i = 0; i < userInfo.size(); i++){
				if(isdigit(userInfo[i])){
					return -1;
				}				
			}
			name = userInfo;
			userReading.ignore(256, '\t'); 
		}
		else if(lineTracker % 5 == 4){
			for(int i = 0; i < userInfo.size(); i++){
				if(isalpha(userInfo[i])){
					return -1;
				}				
			}
			year = std::stoi(userInfo);
			userReading.ignore(256, '\t');
		}
		else if(lineTracker % 5 == 0){
			for(int i = 0; i < userInfo.size(); i++){
				if(isalpha(userInfo[i])){
					return -1;
				}				
			}
			zip = std::stoi(userInfo);
			userReading.ignore(256, '\t');
		}
		else if(lineTracker % 5 == 1){
			for(int i = 0; i < userInfo.size(); i++){
				if(isalpha(userInfo[i])){
					return -1;
				}
            }
				std::string variable;
            for(int i = 0; i < userInfo.size(); i++){

                if(userInfo[i] == ' '){
                    std::size_t friendIds;
                    friendIds = std::stoi(variable);
                    listOfFriends.push_back(friendIds);
                    variable = "";

                }
                else{
                    variable += userInfo[i];
                }
            }
			User* temporaryUser = new User(id, name, year, zip, listOfFriends);
			users.push_back(temporaryUser);
			listOfFriends.clear();
		}
		lineTracker++; 
	}
	userReading.close();
	return 0;
}

// pre: Valid file given
// post: Inserts all of the user information into the filename given, unless network has no users
int Network::writeUsers(char *fileName){
	if(users.empty()){return -1;} // If users vector is empty, then there is no point in creating a file 
	std::ofstream userWriting(fileName);
	userWriting << users.size() << std::endl;
	for(int i = 0; i < users.size(); i++){
		userWriting << users[i] -> getID() << std::endl;
		userWriting << "\t" << users[i] -> getFullName() << std::endl;
		userWriting << "\t" << users[i] -> getBirthYear() << std::endl;
		userWriting << "\t" << users[i] -> getZipCode() << std::endl;
		std::vector<std::size_t> userFriends = users[i] -> getFriends();
		userWriting << "\t";
		for(int i = 0; i < userFriends.size(); i++){
			userWriting << userFriends[i] << " ";
		}
		userWriting << std::endl;
	}
	userWriting.close();
	return 0;
}

// pre: Valid user given
// post: Adds the user that was given into the vector of users
void Network::addUser(User* newUser){
	users.push_back(newUser);
}

// pre: Both users provided have to be unique and valid users
// post: Ensures that the two users given are successfully added as friends, assuming they aren't friends already
int Network::addConnection(std::string friend1, std::string friend2){
	if((getId(friend1) == -1 || getId(friend2) == -1) || (friend1 == friend2)){
		return -1;
	}
	else{
		User* user1 = getUser(getId(friend1));
		User* user2 =getUser(getId(friend2));
		std::vector<std::size_t> user1Connection = user1 -> getFriends();
		for(auto i = user1Connection.begin(); i != user1Connection.end(); i++){
			if(*i == getId(friend2)){
				return -1;
			}
		}
		user1 -> addFriend(getId(friend2));
		user2 -> addFriend(getId(friend1));
		return 0;
	}
}

// pre: Both users provided have to be unique and valid users
// post: Ensures that the two users given are successfully removed as friends, assuming they were friends before the removal
int Network::removeConnection(std::string friend1, std::string friend2){
	if((getId(friend1) == -1 || getId(friend2) == -1) || (friend1 == friend2)){
		return -1;
	}
	else{
		User* user1 = getUser(getId(friend1));
		User* user2 =getUser(getId(friend2));
		std::vector<std::size_t> user1Connection = user1 -> getFriends();
		for(auto i = user1Connection.begin(); i != user1Connection.end(); i++){
			if(*i == getId(friend2)){
				user1 -> deleteFriend(getId(friend2));
				user2 -> deleteFriend(getId(friend1));
				return 0;
			}
		}
		return -1;

	}
}

//pre: Two valid users are inputted
//post: Gives a vector that shows the shortest social connection between two users
std::vector<std::size_t> Network::shortestPath(std::size_t from, std::size_t to){
	std::queue<std::size_t> q; // First in, first out
	std::vector<bool> visitedVertices(users.size(), 0); // bool visitedVertices[users.size()];
	std::vector<std::size_t> previousVertex(users.size(), -1);
	q.push(from);
	while (q.size() > 0) {
		// Visit the next user
		std::size_t currentUserId = q.front();
		q.pop();
		if (visitedVertices[currentUserId]){ 
			continue;
		}
		visitedVertices[currentUserId] = true;

		// Add their friends to queue
		User* tempUser = getUser(currentUserId);
		std::vector<std::size_t> currentUsersFriends = (tempUser -> getFriends());
		for (auto friendId : currentUsersFriends) {;
			q.push(friendId);
			if (previousVertex[friendId] == -1 && friendId != from) {
				previousVertex[friendId] = currentUserId;
			}
		}
	} 
	std::vector<std::size_t> returnVector; // Reverses the previous Vertexes to return a path
	std::size_t currentUser = to;
	while(currentUser != -1){
		returnVector.push_back(currentUser);
		currentUser = previousVertex[currentUser];
	}
	reverse(returnVector.begin(), returnVector.end());
	return returnVector;
}

//pre: Valid user inputted
//post: Returns path from a user to a certain distance
std::vector<std::size_t> Network::distanceUser(std::size_t from, std::size_t& to, std::size_t distance){
	std::vector<std::size_t> distanceVector(users.size(), -1); //Keeps track of users in specified distance
	distanceVector[from] = 0;
	std::queue<std::size_t> q; // First in, first out
	std::vector<bool> visitedVertices(users.size(), 0); // bool visitedVertices[users.size()];
	std::vector<std::size_t> previousVertex(users.size(), -1);
	q.push(from);
	while (q.size() > 0) {
		// Visit the next user
		std::size_t currentUserId = q.front();
		q.pop();
		if (visitedVertices[currentUserId]){ 
			continue;
		}
		visitedVertices[currentUserId] = true;

		// Add their friends to queue
		User* tempUser = getUser(currentUserId);
		std::vector<std::size_t> currentUsersFriends = (tempUser -> getFriends());
		if(to != -1){ // if to != -1, that means a user within the distance is found
			break;
		}	
		for (auto friendId : currentUsersFriends) {
			q.push(friendId);
			if (previousVertex[friendId] == -1 && friendId != from) {
				previousVertex[friendId] = currentUserId;
			}
			if (distanceVector[friendId] == -1) {
				distanceVector[friendId] = distanceVector[currentUserId] + 1;
				if(distanceVector[friendId] == distance){
					to = friendId;
					break;
				}
			}
		}
	} 
	std::vector<std::size_t> returnVector; // Reverses the previous Vertexes to return a path
	std::size_t currentUser = to;
	while(currentUser != -1){
		returnVector.push_back(currentUser);
		currentUser = previousVertex[currentUser];
	}
	reverse(returnVector.begin(), returnVector.end());
	return returnVector;	
}

//pre: Gives a valid user
//post: Returns the best friend suggestions for a user
std::vector<std::size_t> Network::suggestFriends(std::size_t who, std::size_t& score){
	std::vector<std::size_t> bestSuggestions(users.size(), -1); // Keeps track of the best suggestions and returns this vector
	std::vector<std::size_t> distanceVector(users.size(), -1); // Keeps track of users distance from og user
	std::vector<std::size_t> friendsOfFriend; // Keeps track of user's friends' friends
	distanceVector[who] = 0;
	std::queue<std::size_t> q;
	std::vector<bool> visitedVertices(users.size(), 0); // bool visitedVertices[users.size()];
	q.push(who);
	while (q.size() > 0) {
		// Visit the next user
		std::size_t currentUserId = q.front();
		q.pop();
		if (visitedVertices[currentUserId]){ 
			continue;
		}
		visitedVertices[currentUserId] = true;

		// Add their friends to queue
		User* tempUser = getUser(currentUserId);
		std::vector<std::size_t> currentUsersFriends = (tempUser -> getFriends());
		for (auto friendId : currentUsersFriends) {
			q.push(friendId);
			if (distanceVector[friendId] == -1) {
				distanceVector[friendId] = distanceVector[currentUserId] + 1;
				if(distanceVector[friendId] == 2){
					friendsOfFriend.push_back(friendId);
				}
			}
		}
	}	
	User* ogUser = getUser(who); //Original User
	std::vector<std::size_t> ogUserFriends = (ogUser -> getFriends());
	// Create a for-loop to find the list of user's twoScore's friends
	for(auto friendId : friendsOfFriend){
		User* twoScoreUser = getUser(friendId);
		std::vector<std::size_t> twoScoreFriends = (twoScoreUser -> getFriends()); // list of friends's friends's friends
		size_t mutualScore = 0;
		// Then take friend vector of friendOfFriend and compare it to ogFriend Vector ()	
		for(auto cFriendsId: ogUserFriends){
			for(auto twoScoreFriendsId : twoScoreFriends){
				//After that, check if any set inital score of 0, increase everytime it matches
				if(cFriendsId == twoScoreFriendsId){
					mutualScore++;
				}
			}

		}
		if(score < mutualScore || score == -1){
			score = mutualScore;
			bestSuggestions.clear();
			bestSuggestions.push_back(friendId);
		}
		else if(score == mutualScore){
			bestSuggestions.push_back(friendId);
		}
	}
	return bestSuggestions;
	
}

//pre: None
//post: Returns all the sets of friend groups
std::vector<std::vector<std::size_t>> Network::groups(){
	std::vector<std::vector<std::size_t>> friendGroups;
	std::vector<bool> visitedPeople(numUsers(), 0);
	for(std::size_t i = 0; i < visitedPeople.size(); i++){
		if(visitedPeople[i] == 0){
			friendGroups.push_back(depthFirst(i, visitedPeople));
		}
	}
	return friendGroups;
}

std::vector<std::size_t> Network::depthFirst(std::size_t source, std::vector<bool>& visited) {
	std::vector<std::size_t> output;
	std::vector<std::size_t> stck;
	stck.push_back(source);
	while (stck.size() > 0) {
		// Visit the next user
		std::size_t currentId = stck[stck.size() - 1];
		User* startingUser = getUser(currentId);
		stck.pop_back();
		if (visited[currentId]) { 
			continue; 
		}
		visited[currentId] = true;
		// Add current user to output
		output.push_back(currentId);
		std::vector<std::size_t> friends = startingUser->getFriends();
		// Add their friends to each set
		for (int i = 0; i < friends.size(); i++) {
			stck.push_back(friends[i]);
		}
	}
	return output;
}

// pre: Valid user and owner given
// post: Adds a post to the network and the user
void Network::addPost(std::size_t ownerId_, std::string message_, std::size_t likes_, bool incoming_, std::size_t author_, bool isPublic_){
	if(incoming_){
		if(getUser(author_) == nullptr){
			return;
		}
		if(getUser(ownerId_) == nullptr){
			return;
		}
		IncomingPost* tempIncomingPost = new IncomingPost(numMessages++, message_, likes_, isPublic_, getUser(author_)->getFullName());
		getUser(ownerId_)->addPost(tempIncomingPost);
		return;
	}
	else{
		Post* tempPost = new Post(numMessages++, message_, likes_);
			if(getUser(ownerId_) == nullptr) {
			return;
		}
		getUser(ownerId_)->addPost(tempPost);
	}
}

// pre: Valid user inputted
// post: Returns the post's display on the network
std::string Network::displayPosts(std::string name, std::size_t howMany, bool showOnlyPublic){
	std::string postDisplay;
	if(getId(name) == -1){
		return postDisplay;
	}
	postDisplay = users[getId(name)] -> displayPosts(howMany, showOnlyPublic);
	return postDisplay;
}

// pre: Valid filename given
// post: Reads the posts into the files, returns -1 if unsuccessful, returns 0 if successful
int Network::readPosts(char* filename){
	std::ifstream inputFileTest(filename);
	std::size_t currentMessageId, currentMessageOwner, currentLikes;
	std::string currentMessage;
	bool currentPublicity;
	int lineTracker = 1; //Keeps track of line number in file
	std::string currentLine;
	if(!std::getline(inputFileTest,currentLine)) {
		return -1;
	}
	inputFileTest.close();
	std::ifstream inputF(filename);
	while(getline(inputF,currentLine)) {
		//Special Case for first line
		if(lineTracker == 1){
			for(int i = 0; i < currentLine.size(); i++) {
				if(isalpha(currentLine[i])){
					return -1;
				}
			}
			if(std::stoi(currentLine) == 0) {
				return -1;
			}
			else{
				lineTracker++;
			continue;
			}
		}
		else if(lineTracker % 5 == 2){
			if(currentLine[0]!='\t') {
				for(int i = 0; i < currentLine.size(); i++){
					if(isalpha(currentLine[i])){
						return -1;
					}
				}
			currentMessageId = std::stoi(currentLine);
			if(numMessages != currentMessageId){
				return -1;
			}
			inputF.ignore(256,'\t');
			numMessages++;
			lineTracker++;
			}
			else{
				std::string temp;
				for(int i = 0; i < currentLine.size(); i++) {
					if(currentLine[i] =='\t'){
						continue;
					}
					temp += currentLine[i];
				}
				if(getUser(currentMessageOwner) == nullptr){
					return -1;
				}
				IncomingPost* tempIncomingPost = new IncomingPost(currentMessageId, currentMessage, currentLikes, currentPublicity, temp);
				getUser(currentMessageOwner) -> addPost(tempIncomingPost);
			}
		}
		else if(lineTracker % 5 == 3){
			currentMessage = currentLine;
			inputF.ignore(256,'\t');
			lineTracker++;
		}
		else if(lineTracker % 5 == 4){
			for(int i = 0; i < currentLine.size(); i++){
				if(std::isalpha(currentLine[i])){
					return -1;
				}
			}
			currentMessageOwner = std::stoi(currentLine);
			inputF.ignore(256, '\t');
			lineTracker++;
		}
		else if(lineTracker % 5 == 0){
			for(int i = 0; i < currentLine.size(); i++){
				if(std::isalpha(currentLine[i])){
					return -1;
				}				
			}
			currentLikes = std::stoi(currentLine);
			lineTracker++;
		}
		else if(lineTracker % 5 == 1){
			for(int i = 0; i < currentLine.size(); i++){
				if(std::isdigit(currentLine[i])){
					return -1;
				}				
			}
			if(!currentLine.empty()){
				if(currentLine == "\tpublic"){
					currentPublicity = true;
				}
				else if(currentLine == "\tprivate"){
					currentPublicity = false;
				}
				else{
					return -1;
				}
			}
			else{
				Post* tempPost = new Post(currentMessageId, currentMessage, currentLikes);
				if(getUser(currentMessageOwner) == nullptr){
					return -1;
				}
				if(users[currentMessageOwner] == nullptr){
					return -1;
				}
				users[currentMessageOwner] -> addPost(tempPost);
			}
			lineTracker++;
		}
		else{
			return -1;
		}
	}
	inputF.close();
	return 0;
}

// pre: Name provided has to be of a valid user
// post: Returns the id number of the user's name provided
std::size_t Network::getId(std::string name){
	for(int i = 0; i < users.size(); i++){
		if(name == users[i] -> getFullName()){
			return users[i] -> getID();
		}
	}
	return -1;
}

// pre: None
// post: Returns the number of users in the network
std::size_t Network::numUsers(){
	return users.size();
}

// pre: Id is a valid ID
// post: Returns the user through the ID provided
User* Network::getUser(std::size_t id){
	for(int i = 0; i < users.size(); i++){
		if(id == users[i] -> getID()){
			return users[i];
		}
	}
	return nullptr;	
}
