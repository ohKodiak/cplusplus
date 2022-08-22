#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  int i = 0;
  while (str[i] != '\0')  {
  i += 1;}
  return i;
}

unsigned int find(char str[], char character) {
  int i = 0;
  while (str[i] != '\0')  {
    if (str[i] == character)  {
      return i;}
    i += 1;
  } return i;
  
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  return 0;
}

bool equalStr(char str1[], char str2[]) {
  int i = 0;
  while (true)  {
    if (str1[i] != str2[i]) {
      return false;
    }
   else {
    if (str1[i] == '\0')
    {return true;} }
   i += 1;}
  //if (str1[i] != str2[i]){
   // return false;
  //}}
  // returns true if they are equal and false if they are not
}