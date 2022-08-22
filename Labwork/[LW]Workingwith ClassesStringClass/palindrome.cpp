#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

bool isPalindrome(string word)  {
    for ( int i = 0; i < word.length() / 2; i++)    {
        if ( word[i] != word[word.length() - i - 1])    {
            return false;
        }
    }   
    return true;
}

int main() {
    int count = 0;
    string wordinSentence;
    cout << "Please enter a sentence (end with 'quit'): ";
    while (cin >> wordinSentence)    {
        if (wordinSentence == "quit"){
            break;
    }   else if (isPalindrome(wordinSentence))  {
        count++;}}

    cout << "You have typed " << count << " palindromes.";
    return 0;
}
