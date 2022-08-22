#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string stringword;
    string filterword;
    cout << "Please enter the sentence: "; // breaks when you give it a sentence, may need to incorporate while loop from palindrome
    getline(cin, stringword);
    //cout << endl;
    cout << "Please enter the filter word: ";
    cin >> filterword;
    //cout << endl;
    string filter = "#";
    //replace requires starting index, length, and what string you're replacing it with
    int filterlength = filterword.length();
    int stringlength = stringword.length();
    for (int i = 1; i < filterlength; i++)  {
        filter.append("#");}
// works perfectly up to here
    for (int i=0; i < stringlength; i++) {
        int indexed = stringword.find(filterword);
        if (indexed < 0)    {
            break;
        }
        if (indexed <= stringlength)  {
                stringword.replace(indexed,filterlength,filter);
        }   else    {
            break;
        }

    }
    //cout << stringword.find(filterword) << endl;
    //cout << "test" << endl;
    cout << "Filtered sentence: " << stringword << endl;
    return 0;
}
