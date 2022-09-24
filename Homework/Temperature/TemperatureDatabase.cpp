#include "TemperatureDatabase.h"
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
#include <sstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureData.h"
#include <fstream>
using namespace std;


// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1

	ifstream ifs(filename);
	if (!ifs.is_open()) {
		cout << "Error: Unable to open " << filename << endl;}
	string id = "";
	int year = 0;
	int month = 0;
	double temperature = 0;
	string response = "";
	string test = "";
	while(getline(ifs,response)){ 
  		istringstream name(response);
		//add controls for invalid input types here
		name >> id;
		if (name.fail())	{
			cout << "Error: Other invalid input" << endl;
			name.clear();}

		name >> year;
		if (name.fail())	{
			cout << "Error: Other invalid input" << endl;
			name.clear();}
		if (year < 1800 || year > 2022)	{
			cout << "Error: Invalid year " << year << endl;
		}
		
		name >> month;
		if (name.fail())	{
			cout << "Error: Other invalid input" << endl;
			name.clear();}
		if (month < 1 || month > 12)	{
			cout << "Error: Invalid month " << month << endl;
		}

		name >> temperature;
		if (name.fail())	{
			cout << "Error: Other invalid input" << endl;
			name.clear();}
		if (temperature < -50.00 || temperature > 50.00)	{
			if (temperature != -99.99)	{
			cout << "Error: Invalid temperature " << temperature << endl;}
		}

	records.insert(id, year, month, temperature);
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	(void)filename; //void cast
	// Implement this function for part 2
	//  Leave it blank for part 1
}
