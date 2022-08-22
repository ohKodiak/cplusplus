/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include "Tag.h"

using std::string;
using std::vector;
/*Throw std::invalid_argument if any of the following are true:
tagName length is less than 2 /////done
the first character of tagName is not ‘#’ ////done
the second character in tagName is not from ‘a’ - ‘z’ ////done
tagName contains uppercase letters ‘A’ - ‘Z’ //done 
In other words it should be all lowercase letters ///done
there is one or more consecutive punctuations at the 
end of the tagName (e.g., #happy!, #happy!?, etc.), where punctuation is one of the following: ('!', ',', '.', '?')*/

Tag::Tag(string tagName): tagName(tagName) /* TODO(student): initialize */ { //may have to initialize inside method
  // TODO(student): implement constructor checks
  if (tagName.size() < 2 ) {
    throw std::invalid_argument("tag constructor: invalid parameter values");}
  if (tagName[0] != '#') {
    throw std::invalid_argument("tag constructor: invalid parameter values");}

  for (unsigned int i = 0; i < tagName.size(); i++)  {
    if (isalpha(tagName[i])) {
    if (isupper(tagName[i] )) {
      throw std::invalid_argument("tag constructor: invalid parameter values");}}}

  //check for upper case first so you can just do isalpha
  if (!isalpha(tagName[1])) {
    throw std::invalid_argument("tag constructor: invalid parameter values");}

  int lI = tagName.size() - 1; //last Index
  int slI = lI - 1;     //second to last index
  if ((tagName[lI] == '!') || (tagName[lI] == ',') || (tagName[lI] == '.') || (tagName[lI] == '?') )  {
    if ((tagName[slI] == '!') || (tagName[slI] == ',') || (tagName[slI] == '.') || (tagName[slI] == '?') )  {
      throw std::invalid_argument("tag constructor: invalid parameter values");}}

}

string Tag::getTagName() {
    return tagName;
  // TODO(student): implement getter
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
    return tagPosts;
}

void Tag::addTagPost(Post* post) {
  if (post == nullptr)  {
    throw std::invalid_argument("tag posts: invalid parameter values");}
  
  // TODO(student): add post to tag posts
  //every post has post id, username, and post tags
  //tags are supposed to be member of post text body
  //when you call addTagPost
  //push_back post that had has special tag to an object known as tagPosts
  //adds a member from vector tagposts
  //post talks about 2 things, 2 tags, both tags can have seperate pointers, 
  //footbal in vector football
  //politics vector
  //both vectors have indiviuaal pointer
  //need information from post
  tagPosts.push_back(post);
}
