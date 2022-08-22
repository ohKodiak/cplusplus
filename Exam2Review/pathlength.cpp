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
    //cout << maxRow << endl;

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



int pathLength(int** distance, int n, int* path, int m)   {
    int i = 0;
    int j = 0;
    int total = 0;
    //12424553
    for ( i = 0; i < m-1; i++)  { //must be m-1 because you're using i+1 while iterating
        total += distance[path[i]][path[i+1]];}
    return total;}

int main()  {
    int maxRow = 0;
    int maxCol = 0;
    int** array =  GetArray("test.txt", maxRow, maxCol);
    int m = 6;
    int path[6] = {0,1,0,3,2,0};
    cout << pathLength(array, maxRow, path, m) << endl;
    
   /* int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    int five = 5;
    int d1[5] = {3,6,76,37,87}; //columns
    int d2[5] = {30,0,45,100,50};
    int d3[5] = {10,45,0,85,20};
    int d4[5] = {70,100,85,0,100};
    int d5[5] = {10,50,20,100,0};
    int* distance[1] = {}; //rows
    distance[0] = d1;
    distance[1] = d2;
    distance[2] = d3;
    distance[3] = d4;
    distance[4] = d5;
    //distance[1] is a pointer to d1
    //to cout d1, you have to dereference that pointer to d1
    //
    cout << *distance << endl;
    // GIVES THIS 0x16b1e3260
    for ( int i = 0; i < 5; i++)    {
        for ( int j = 0; j < 5; j++)    {
        cout << *distance[i] << endl; 
        cout << distance[i][j] << endl;}} */

// 0x16f70f1c0
//0x16f70f200
//0x16f70f240
//0x16f70f280
//0x16f70f2c0
    //int dist[5] = {};
    //dist[5] = {{0,30,10,70,10}, {30,0,45,100,50}, {10,45,0,85,20}, {70,100,85,0,100},{10,50,20,100,0}};

    }

