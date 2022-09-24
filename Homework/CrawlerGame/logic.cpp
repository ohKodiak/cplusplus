#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream ifs(fileName); 
    if (!ifs.is_open())    {return nullptr;}

    //delegate values, check to make sure they didnt fail
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
    if (maxCol > INT32_MAX / maxRow)    {return nullptr;}

    //get array values from file
    int row = 0;
    int col = 0;
    int iterationCounter = 0;
    int wayOutCounter = 0;
    int dimensions = maxRow * maxCol;
    char eofbit = '\0';
    //create level pointer
    char** level = createMap(maxRow, maxCol); 
    for (row = 0; row < maxRow; row++)  {
        for (col = 0; col < maxCol; col++)  {

            //count iteration
            iterationCounter += 1;

            //check for fail bit
            ifs >> level[row][col];
            if (ifs.fail()) {return nullptr;}
            if (ifs.eof())  { //gets here if you take 2 off
                if (iterationCounter < dimensions)   { deleteMap(level,maxRow); return nullptr;}}

            //check for valid char 
            if (level[row][col] == TILE_AMULET) {continue;}
            else if (level[row][col] == TILE_DOOR) {wayOutCounter += 1; continue;}
            else if (level[row][col] == TILE_EXIT) {wayOutCounter += 1; continue;}
            else if (level[row][col] == TILE_MONSTER) {continue;}
            else if (level[row][col] == TILE_OPEN) {continue;}
            else if (level[row][col] == TILE_PILLAR) {continue;}
            else if (level[row][col] == TILE_TREASURE) {continue;}
            else if (level[row][col] == TILE_PLAYER) {continue;} //unlikely
            //check bad value
            else    { deleteMap(level,maxRow); return nullptr;} }}
    //edge case 
    //cout << iterationCounter << endl;
    //if (iterationCounter != dimensions)   { deleteMap(level,maxRow); return nullptr;}
    //player cannot replace anything, must be on blank cell
    if (level[player.row][player.col] == TILE_DOOR)    {wayOutCounter -= 1;}
    if (level[player.row][player.col] == TILE_EXIT)    {wayOutCounter -= 1;}
    if (level[player.row][player.col] != TILE_OPEN) {deleteMap(level,maxRow); return nullptr;}
    level[player.row][player.col] = TILE_PLAYER;
    
    //check for way out, not needed
    if (wayOutCounter < 1)  {
        deleteMap(level,maxRow);
        return nullptr;}

    //want reading a number otuside of loop to fail 
    ifs >> eofbit;
    if (!ifs.fail())    {
        deleteMap(level,maxRow);
        return nullptr;}

    return level;}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 *////done
void getDirection(char input, int& nextRow, int& nextCol) {
    tolower(input);
    if (input == 'w')   {nextRow -= 1;}//up from our perspective, so a lower index
    if (input == 's')   {nextRow += 1;}//down
    if (input == 'a')   {nextCol -= 1;}//left
    if (input == 'd')   {nextCol += 1;}//right
    //if (input == 'e')   {}
    //account for negative or large numbers?
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 *///done
char** createMap(int maxRow, int maxCol) {
    //ints will not be anything other than numbers and will not be greater than INT32_MAX
    if (maxRow < 0) {return nullptr;}
    if (maxCol < 0) {return nullptr;} // less than 1?
    //map is 2D array, of capacity Max row and max column
    //go by row, give dimensions
    char** map = new char* [maxRow]; //pointer initalized on the heap
    int index = 0;
    int j = 0;
    for (index = 0; index < maxRow; index++)    {
        map[index] = new char[maxCol];  //max col is the capacity of the array inserted into the map array at index i
        for (j = 0; j < maxCol; j++)  {  
            map[index][j] = TILE_OPEN;}} //TITLE_OPEN is global variable //segmentation fault on this line
    return map;}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 *///missing one test case
void deleteMap(char**& map, int& maxRow) {
    //update maxRow to 0
    //map should be null ptr
    if (map == nullptr) {
        maxRow = 0;
        return;}
    int index = 0;
    for (index = 0; index < maxRow; index++)    { 
        delete[] map[index];
        map[index] = nullptr;}
    delete[] map;
    maxRow = 0;
    map = nullptr;}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 *///not done

char** resizeMap(char** map, int& maxRow, int& maxCol) {
    //conditions
    if (maxRow < 1) {return nullptr;}
    if (maxCol < 1) {return nullptr;}
    if (maxRow > (INT32_MAX / 2) ) {return nullptr;}
    if (maxCol > (INT32_MAX / 2) ) {return nullptr;}
    if (map == nullptr) {return nullptr;}
    int oldRow = maxRow;
    int oldCol = maxCol;
    int newmaxRow = maxRow * 2; //new capacities
    int newmaxCol = maxCol * 2; 
    char** newMap = new char*[newmaxRow];
    int i = 0;
    //initializing new map
    for (i = 0; i < newmaxRow; i++)    {
        newMap[i] = new char[newmaxCol];}

    //Creating A - (0,0), simply copies over old values up until previous max value
    int row = 0;
    int column = 0;
    for (row = 0; row < oldRow; row++)  {
        for (column = 0; column < oldCol; column++) {
            newMap[row][column] = map[row][column];}}

    //Creating B - (1,0) - copies over values starting at previous column max, thus newmax - oldmax
    //same row, different columns
    //same row index, different columns
    for (row = 0; row < oldRow; row++) {
        for (column = oldCol; column < newmaxCol; column++) {
            if(map[row][column - oldCol] == TILE_PLAYER){newMap[row][column] = TILE_OPEN;}
            else{newMap[row][column] = map[row][column - oldCol];}  }}

    //Creating C - (0,1) - same column, change in the row
    for (row = oldRow; row < newmaxRow; row++)  {
        for (column = 0; column < oldCol; column++) {
            if(map[row - oldRow][column] == TILE_PLAYER){newMap[row][column] = TILE_OPEN;}
            else{newMap[row][column] = map[row - oldRow][column];}  }}
    
    for (row = oldRow; row < newmaxRow; row++)  {
        for (column = oldCol; column < newmaxCol; column++) {
            if(map[row - oldRow][column-oldCol] == TILE_PLAYER) {newMap[row][column] = TILE_OPEN;}
            else{newMap[row][column] = map[row - oldRow][column-oldCol];}   }}

    deleteMap(map,oldRow); 
    maxRow *= 2;
    maxCol *= 2;
    return newMap;}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 *///done
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
  
    if (nextRow < 0)    {return STATUS_STAY;} //moves out of bounds
    if (nextRow >= maxRow)  {return STATUS_STAY;} //starts at 0 so equal to is an idex out of bounds
    if (nextCol < 0)    {return STATUS_STAY;}
    if (nextCol >= maxCol)   {return STATUS_STAY;}

    if (map[nextRow][nextCol] == TILE_PILLAR)   {return STATUS_STAY;}  //objects you cant move onto
    if (map[nextRow][nextCol] == TILE_MONSTER)  {return STATUS_STAY;}
    //all of these will require you to change previous position
    if (map[nextRow][nextCol] == TILE_EXIT) {
        if(player.treasure > 0) {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow; player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_ESCAPE;}
        else    {return STATUS_STAY;}}

    if (map[nextRow][nextCol] == TILE_TREASURE) 
        {player.treasure += 1; 
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow; player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_TREASURE;}

    if (map[nextRow][nextCol] == TILE_AMULET) 
        {map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow; player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_AMULET;}

    if (map[nextRow][nextCol] == TILE_DOOR) 
        {map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow; player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_LEAVE;}

    if (map[nextRow][nextCol] == TILE_OPEN) 
        {map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow; player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_MOVE;}
    return 0;}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 *///not done
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //loop left right up down until you get pillar, monster, or wall 
    //if monster and pillar are true in the same loop, then no change to position, return false
    //if pillar true and monster false, no change to position, return false
    //if monster true and pillar false, monster moves in direction of player, return false
    // if monster true and pillar false, and monster +-1 in the direction of player = player_tile, return true
    // you want to break if you see either a pillar or a monster
    int row = 0;
    int col = 0;
    bool pillar = false;
   // bool monster = false;
    bool attack = false;
    //up from player, do not need to change column
    for (row = player.row - 1; row >= 0; row--)  {  
        if (map[row][player.col] == TILE_PILLAR)    {pillar = true; break;} 
        if (map[row][player.col] == TILE_MONSTER)   {
            if (pillar != true)    { //monster sees traveler and can move towards him
                if (map[row+1][player.col] == TILE_PLAYER)  {
                    attack = true;}
                map[row][player.col] = TILE_OPEN;
                map[row+1][player.col] = TILE_MONSTER;}}}
    pillar = false; //reinitialize pillar

    //down from player, do not need to change column
    for (row = player.row + 1; row < maxRow; row++)  {  //maxRow index is not inclusive?
        if (map[row][player.col] == TILE_PILLAR)    {pillar = true; break;} 
        if (map[row][player.col] == TILE_MONSTER)   {
            if (pillar != true)    {
                if (map[row - 1][player.col] == TILE_PLAYER)  {
                    attack = true;}
                map[row][player.col] = TILE_OPEN;
                map[row - 1][player.col] =  TILE_MONSTER;}}}
    pillar = false; //reinitialize pillar

    //left from player, do not need to change row
    for (col = player.col - 1; col >= 0; col--) {
        if (map[player.row][col] == TILE_PILLAR)    {pillar = true; break;} 
        if (map[player.row][col] == TILE_MONSTER)   {
            if (pillar != true)    {
                if (map[player.row][col + 1] == TILE_PLAYER)  {
                    attack = true;}
                map[player.row][col] = TILE_OPEN;
                map[player.row][col + 1] =  TILE_MONSTER;}}}
    pillar = false; // reinitialize

    //right from player, do not need to change row
    for (col = player.col + 1; col < maxCol; col++) {
        if (map[player.row][col] == TILE_PILLAR)    {pillar = true; break;} 
        if (map[player.row][col] == TILE_MONSTER)   {
            if (pillar != true)    {
                if (map[player.row][col - 1] == TILE_PLAYER)  {
                    attack = true;}
                map[player.row][col] = TILE_OPEN;
                map[player.row][col - 1] =  TILE_MONSTER;}}}
    
    return attack;}
