#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;

// TODO Write this function
int energy(const Pixel *const*image, int col, int row, int width, int height)
{
  //initialize variables
  int below = 0;
  int above = 0;
  int toright = 0;
  int toleft = 0;
  int ry = 0;
  int gy = 0;
  int by = 0;
  int rx = 0;
  int gx = 0;
  int bx = 0;
  int ytotal = 0;
  int xtotal = 0;
  int energy = 0;
  // 3pieces: non border, border, and corners
  //if you calculate separately, you dont need to calculate individual corners
  // checking y pieces first
  if (height > 1)  {
    if (row == height - 1) { //bottom
      above = row - 1; 
      below = 0; // wraps around, gives top value
    }
    else if (row == 0) { //top
      above = height - 1; // wraps around, gives bottom value
      below = row + 1;
    }
    else { //middle
      above = row - 1;
      below = row + 1;
    }
  ry = abs(image[col][above].r - image[col][below].r);
  gy = abs(image[col][above].g - image[col][below].g);
  by = abs(image[col][above].b - image[col][below].b);
  ytotal = pow(ry,2) + pow(gy,2) + pow(by,2); //makes calculation
  }
  if (height <= 1) {ytotal = 0;} //no gradient

  if (width > 1)  {
    if (col == width - 1) { //right border
      toleft = col - 1;
      toright = 0;
    }
    else if (col == 0) { //left border
      toleft = width - 1;
      toright = col + 1;
    }
    else { //middle
      toleft = col - 1;
      toright = col + 1;
    }
  rx = abs(image[toright][row].r - image[toleft][row].r);
  gx = abs(image[toright][row].g - image[toleft][row].g);
  bx = abs(image[toright][row].b - image[toleft][row].b);
  xtotal = pow(rx,2) + pow(gx,2) + pow(bx,2);
  }
  if (width <= 1) {xtotal = 0;} //no gradient

  energy = xtotal + ytotal;
  return energy;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const*image, int start_col, int width, int height, int* seam)
{ int totalenergy = 0;
  int leftenergy = 0; 
  int rightenergy = 0;
  int centergy = 0; // pun
  int iterationenergy = 0;
  int row = 0; // y component
  seam[0] = start_col;
  totalenergy = energy(image,start_col,0,width, height);
  for (row = 1; row < height; row++)  { //row starts at 1 because we are looking under the value of interest

  //edge case in the event that width is 1
    if ((start_col == 0 ) && (start_col == width - 1))  {
      leftenergy = INT32_MAX;
      rightenergy = INT32_MAX; //row is same, change column
      centergy = energy(image, start_col, row, width, height);}
    
    else if (start_col == 0) { //right border
      rightenergy = INT32_MAX;
      leftenergy = energy(image, start_col + 1, row, width, height); //row is same, change column
      centergy = energy(image, start_col, row, width, height);}

    else if (start_col == width - 1) { //left border
      leftenergy = INT32_MAX; //row is same, change column
      rightenergy = energy(image, start_col - 1, row, width, height); //row is same, change column
      centergy = energy(image, start_col, row, width, height);}
    
    else { // middle 
      rightenergy = energy(image, start_col - 1, row, width, height);
      leftenergy = energy(image, start_col + 1, row, width, height); //row is same, change column
      centergy = energy(image, start_col, row, width, height);}

  //find smallest, change column
    if ((centergy <= leftenergy) && (centergy <= rightenergy)){ //prefers going center
      //start_col stays the same
      iterationenergy = centergy;}

    else if ((leftenergy <= rightenergy) && (leftenergy < centergy)){
      start_col += 1; //+=1 
      iterationenergy = leftenergy;}

    else  { //doesnt like going right, last resort
      start_col -= 1; //-=1 
      iterationenergy = rightenergy;}


    totalenergy += iterationenergy; //add to total energy
    seam[row] = start_col;  //load seam array
}
  return totalenergy;
}

// TODO Write this function
void removeVerticalSeam(Pixel **image, int& width, int height, int *verticalSeam)
{ int row = 0;
  int col = 0;
  int newindex = 0;
  //int newwidth = width - 1;
  //vertical seam is an array of columns, youll have to loop through all the rows and use vertical seam to tell you which column
  for (row = 0; row < height; row++){
    for (col = verticalSeam[row]; col < width - 1; col++)  { //iterates through vertical seam
      newindex = col + 1;
      image[col][row] = image[newindex][row];}  //overwrites current spot with one a little larger 
      }
  //decreases length of width by one
  width -= 1;}

// TODO Write this function for extra credit
int getHorizontalSeam(const Pixel *const*image, int start_row, int width, int height, int* seam)
{ (void) image; (void) start_row; (void) width; (void) height; (void) seam;
  return 0;
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int& height, int *horizontalSeam)
{ (void) image; (void) width; (void) height; (void) horizontalSeam;
  
}

int *findMinVerticalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first col (index 0)
  int *minSeam = new int[height]{0};
  int minDist = getVerticalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[height]{0};
  int candidateDistance = -1; // invalid distance

  // start at second col (index 1) since we initialized with first col (index 0)
  for (int col = 1; col < width; ++col)
  {
    candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

    if (candidateDistance < minDist)
    { // new min
      //  swap min & candidate
      minDist = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

  // clean up 
  delete [] candidateSeam;

  return minSeam;
}

int *findMinHorizontalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first row (index 0)
  int *minSeam = new int[width]{0};
  int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[width]{0};
  int candidateDistance = -1; // invalid distance

  // start at second row (index 1) since we initialized with first row (index 0)
  for (int row = 1; row < height; ++row)
  {
    candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

    if (candidateDistance < minDistance)
    { // new minimum
      //  swap min and candidate seams
      minDistance = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

    // clean up 
  delete [] candidateSeam;

  return minSeam;
}

Pixel **createImage(int width, int height)
{
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width] {}; // initializes to nullptr

  for (int col = 0; col < width; ++col)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    try
    {
      image[col] = new Pixel[height];
    }
    catch (std::bad_alloc &e)
    {
      // clean up already allocated arrays
      for (int i = 0; i < col; ++i)
      {
        delete[] image[i];
      }
      delete[] image;
      // rethrow
      throw e;
    }
  }

  // initialize cells
  // cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i];
  }
  delete[] image;
  image = nullptr;
  cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

Pixel ** loadImage(string filename, int &width, int &height)
{
  cout << "Start loadImage..." << endl;
  // remove
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    throw std::invalid_argument("Failed to open input file (" + filename + ")");
  }

  string type;
  ifs >> type; // should be P3
  if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
  {
    throw std::domain_error("Not PPM type P3 (" + type + ")");
  }
  ifs >> width;
  // cout << "w and h: " << w << " " << h << endl;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for width");
  }
  if (width <= 0)
  {
    ostringstream oss;
    oss << "Width in file must be greater than 0 (" << width << ")";
    throw std::domain_error(oss.str());
  }

  ifs >> height;
  if (ifs.fail())
  {
    cout << "Read non-integer value for height" << endl;
  }
  if (height <= 0)
  {
    ostringstream oss;
    oss << "Height in file must be greater than 0 (" << height << ")";
    throw std::domain_error(oss.str());
  }

  int colorMax = 0;
  ifs >> colorMax;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for max color value");
  }
  if (colorMax != 255)
  {
    ostringstream oss;
    oss << "Max color value must be 255 (" << colorMax << ")";
    throw std::domain_error(oss.str());
  }

  // load image throws exceptions but we will let them pass through
  Pixel **image = createImage(width, height);

  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "Pixel(" << col << ", " << row << ")" << endl;
      ifs >> image[col][row].r;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for red");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for red (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].g;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for green");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for green (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].b;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for blue");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for blue (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }
    }
  }
  cout << "End loadImage..." << endl;
  return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
  cout << "Start outputImage..." << endl;
  // remove code
  // declare/define and open output file stream with filename
  ofstream ofs(filename);
  // ensure file is open
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Error: failed to open output file - " + filename);
  }
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
  cout << "End outputImage..." << endl;
}