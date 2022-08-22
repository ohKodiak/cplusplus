#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char** rotateImage(char** art, unsigned int &width, unsigned int &height) {
    int i = 0;
    int j = 0;
    int oldheight = height;
    int oldwidth = width;
    width = oldheight;
    height = oldwidth;
    //to rotate, height becomes width becomes height, thus max rows witll be the width
    char** rotatedImage = new char*[height]; //allocate space for rows
    for (i = 0; i < height; i++) {
        rotatedImage[i] = new char[width]; //allocate columns in each row
        for (j = 0; j < width; j++)    {
            rotatedImage[i][j] = art[j][i]; }
    }
    return rotatedImage;}
  // Write your solution here
  // We will not grade any code outside of this function
  // Code must handle arrays of any dimensions,
  //   not just the simple example we hard coded
  //return nullptr; // update to correct result


void deleteImage(char**& art, unsigned int height) {
  // not required for exam, but writing would stop a memory leak
}

char** loadSimple(unsigned int& width, unsigned int& height) {
  /* This is a bad, non-scalable way to build an array
  
      <->
      [+]
      
  */
  
  width = 3;
  height = 2;
  char** ary = new char*[2];
  ary[0] = new char[3];
  ary[0][0] = '<';
  ary[0][1] = '-';
  ary[0][2] = '>';
  ary[1] = new char[3];
  ary[1][0] = '[';
  ary[1][1] = '+';
  ary[1][2] = ']';
  return ary;
}

void printImage(char const* const* art, unsigned int width, unsigned int height) {
    for (unsigned int row = 0; row < height; ++row) {
        for (unsigned int col = 0; col < width; ++col) {
            cout << art[row][col];
        }
        cout << endl;
    }
} 

int main() {
    unsigned int width = 0;
    unsigned int height = 0;
     
    char** art = loadSimple(width, height);

    printImage(art, width, height);
    cout << endl;
    
    art = rotateImage(art, width, height);
    printImage(art, width, height);

    //deleteImage(art, height);
}