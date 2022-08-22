#include <iostream>
#include <stdexcept> 
using namespace std;
#include <limits.h>
#include <string>
#include <sstream>
#include <fstream>
#include <fstream>
#include "logiccopy.h"

char** createMap(int maxRow, int maxCol) {
    //ints will not be anything other than numbers and will not be greater than INT32_MAX
    if (maxRow < 0) {return nullptr;}
    if (maxCol < 0) {return nullptr;} // less than 1?
    //map is 2D array, of capacity Max row and max column
    //go by row, give dimensions
    char** map = new char*[maxRow]; //pointer initalized on the heap
    int index = 0;
    int j = 0;
    for (index = 0; index < maxRow; index++)    {
        map[index] = new char[maxCol];}  //max col is the capacity of the array inserted into the map array at index i
        for (j = 0; j < maxCol; j++)    {
            map[index][j] = TILE_OPEN;} //TITLE_OPEN is global variable 
    return map;}

void deleteMap(char**& map, int& maxRow) {
    //update maxRow to 0
    //map should be null ptr
    int index = 0;
    for (index = 0; index < maxRow; index++)    { 
        delete[] map[index];
        map[index] = nullptr; }
    delete[] map;
    maxRow = 0;
    map = nullptr;}

char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream ifs(fileName);
    //possible malicious input
    //inputs larger than intmax
    //player value larger than max
    //negative inputs
    //less inputs than maxRow and maxCol, check number of iterations and see if it equals product of maxrow and max col
    //no exit or door, will have to find them while iterating
    //if there is an exit, must there be treasure??
    //how to check against invalid tile?????

    if (!ifs.is_open())    {return nullptr;}
    //delegate values, check to make sure they didnt fail
    if (ifs.fail()) {return nullptr;}
    ifs >> maxRow;
    if (ifs.fail()) {return nullptr;}
    ifs >> maxCol;
    if (ifs.fail()) {return nullptr;}
    ifs >> player.row;
    if (ifs.fail()) {return nullptr;}
    ifs >> player.col;
    if (ifs.fail()) {return nullptr;}

    //checks for valie row, col, maxRow, and maxCol values
    if (player.row >= maxRow)    {return nullptr;}
    if (player.col >= maxCol)    {return nullptr;} //may not be equal to
    if (maxRow < 1)    {return nullptr;}
    if (maxCol < 1)    {return nullptr;}
    if (player.row < 0) {return nullptr;}
    if (player.col < 0) {return nullptr;}
    if (maxRow > INT32_MAX / maxCol)    {return nullptr;} //overflow

    //get array values from file
    int row = 0;
    int col = 0;
    int iterationCounter = 0;
    int wayOutCounter = 0;
    int dimensions = maxRow * maxCol;
    //create level pointer
    char** level = createMap(maxRow,maxCol);
    for (row = 0; row < maxRow; row++)  {
        for (col = 0; col < maxCol; col++)  {
            if (ifs.eof())  {
                if (iterationCounter < dimensions)   { deleteMap(level,maxRow); return nullptr;}}
            else{
            //count iteration
            iterationCounter += 1;
            //check for fail bit
            if (ifs.fail()) {return nullptr;}
            ifs >> level[row][col];
            //check for valid char
            if (level[row][col] == TILE_AMULET) {continue;}
            if (level[row][col] == TILE_DOOR) {wayOutCounter += 1; continue;}
            if (level[row][col] == TILE_EXIT) {wayOutCounter += 1; continue;}
            if (level[row][col] == TILE_MONSTER) {continue;}
            if (level[row][col] == TILE_OPEN) {continue;}
            if (level[row][col] == TILE_PILLAR) {continue;}
            if (level[row][col] == TILE_TREASURE) {continue;}
            //check bad value
            else    { deleteMap(level,maxRow); return nullptr; }
            }}}
    //edge case
    if (level[player.row][player.col] == TILE_DOOR)    {wayOutCounter -= 1;}
    if (level[player.row][player.col] == TILE_EXIT)    {wayOutCounter -= 1;}
    level[player.row][player.col] = TILE_PLAYER;  
    //check for way out
    if (wayOutCounter < 1)  {
        deleteMap(level,maxRow);
        return nullptr;}

    return level;}
int main() {
if (loadLevel == nullptr) {
  cout << "null" << endl;}
else{
  cout << "not null" << endl;}
}


