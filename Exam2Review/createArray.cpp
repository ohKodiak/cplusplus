#include <iostream>
#include <string>
#include <array>
#include <fstream>
using namespace std;


int** GetArray(const string& fileName, int& maxRow, int& maxCol )  {
    ifstream ifs(fileName); 
    if (!ifs.is_open()) {
        cout << "not opening" << endl;
    }


    ifs >> maxRow;
    if (ifs.fail()) {cout << "i failed" << endl;}
    cout << maxRow << endl;

    ifs >> maxCol;
    if (ifs.fail()) {}

    int i =  0;
    int j = 0;
    int** outArray = new int* [maxRow];
    for (i = 0; i < maxRow; i++)   {
        outArray[i] = new int [maxCol];
        for (j = 0; j < maxCol; j++)    {
            ifs >> outArray[i][j];
        }}
    return outArray;}


int main()  {
    int maxRow = 0;
    int maxCol = 0;
    int** array =  GetArray("test.txt", maxRow, maxCol);

    for ( int i = 0; i < maxRow; i++)    {
        for (int j = 0; j < 6; j++) {
        cout << array[i][j] << endl;}}}

