#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
    bool test = true;
    for (int i = 0; i < 10; i++)    {
        if (numbers[i] == digit)    {
            test = false;
        }
    }
    if (test){
        throw std::invalid_argument("Invalid Argument");}
    digit = static_cast<int>(digit);
    int num = digit - 48;
    return num;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    unsigned int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
    bool test = true;
    for (unsigned long i = 0; i < 10; i++)    {
        if (numbers[i] == decimal)    {
            test = false;
        }}
    if (test){
        throw std::invalid_argument("Invalid Argument");}
    decimal = static_cast<char>(decimal+48);
    char num = decimal;
    // << typeid(num).name() << endl;
    return num;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    string newstring = "";
    unsigned long counter = 0;
    bool negative = false;
    for (unsigned long i = 0; i < num.length(); i++)  {

      if (num[i] == '-')  {
        negative = true;
        newstring += num[i];}
      else if (num[i] != '0') {
        int firstindex = i; 
        int length = num.length() - firstindex;
        newstring.append(num.substr(firstindex,length));
        break;}
      else  {
        counter += 1;
        continue;
      }
      }
    if (negative) {
      if (counter == num.length() -1) {return "0";}
    } if (negative == false)  {
      if (counter == num.length())  { return "0";}
    }
    return newstring;
}

string add(string lhs, string rhs) {  
  bool negative = false;
  string biggerstring = "";
  string smallerstring = "";
  if (lhs.size() >= rhs.size())  { // finds which string is bigger
    biggerstring = lhs;
    smallerstring = rhs;
  } else  {
    biggerstring = rhs;
    smallerstring = lhs;
  }
  biggerstring = trim_leading_zeros(biggerstring);
  smallerstring = trim_leading_zeros(smallerstring);
  if (biggerstring[0] == '-') { 
    biggerstring = biggerstring.erase(0,1);
    smallerstring = smallerstring.erase(0,1);
    negative = true;}
  int carry = 0; int sum; int addbig; int addsmall; int stays;
  for ( unsigned long i = 1; i <= smallerstring.size()+1;i++)  {
    if (i == smallerstring.size()+1 && carry != 0)  {
      // //next letter that needs the carry
      while (carry !=0) {
        if (i > biggerstring.size())  {
          if (biggerstring[0] == '-')   {
          biggerstring.insert(1,"1");}
          if (biggerstring[0] != '-') {
          biggerstring.insert(0,"1");}
          if (negative) {
          biggerstring.insert(0,"-");}
          return biggerstring;
        }
        int bigindex = biggerstring.size() - i;
        addbig = digit_to_decimal(biggerstring.at(bigindex));
        sum = addbig + carry;
        if (sum >= 10)  {
          stays = sum % 10;
          carry = 1;}
        else{
          stays = sum;
          carry = 0;
          char stayed = decimal_to_digit(stays);
          biggerstring[bigindex] = stayed;
          if (negative) {
            biggerstring = biggerstring.insert(0,"-");}
          return biggerstring;}
        
        char stayed = decimal_to_digit(stays);
        biggerstring[bigindex] = stayed;
        i +=1;
        }}

    if (i == smallerstring.size()+1 && carry == 0) {
      break;}

    int smallindex = smallerstring.size() - i; // index moving from right to left
    int bigindex = biggerstring.size() - i;
    if (smallerstring.at(smallindex) == '-') {continue;}

    addsmall = digit_to_decimal(smallerstring.at(smallindex)); // integer values of indexed smaller number
    addbig = digit_to_decimal(biggerstring.at(bigindex)); // integer value of indexed larger number
    sum = addsmall + addbig + carry;
    if (sum >= 10)   {
      stays = sum % 10;
      //sum /= 10;
      carry = 1;} 
    else{
      carry = 0;
      stays = sum;}
  
  char stayed = decimal_to_digit(stays);
  biggerstring[bigindex] = stayed;}
if (negative) {
  biggerstring = biggerstring.insert(0,"-");}
return biggerstring;}

string multiply(string lhs, string rhs) {
  string firstpartial = "";
  string totalpartial = "0";
  string firstpartialcorrected = "";
  bool negative = false;
  string biggerstring = "";
  string smallerstring = "";
  if (lhs.size() >= rhs.size())  { // finds which string is bigger
    biggerstring = lhs;
    smallerstring = rhs;
  } else  {
    biggerstring = rhs;
    smallerstring = lhs;
  }
  //trim leading zeros
  biggerstring = trim_leading_zeros(biggerstring);
  smallerstring = trim_leading_zeros(smallerstring);
  //check if answer should be positive or negative
  if ((biggerstring[0] == '-') && smallerstring[0] == '-') { 
    biggerstring = biggerstring.erase(0,1);
    smallerstring = smallerstring.erase(0,1);
    negative = false;}
  if ((biggerstring[0] == '-') && smallerstring[0] != '-') { 
    biggerstring = biggerstring.erase(0,1);
    negative = true;}
  if ((biggerstring[0] != '-') && smallerstring[0] == '-') { 
    smallerstring = smallerstring.erase(0,1);
    negative = true;}
  //initialize variables
  unsigned long i = 1;;
  unsigned long j= 1;;
  char lastcarry = '0';
  int carry = 0; 
  int product = 0;
  int multiplier = 0;
  int multiplied = 0;
  int stays = 0;
  //loop through smaller number
  for (j = 1; j <= smallerstring.size(); j++)  {
    multiplier = digit_to_decimal(smallerstring[smallerstring.size() - j]);
    firstpartial.clear();
    firstpartialcorrected.clear();
    carry = 0;
  //loop through bigger number
    for (i = 1; i <= biggerstring.size(); i ++) {
      multiplied = digit_to_decimal(biggerstring[biggerstring.size() - i]);
      product = multiplier * multiplied;
      stays = (product % 10) + carry;
      carry = product / 10;
      if (stays > 10)  {
        carry += (stays / 10);
        stays = stays % 10;
        stays = decimal_to_digit(stays);
        firstpartial += stays;
        if (i == biggerstring.size())  {
          lastcarry = decimal_to_digit(carry);
          firstpartial += lastcarry;
          for (unsigned long k = 1; k <= firstpartial.size();k++) {
            firstpartialcorrected += firstpartial[ firstpartial.size()- k];}//need to append 0's here
          for (unsigned e = 1; e < j; e++)  {
            firstpartialcorrected += "0";}
        if (trim_leading_zeros(firstpartialcorrected) == "0") {continue;} //just added
        totalpartial = add(firstpartialcorrected,totalpartial);
          }
        }
      else if (stays == 10)  {
        carry += 1;
        firstpartial += "0";
        if (i == biggerstring.size())  {
          lastcarry = decimal_to_digit(carry);//reverse order
          firstpartial += lastcarry;//now you have the full number for partial
          for (unsigned long k = 1; k <= firstpartial.size();k++) {
            firstpartialcorrected += firstpartial[ firstpartial.size()- k];}//need to append 0's here
          for (unsigned e = 1; e < j; e++)  {
            firstpartialcorrected += "0";}
        if (trim_leading_zeros(firstpartialcorrected) == "0") {continue;} //just added
        totalpartial = add(firstpartialcorrected,totalpartial);
        }}
      else if (stays < 10) {
        stays = decimal_to_digit(stays);
        firstpartial += stays; 
        if (i == biggerstring.size())  {
          lastcarry = decimal_to_digit(carry);//reverse order
          firstpartial += lastcarry;//now you have the full number for partial
          for (unsigned long k = 1; k <= firstpartial.size();k++) {
            firstpartialcorrected += firstpartial[ firstpartial.size()- k];}//need to append 0's here
          for (unsigned e = 1; e < j; e++)  {
            firstpartialcorrected += "0";}
        if (trim_leading_zeros(firstpartialcorrected) == "0") {continue;} //just added
        totalpartial = add(firstpartialcorrected,totalpartial);
        }}} 
  }
  if (negative) {totalpartial.insert(0,"-");}
  return totalpartial;}
