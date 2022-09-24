#include <iostream>
#include "functions.h"

using namespace std;

bool is_valid_range(int a, int b) {

	// TODO(student): validate input range
	if ( ( (a >= 10) && (b < 10000) ) && (b >= a) )	{
		return true;}
	else	{
		return false;}	
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// only takes in one number at a time 
	int num1;
	int num2;
	char slope = 'A'; 
	char newslope = 'A';
	//int digit;
	//int dig;
	int counter = 1;
	int dig = number;
  	int numlength = 0;
  	while (dig > 0) {
    	dig /= 10;
    	numlength += 1;}
	if (numlength < 2)	{
		return 'N';
	}
	while (counter < numlength)	{

		num1 = number % 10;
		number /= 10;
		//num1 = digit; //right most digit
		//cout << "num1:" << num1 << endl;
		
		num2 = number % 10; //second right most digit
		//cout << "num2:" << num2 << endl;
		//cout << "number:" << number << endl;
		//number /= 10;
		//cout << "number2: " << number << endl;
		if (num1 > num2)	{
			//cout << "got here 1" << endl;
			newslope = 'U';
			//cout << newslope << endl;
			if (newslope == slope)	{
				return 'N';
				break;
			}	else{
				slope = newslope;
				
		}}
		if (num1 < num2)	{
			//cout << "got here 2" << endl;
			newslope = 'D';
			//cout << newslope << endl;
			if (newslope == slope)	{
				return 'N';
				break;
			}	else{
				slope = newslope;
				//cout << slope << endl;
			}
		}if (num1 == num2)	{
			//cout << "got here 3" << endl;
			return 'N';
			break;
		}	
		counter += 1;
	}	//cout << num1 << num2 << endl;
		//cout << slope << endl;
		//cout << newslope << endl;
		if (slope == 'U')	{
		return 'M';
	}	if (slope == 'D')	{
		return 'V';
	}


/*	int dig = number;
  	int numlength = 0;
  	while (dig > 0) {
    	dig /= 10;
    	numlength += 1;

  }
  	if (numlength == 4)	{
		int d4 = number % 10;
		number /= 10;
		int d3 = number % 10;
		number /= 10;
		int d2 = number % 10;
		number /= 10;
		int d1 = number;
		if ( (d4 > d3) && (d3 < d2) && (d2 > d1) )	{
			return 'M';
		}	else if ( (d4 < d3) && (d3 > d2) && (d2 < d1) )	{
			return 'V';
		}	else{
			return 'N';
		}
}
  	if (numlength == 3)	{
		int d3 = number % 10;
		number /= 10;
		int d2 = number % 10;
		number /= 10;
		int d1 = number;
		if ( (d3 < d2) && (d2 > d1) )	{
			return 'M';
		}	else if ( (d3 > d2) && (d2 < d1) )	{
			return 'V';
		}	else{
			return 'N';
		}
}
  	if (numlength== 2)	{
		int d2 = number % 10;
		number /= 10;
		int d1 = number;
		if ( d2 > d1 )	{
			return 'M';
		}	else if ( d2 < d1) 	{
			return 'V';
		}	else{
			return 'N';
		}}
  	if (numlength== 1)	{
		return 'N';
		}

	if (numlength > 4)	{
	int array1[numlength];
	int i;
	//cout << numlength << endl;
	for (i = 0; i < numlength; i++)	{
		array1[i] = number % 10;
		number /= 10;}
	bool checkW = false;
	bool checkV = false;
	int counter = 0;
	if (numlength % 2 == 1)	{ // for odd numbers over 4
		//cout << "odd" << endl;
		for (i = 1; counter < (numlength - 1)/2; i += 2)	{
			//cout << "i:" << i << endl;

			if (array1[i+1] == array1[i] ) {  // in case first 2 are same
				//cout << "broke" << endl;
				// 'N';
				checkW = false;
				checkV = false;
				break;}
	
			else if ((array1[i+1] < array1[i] ) && (array1[i-1] < array1[i])){
				checkW = true;
				//cout << "M" << endl;   //possible loop place
				//cout << array1[i+1] << "and" << array1[i-1] << "compared with" << array1[i] << endl;
				}
			
			else if ((array1[i+1] > array1[i] ) && (array1[i-1] > array1[i]))	{
				checkV = true;
				//cout << "V" << endl;
				//cout << array1[i+1] << "and" << array1[i] << endl;; // this code works succesfully with odd numbers
				}
			
			else {
				//return 'N';
				checkW = false;
				checkV = false;
				break;}
			counter += 1;}}
			
	else	{ // even numbers over 4, must isolate first or late term, start at 0
		//cout << "even" << endl;
		int counter = 0;
		//cout << counter << endl;
		for (i = 2; counter < (numlength/2 - 1); i += 2)	{
			//cout << "i:" << i << endl;
			//taking care of first number 
			if (array1[i+1] == array1[i] ) {  // in case first 2 are same
				//cout << "broke" << endl;
				// 'N';
				checkW = false;
				checkV = false;
				break;}
			//cout << "counter is:" <<counter << endl;
			if (array1[0] > array1[1]) 	{ // mountain path
				if ((array1[i+1] < array1[i] ) && (array1[i-1] < array1[i]))	{
					checkW = true;
					//cout << "here" << endl;
					//cout << i << endl;
					//cout << "M1" << endl;
					}
				else	{
					//cout << "im breaking" << endl;
					//return 'N';   // for 6 numbers, youre only making 2 evaluations 
					//cout << i << endl;
					//cout << "here?" << endl;
					checkW = false;
					//checkV = false;
					break;
				}
				//cout << "V2" << endl;
			counter += 1;
			}
			if (array1[0] < array1[1]) 	{ //valleypath path, //
				//cout << "im over here" << endl;
				if ((array1[i+1] > array1[i] ) && (array1[i-1] > array1[i]))	{
					checkV = true;
					//cout << "V1" << endl;
					}
				else	{
					//cout << "didnt get in " << endl;
					//return 'N';
					checkV = false;
					break;
				}
				//cout << "M2" << endl;
			counter += 1;	
			}}}
	//cout << checkW << endl;
	//cout << checkV << endl;
	///cout << 
	if (checkW)	{
		//cout << "M" << endl;
		return 'M';
		}
	if (checkV == 1 || checkV == true || checkV)	{
		//cout << "V" << endl;
		return 'V';}
	else{
		//cout << "N" << endl;
		return 'N';}
		} */
	
	
	
	
	
	
	
	
	
	
	
	/*		if (array1[i+1] == array1[i] ) {
				//cout << "broke" << endl;
				return 'N';
				checkW = false;
				checkV = false;
				break;}
	
			else if (array1[i+1] > array1[i] ) {
				checkW = true;}
				//cout << "M" << endl;
			else if (array1[i+1] < array1[i])	{
				checkV = true;}
				//cout << "V" << endl;
			else {
				//cout << "broke" << endl;
				return 'N';
				checkW = false;
				checkV = false;
				break;}}}
			if (array1[-1] == array1[-2] ) {  // this is for the last term of an odd numlength number
				//cout << "broke" << endl;
				return 'N';
				checkW = false;
				checkV = false;}
	
			else if (array1[-1] < array1[-2] ) {
				checkW = true;}
				//cout << "M" << endl;
			else if (array1[-1] > array1[-2])	{
				checkV = true;}
				//cout << "V" << endl;

	if (checkW == true)	{
			return 'M';}
	if (checkV == true)	{
			return 'V';}*/
		//}}}


	/*if (numlength % 2 == 0)	{ //even
		//cout << "test1" << endl;
		//int equalizer;
		//int help = numlength - 4;
		// equalizer = pow(10,help);  // these two will help get rid of all the digits after the fourth digit
		// cout << equalizer << endl; // 100
		int d4 = number % 10; // i only need 4 to find whether it is a mountain or not 
		number /= 10;
		int d3 = number % 10;
		number /= 10;
		int d2 = number % 10;
		number /= 10;
		
		//cout << number << endl; //120 // i need d1 to equal the fourth digit of the sequence, and to peel all the number behind it off
		//number = number / equalizer; // 
		int d1 = number % 10;
		if ( (d4 > d3) && (d3 < d2) && (d2 > d1) )	{
			return 'M';
		}	else if ( (d4 < d3) && (d3 > d2) && (d2 < d1) )	{
			return 'V';
		}	else{
			return 'N';
		}
	}else	{ //odd
		int d3 = number % 10;
		number /= 10;
		int d2 = number % 10;
		number /= 10;
		int d1 = number % 10;
		if ( (d3 < d2) && (d2 > d1) )	{
			return 'M';
		}	else if ( (d3 > d2) && (d2 < d1) )	{
			return 'V';
		}	else{
			return 'N';
		}
	} 
}*/
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int Wcounter = 0;
	int Vcounter = 0;
	int i;
	for (i = a; i <= b; i++)	{

		if (classify_mv_range_type(i) == 'M')	{

			Wcounter += 1;
		}	else if (classify_mv_range_type(i) == 'V')	{

			Vcounter += 1;
		}	else	{
			continue; 
		}
}	cout << "There are " << Wcounter << " mountain ranges and " << Vcounter << " valley ranges between " << a <<" and " << b << "." << endl;
}


 

