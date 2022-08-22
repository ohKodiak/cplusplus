#include <iostream>
#include <string>
#include <array>
using namespace std;

void minusOddColumn(int** mat, int n)   {

//n is >= 1
//mat is a 2d array of non negative integers
//find column in mat with most odd numbers and replace all of its elements with -1

    int i = 0;
    int j = 0;
    int negativeCount = 0;
    int holdCol;  //hold column of most negative
    int holdMost = 0; //hold number of col
//we can change mat from here 
    for (i = 0; i < n; i++) {
        //column
        for (j = 0; j < n; j++) {
        //row
            if (mat[j][i] < 0)  {
                negativeCount += 1;}}
        if (negativeCount > holdMost)    {
            holdMost = negativeCount;
            holdCol = i;}
        if (negativeCount == holdMost)    {
            holdMost = negativeCount;
            if (i < holdCol)    {holdCol = i;}
            else{continue;}}
        negativeCount = 0;}

    for (i = 0; i < n; i++) {
        mat[i][holdCol] = -1;}

}

int main()  {

}