#include <iostream>
#include <string>
#include "road.h"
using namespace std;

//this all works
// Member functions definitions including constructor
Road::Road(double len, double wid, int lan, std::string nam): length(len), width(wid), lanes(lan), name(nam){
// to do
}

void Road::setLength( double len ) {
   this->length = len;
   // to do
}
void Road::setWidth( double wid ) {
   this->width = wid;
   // to do
}
void Road::setLanes( int lan ) {
   this->lanes = lan;
   // to do
}

double Road::getLength( void ) {
   return length;
   // to do
}
double Road::getWidth( void ) {
   return width;
   // to do
}
int Road::getLanes( void ) {
   return lanes;
   // to do
}

std::string Road::getName() {
   return name;
    // to do
}

double Road::getSurface( void ) {
   return (lanes*width) * length;
   // to do
}
