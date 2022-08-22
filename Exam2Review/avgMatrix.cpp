#include <iostream>
#include <string>
#include <array>
#include <fstream>
using namespace std;


double** GetArray(const string& fileName, int& maxRow, int& maxCol )  {
    ifstream ifs(fileName); 
    if (!ifs.is_open()) {
        cout << "not opening" << endl;
    }


    ifs >> maxRow;
    if (ifs.fail()) {cout << "i failed" << endl;}


    ifs >> maxCol;
    if (ifs.fail()) {}

    int i =  0;
    int j = 0;
    double** outArray = new double* [maxRow];
    for (i = 0; i < maxRow; i++)   {
        outArray[i] = new double [maxCol];
        for (j = 0; j < maxCol; j++)    {
            ifs >> outArray[i][j];
        }}
    return outArray;}

void avgMatrix (double** inArray, int rows, int columns, double** outArray) {
    int i = 0;
    int j = 0;
    int counter = 0;
    double total = 0;
    double avg = 0;
    for (i = 0; i < rows; i++)  {
        for (j = 0; j < columns; j++)   {
            //sides
            if (i != 0) { //top  (y,x)
                total += inArray[i-1][j]; 
                counter += 1;}
            if (i != rows - 1)  { //bottom
                total += inArray[i+1][j];
                counter += 1;}
            if (j != 0) { //left
                total += inArray[i][j-1];
                counter += 1;}
            if (j != columns - 1)  { //right
                total += inArray[i][j+1];
                counter += 1;}
            //diagonal
            if (i != 0 && j != 0)   { //top left
                total += inArray[i-1][j-1];
                counter += 1;}
            if (i != 0 && j != columns-1)   { //top right
                total += inArray[i-1][j+1];
                counter += 1;}
            if (i != rows-1 && j != 0)   { //bottom left
                total += inArray[i+1][j-1];
                counter += 1;}
            if (i != rows-1 && j != columns -1)   { //bottom right
                total += inArray[i+1][j+1];
                counter += 1;}
            
        avg = total / counter;
        outArray[i][j] = avg; 
        total = 0;
        avg = 0;
        counter = 0;
            }}}

int main()  {
    int maxRow = 0;
    int maxCol = 0;
    double** inArray = GetArray("test.txt",maxRow,maxCol);
    double** outArray = GetArray("test.txt",maxRow,maxCol);
    avgMatrix(inArray, maxRow, maxCol, outArray);
    for (int i = 0; i < maxRow; i++)    {
        for (int j = 0; j < maxCol; j++)    {
            cout << outArray[i][j] << endl;
        }
    }

}