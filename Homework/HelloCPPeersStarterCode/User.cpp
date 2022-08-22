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
#include "User.h"

using std::string;
using std::vector;
/*Throw std::invalid_argument if any of the following are true:
userName is empty
userName does not start with a letter ‘a’ - ‘z’
userName contains uppercase letters ‘A’ - ‘Z’
In other words it should be all lowercase letters
*/
User::User(string userName): userName(userName) /* TODO(student): initialize */ {
  // TODO(student): implement constructor checks
  if (userName == "") {
    throw std::invalid_argument("user constructor: invalid parameter values");}
  if (!isalpha(userName[0]))  {
    throw std::invalid_argument("user constructor: invalid parameter values");}
  for (unsigned int i = 0; i < userName.size(); i++) {
    if (!isalpha(userName[i]))  {continue;}
    if (isupper(userName[i])) {
       throw std::invalid_argument("user constructor: invalid parameter values");}}

}

string User::getUserName() {
  // TODO(student): implement getter
  return (userName);
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  return (userPosts);
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if (post == nullptr)   {
    throw std::invalid_argument("user constructor: invalid parameter values");
  }
  userPosts.push_back(post);
}
