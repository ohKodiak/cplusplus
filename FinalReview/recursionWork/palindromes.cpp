#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
bool palindrome(int num)    {

//base case
//get first number
//get last number
//if same, call recursive function again with those numbers not included
int first = 0;
int digit = 0;
int counter = 0;
int last = 0;
int leftover = 0;
int length = 0;
while (num != 0)    {
    digit = num % 10; //gives you last digit off 
    if (counter == 0)    {last = digit;} 
    if (num / 10 == 0)  {first = num; length = counter-1; break;} //check for last before going into middle
    if (counter != 0)   {leftover += digit * pow(10,counter-1); }
    
    counter += 1;
    num /= 10; //slice
    }
//bool check = false;
//cout << first << " " << last << endl;
//cout << leftover << endl;
//cout << length << endl;
if (first == last)  {
    
    //cout << "here1" << endl;
    cout << "length is " << length << endl;
    if (length == 1)    {
       // check = true;
        return true;}
    if (length == 0)    {
        //check = true;
        //cout << "check is " << check << endl;
        return true;}
    if (length > 1)    {palindrome(leftover);}
    }
else {return false;}
//cout << "check is " << check << endl;
return false;
}

//why doesnt this code work??



int main()  {
cout << palindrome(334433) << endl;
}