#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "original.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams
	ifstream censorIn = ifstream(censorWordsFilename);
	ifstream originalIn{ originalTextFilename };
	ofstream censoredOut{ censoredTextFilename };

	// make sure all files were opened and give feedback if not
	if (!censorIn.is_open()) {
		cerr << "Failed to open censor word file: " << censorWordsFilename << endl;
		return 1;
	}

	if (!originalIn.is_open()) {
		cerr << "Failed to open censor word file: " << originalTextFilename << endl;
		return 1;
	}

	if (!censoredOut.is_open()) {
		cerr << "Failed to open censor word file: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	vector<string> censorWords = { "coffee", "java", "bean" };
	string word;

	// print out list of censored words (for debugging) remove later from final program
	cout << "Words to Censor: " << endl;
	for (unsigned int i = 0; i < censorWords.size(); ++i) {
		cout << censorWords.at(i) << endl;
	}
	cout << endl;

	// read original, process and send to output
	// process line by line
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line

	// following so I can see the output
	cout << endl;
	system("pause");
}