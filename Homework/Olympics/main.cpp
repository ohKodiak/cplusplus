/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.csv
content: The csv file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include "parallel_tracks.h"
#include <stdexcept>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;


int main()
{
    // TODO: create arrays needed
    string file;
    unsigned int ranks[SIZE] = {};
    unsigned int numbers[SIZE] = {};
	double times[SIZE] = {};
    string countries[SIZE] = {}; 
    string lastnames[SIZE] = {}; 
    // TOTO: prep all arrays
    void prep_double_array(double times);
    void prep_unsigned_int_array(unsigned int ranks);
    void prep_unsigned_int_array(unsigned int numbers);
    void prep_string_array(string countries);
    void prep_string_array(string names);
    // TODO: prompt until both the file and the contained data are valid
	while(cin.good()){ //clear and ignore
        cout << "Enter file name: "; cin >> file;
        try{get_runner_data(file, times, countries, numbers, lastnames); break;}
         catch (const std::exception & ia) {cout << "Invalid File: " << ia.what() << endl;}
         cin.clear();}
    // TODO: determine ranking, notice the rank array receives the results
    get_ranking(times,ranks);
    // TODO: Output results
    print_results(times, countries, lastnames, ranks);
    return 0;
}

