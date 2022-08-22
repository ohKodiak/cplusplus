/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Post.h"
#include <cctype>
#include <sstream>
using namespace std;

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  unsigned int i = 0;
  //string word = "";
  //int punctuation = 0;
  string filteredWord = "";
  vector<string> Tags;
  istringstream iss(postText); 
  string something;
  while (iss >> something)  {
    if (something.at(0) == '#')  {
      for (i = 0; i < something.size(); i++)  {
        if (i == something.size() - 1)  { //last index cant be punctuation
          if ( (something.at(i) == '!') || (something.at(i) == '?') || (something.at(i) == ',') || (something.at(i) == '.') ) {
            continue;}}

        if (isalpha(something.at(i))) {
          filteredWord += tolower(something.at(i));}
        else{filteredWord+= something.at(i);}}
      Tags.push_back(filteredWord);
      filteredWord = "";}}
  
  return Tags;

  /*for (i = 0; i < postText.size(); i++) { //move through post
    if (postText[i] == '#') { //move through word
      while (postText[i] != ' ')  { //stop at space
        if (i == postText.size())  {break;} //makes sure it doesnt loop infinitely if hashtag at end of string, may be +- 1
        word += postText[i]; //grab letter
        i += 1;}
      
      int j = 0;
      for (j = 0; j < word.size(); j++) { //account for hashtag
        if (word[j] == '!' || word[j] == ',' || word[j] == '.' || word[j] == '?')  {
          punctuation += 1;}
        if (isalpha(word[j])) {
          word[j] = tolower(word[j]);}
          filteredWord += word[j];}
    //after this loop, can add to vector
    //check punctuation at the end
    int size = filteredWord.size();
    for (int k = 1; k < punctuation; k++) {
      int index = size - k; //can also use.back() to check last character
      if (filteredWord[index] == '!' || filteredWord[index] == ',' || filteredWord[index] == '.' || filteredWord[index] == '?')  {
        filteredWord.pop_back();
      }
      else{break;}} //break out of loop if you detect charcter which isnt punctuation
    Tags.push_back(filteredWord);}
    else{continue;}}
    return Tags;}*/
}


// stringstream postText