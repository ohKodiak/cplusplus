#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

const int MAX_WIDTH = 1920;  // max width of image
const int MAX_HEIGHT = 1080; // max height of image

// a Pixel struct representing a single red, green, blue pixel value for an image
struct Pixel {
  int r = 0; // red
  int g = 0; // green
  int b = 0; // blue
};

void printMenu();

void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT]);

void loadImage(const std::string filename, Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height);

void outputImage(const std::string filename, const Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height);

void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height);

void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height);

int getInteger(const std::string label, int min, int max);

#endif