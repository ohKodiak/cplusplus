#include <iostream>
#include <iomanip>

using std::cout, std::endl, std::boolalpha;

bool isValid(char password[]) {
    // initiialize varibales 
    char storeddigit = 'A';
    int index = 0; //index for password
    int j = 0; //index for special characters
    int size = 0;
    int numdigits = 0;
    int countspecial = 0;
    char special[4] = {'$','#','@','&'};


    while (password[index] != '\0')  {
    if (isdigit(password[index]))   {numdigits += 1;} // counts digits 

    if (password[index] == ' ') {return false;} //checks for spaces

    if (password[index] == storeddigit) {return false;} //checks for consecutive chars

    while (special[j] != '\0') {
        if (password[index] == special[j])  {countspecial += 1;}
        j += 1;} //checks against special characters
    j = 0; //re initialze the j index for special characters to zero after checking

    size += 1; //counts size
    storeddigit = password[index]; //holds 
    index += 1;} //increments
    if (numdigits < 2)  {return false;} //checks digits
    if ((size < 9) || (size > 18))  {return false;} //checks size
    if (countspecial < 2)   {return false;} //checks special
    return true; // returns true if makes it through 
}

int main() {
    //cout << isValid("VyS;7@5Zh&baeF(@") << endl;  //1
    //cout << isValid("vs;7@zh &bbf(@") << endl;  //0
    //cout << isValid("Wkx'gZ4d") << endl; //0
}