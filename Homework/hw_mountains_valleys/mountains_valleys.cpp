#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	// TODO(student): print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	// TODO(student): read the numbers from standard input
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;

	// TODO(student): validate input (and reprompt on invalid input)
	while ( (is_valid_range(a, b) != true) )	{
		cout << "Invalid Input" << endl;
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a;
		cin >> b;

	}
	// TODO(student): compute and display solution
	count_valid_mv_numbers(a, b);
	//cout << classify_mv_range_type(9182735) << endl;
	//classify_mv_range_type(293847);
	//cout << "take2" << endl;
	//classify_mv_range_type(9182735); // should be V, odd
	//cout << "3rd" << endl;
	//classify_mv_range_type(639891); // should be V, even
	//classify_mv_range_type(564738291); // should be M, odd
	//classify_mv_range_type(120548); // should be M, even
	//classify_mv_range_type(125548); // should be N, even
	//classify_mv_range_type(1205488); // should N, odd 
	//classify_mv_range_type(10000000);
	//cout << "here" << endl;
	//classify_mv_range_type(1000000); // even
	//cout << "here1" << endl;
	//classify_mv_range_type(12000000); 
	//cout << "here3" << endl;
	//count_valid_mv_numbers(10,100000);
	return 0;
}