#include <iostream>
#include <string>
#include <array>
using namespace std;

#include <iostream>

#include <string>

using std::cin, std::cout, std::endl, std::string;


int main() {
    string obString;
    string deobString;
    string details;
    char c;
    int tempNum = 0;
    int num = 0;
    cout << "Please enter obfuscated sentence: ";
    cin >> obString;
    cout << "Please enter deobfuscation details: ";
    cin >> details;
    for(int i = 0; i < details.length(); i++){
        c = details.at(i);
        tempNum = c - 48;
        deobString += obString.substr(num, tempNum) + " ";
        num += (tempNum);
    }
    cout << "Deobfuscated sentence: " << deobString;
    return 0;
}