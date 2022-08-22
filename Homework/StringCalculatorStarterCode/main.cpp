#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

//using std::cout, std::endl, std::cin;
//using std::string;
using namespace std;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string response;
    bool adding;
    bool mult;
    cout << ">> ";
    while (getline(cin,response))   {
    adding = false;
    mult = false;
    if ((response == "q") || (response == "quit"))  {
        cout << endl;
        cout << "farvel!" << endl;
        break;}
    else{
        string number1 = "";
        string number2 = "";
        int start = 0;
        int counter = 0;
        for (unsigned long i = 0; i < response.length(); i++) {
            counter += 1;
            if (response[i] == ' ') {
            if (response[i+1] == '+'){adding = true;}
            if (response[i+1] == '*'){mult = true;}
            start = i + 2;
            counter += 2;
            break;}
        number1 += response[i];}
        int index2 = response.length() - counter;
        number2 = response.substr(start+1,index2+1);


        number1 = trim_leading_zeros(number1);
        number2 = trim_leading_zeros(number2);

        //cout << trim_leading_zeros("-00000") << endl;
        if (adding){
            cout << endl;
            cout << "ans =" << endl;
            cout << endl;
            cout << "    " << add(number1, number2) << endl;}
        if (mult)   {
            cout << endl;
            cout << "ans =" << endl;
            cout << endl;
            cout << "    " << multiply(number1, number2) << endl;} 
            cout << endl;
        cout << ">> ";
        }
        response.clear();}


}
    
    
    // TODO(student): implement the UI


