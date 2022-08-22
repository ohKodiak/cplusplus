/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */
//questions for TA, 
//what is throw statement supposed to be
//why is loadfile, and the 3 get poser,user, and popular failing 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;
using namespace std;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}


void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  ifstream ifs(fileName);
  if (!ifs.is_open()) {throw std::invalid_argument("post constructor: invalid parameter values");}//throw something
  string response = "";
  string first;
  string user;
  int id;
  string names = "";
  string post = "";
  string word = "";

  while(getline(ifs,response)){
  istringstream name(response);
  first = "";
  name >> first;
  if (first == "User")  {
    name >> user; //user is a string so will fail if not a string 
    if (name.fail())  {throw std::runtime_error("here1");}//throw something here
    try {
    addUser(user);
    user = "";} //must put in try catch block
    catch(std::exception& e)  {
      std::runtime_error("post constructor: invalid parameter values1");}
  }
  if(first == "Post") {
    name >> id;
    if (name.fail())  {throw std::runtime_error("here2");} //throw something
    name >> names;
    if (name.fail())  {throw std::runtime_error("3");}
    //get first word of post
    getline(name,word);
    if (name.fail())  {throw std::runtime_error("4");} //throw something 
    post += word;
   /* while (!name.eof()) {
      //add to post here
      name >> word;
      if (name.fail())  {throw std::runtime_error("5");} //throw something 
      post += " ";
      post += word;}*/
      

  try
  {
    addPost(id, names, post); //must put in try catch block 
    id = 0;
    names = "";
    word = "";
    post = "";
  }
  catch(std::exception& e)  {
    throw std::runtime_error("post constructor: invalid parameter values2");
  }
  }}}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  //users.push_back() //need to check to make sure its unique
  unsigned int i = 0;
  for (i = 0; i < userName.size(); i++) {
    userName.at(i) = tolower(userName.at(i));}
  //a range for loop
  for (User* username: users) {
    //must use arrow to use method on pointer
    if (username->getUserName() == userName)  {
      throw std::invalid_argument("post constructor: invalid parameter values");
    }}
    
  users.push_back(new User(userName));   //adds new allocated thing to vector of users which is an attribute of network.h
    
  cout << "Added User " << userName << endl;}


void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
 Post* post = new Post(postId, userName, postText);
  for (Post* id: posts) {
   //member of post class, passed by pointer
   if (id->getPostId() == postId)  {
     //not unique
     throw std::invalid_argument("post constructor: invalid parameter values");}}
 
   bool check = false;
   for (User* username: users) {
   //must use arrow to use method on pointer
   if (username->getUserName() == userName)  {
     username->addUserPost(post); 
     check = true;}}
 
   if (!check) {
     throw std::invalid_argument("post constructor: invalid parameter values");}
   //
   posts.push_back(post);
   vector<string> tagsInPost;
   //User user = User(userName);// i think  this is the issue
   //.addUserPost(post); //called
   tagsInPost = post->findTags(); //vector of tags within the post
 
   unsigned int i = 0;
   bool mustCreate = true;
   for ( i = 0; i < tagsInPost.size(); i++)  { //iterates through the vector of tags, checks against existing tags or creates new one
     mustCreate = true;
     for (Tag* tag: tags)  { //checks against tags that are in the network
       if (tagsInPost.at(i) == tag->getTagName())  {
         tag->addTagPost(post);
         mustCreate = false;
       }}
       if (mustCreate) {
         try{
         Tag* createdTag = new Tag(tagsInPost.at(i)); //use dynamic memory
         createdTag->addTagPost(post);
         tags.push_back(createdTag);
         }
         catch(const std::exception& e){}
         }
       }
 
 cout << "Added Post " << postId << " by " << userName << endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  //for range loop
  if (userName == "") {
    throw std::invalid_argument("post constructor: invalid parameter values3");}
  //return (userName.getUserPosts());
  unsigned int i = 0;
  unsigned int index = 0;
  bool check = true;
  //for (User* username: users) {
  for ( i = 0; i < users.size(); i++) {
   if (userName == users.at(i) -> getUserName())  {
      check = false;
      //cout << users.at(i) -> getUserPosts().size();
      //return (users.at(i) -> getUserPosts());
      index = i;
      } 
    }
    //cant be else statement because cant happen inside the loop
    if (check) {throw std::invalid_argument("post constructor: invalid parameter values4");}
    //if nothing is found
    //thow something
    //retrun here instead of in loop to avoid compiler error
    return (users.at(index) -> getUserPosts());
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  if (tagName == "") {
    throw std::invalid_argument("post constructor: invalid parameter values1");}
  for ( unsigned int i = 0 ; i < tagName.size(); i++)  {
    if (isalpha(tagName.at(i))) {
      tagName.at(i) = tolower(tagName.at(i));}}
  unsigned int index = 0;
  bool check = true;
  //copy and paste from getuserposts
  //could also be accessed using for ( int i = 0; i < tags.size(); i++) and you can access members using .at()
  for ( unsigned int i = 0; i < tags.size(); i++) {
    //cout << tagName << endl;
   // cout << tags.at(i)->getTagName() << endl;
   if (tags.at(i)->getTagName() == tagName)  {
      index = i;
      check = false;

      //return (tags.at(i)->getTagPosts());
      } }
    //cant be else statement because cant happen inside the loop
  if (check)  {
  throw std::invalid_argument("post constructor: invalid parameter values2"); }
  //hopefully wont get here
  return tags.at(index)->getTagPosts();
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  //we can treat tags as vectors
  vector<string> emptyVector;
  //vector<string> max;
  //int maxNum = 0;
  if (tags.size() == 0) {
    return emptyVector;}
  int max = tags.at(0)->getTagPosts().size();
  emptyVector.push_back(tags.at(0)->getTagName());

  for (unsigned int i = 1; i < tags.size();i++)  {
    int frequency = tags.at(i)->getTagPosts().size();
    if (max < frequency) {
      max = frequency;
      emptyVector.clear();
      emptyVector.push_back(tags.at(i)->getTagName());}
    else if (max == frequency) {
      emptyVector.push_back(tags.at(i)->getTagName());}}
    
  //vector .clear()

  
 /* for (unsigned int i = 0; i < tags.size();i++)  {
    holdNum = (tags.at(i))->getTagPosts().size(); 
    if (holdNum == maxNum) { //if equal, cant be sae because you need to use clear() if bigger
      maxNum = holdNum;
      string maxxed = (tags.at(i))->getTagName();
      max.push_back(maxxed);}
    if (holdNum > maxNum) {  //if greater than
      maxNum = holdNum;
      string maxxed = (tags.at(i))->getTagName();
      max.clear(); //clear former things 
      max.push_back(maxxed);}*/
   // }
    return emptyVector;
    }
//terminate called after throwing an instance of 'std::out_of_range'
// what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}

