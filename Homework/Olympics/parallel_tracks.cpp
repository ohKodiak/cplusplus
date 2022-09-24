#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include <stdexcept> 
using namespace std;
#include <string>
#include <sstream>
#include <fstream>

//check functions
bool checkint(string digit)  {
    unsigned long counter = 0;
    bool test = false;
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
    for (unsigned long i = 0; i < digit.length(); i++ )  {
      char num = digit[i];

      for (unsigned long j = 0; j < 11; j++ )  {
      if (num == numbers[j]) {
        counter += 1;
      }}
} if (counter == digit.length())  {test = true;}
return test;}
bool checkcountry(string input){
	bool checkedstring = false;
  unsigned long counter = 0;
  for (unsigned long i = 0; i < input.length(); i++ )  {
    char letter = input[i];
	  if ((isalpha(letter)) && isupper(letter)){
		counter += 1;
	}}  if (counter == input.length())  { checkedstring = true;}

return checkedstring;}
bool checkname(string input){
  input = trim(input);
	bool checkedstring = false;
  unsigned long counter = 0;
  for (unsigned long i = 0; i < input.length(); i++ )  {
    char letter = input[i];
	  if ((isspace(letter)) || (isalpha(letter))){
		counter += 1;
	}}  if ((counter == input.length()) && (input.length() > 1))  { checkedstring = true;}

return checkedstring;}
bool checkdouble(string digit)  {
    unsigned long counter = 0;
    bool test = false;
    char numbers[] = {'0','1','2','3','4','5','6','7','8','9','.'};
    for (unsigned long i = 0; i < digit.length(); i++ )  {
      char num = digit[i];

      for (unsigned long j = 0; j < 12; j++ )  {
      if (num == numbers[j]) {
        counter += 1;
      }}
} if (counter == digit.length())  {test = true;}
return test;}
//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data( const std::string& fileline, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) {
	string response = "";
	string test = "";
	string files = "";
	int index = 0;
  	string gettime = "";
  	string getcountry = "";
  	string getnumber = "";
  	string getname = "";
	//cout << "name file: " << endl;
	//cin >> fileline;
	ifstream ifs(fileline); // opens file named fileline
	if (!ifs.is_open()) {
		throw invalid_argument("Cannot open file");}

while(getline(ifs,response)){ //full line
  istringstream name(response); //change variable name 

  name >> gettime;
  if (name.fail())	{throw domain_error("File missing data");}
  gettime = trim(gettime);
  //if (checkdouble(gettime) == false){throw std::invalid_argument("File contains invalid data (time)");}
  stringstream contain(gettime); // contains time
  if (contain.fail()){throw domain_error("File contains invalid data (time)");}
  double times = 0.0;
  contain >> times; // time 
  if (times <= 0){throw domain_error("File contains invalid data (time)");}
  //check if there was a problem if contain.fail(), then check if negative

  name >> getcountry;
  //if (name.fail())	{throw invalid_argument("File missing data");}
  getcountry = trim(getcountry);
  if (!checkcountry(getcountry)){throw domain_error("File contains invalid data (country)");}
  if (getcountry.length() != 3){throw domain_error("File contains invalid data (country)");}

  name >> getnumber;
  //if (name.fail())	{throw invalid_argument("File missing data");}
  getnumber = trim(getnumber);
  stringstream container(getnumber);
  int num = 0;
  container >> num; // contains number
  if (container.fail()){throw domain_error("File contains invalid data (number)");}
  if (num > 99)	{throw domain_error("File contains invalid data (number)");}
  if (num < 0)	{throw domain_error("File contains invalid data (number)");}

  //name >> getname; // getline(name,getname);

  if (name.fail()) {throw domain_error("File contains invalid data (name)");}
  getline(name,getname);
  getname = trim(getname);
  if (!checkname(getname)){throw domain_error("File contains invalid data (name)");}

  timeArray[index] = times;
  countryArray[index] = getcountry;
  numberArray[index] = num;
  lastnameArray[index] = getname;
  index += 1;}}



//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{	unsigned long index = 0;
	for (index = 0; index < SIZE; index++)	
	{ary[index] = 0.0;}}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{	unsigned long index = 0;
	for (index = 0; index < SIZE; index++)	
	{ary[index] = 0;}}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{	unsigned long index = 0;
	for (index = 0; index < SIZE; index++)	
	{ary[index] = "N/A";}}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{  unsigned long index = 0;
   unsigned long compare = 0;
   int fasterthan = 0;
   int rank = 0;
   for (index = 0; index < SIZE; index++)  {
       fasterthan = 0;
       for (compare = 0; compare < SIZE; compare++)   {
           if (timeArray[index] < timeArray[compare]){
               fasterthan += 1; }}
       rank = SIZE - fasterthan; //faster than 8 of them, will be 1
       rankArray[index] = rank;
   }}



//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//dont edit
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}
//dont edit
std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}