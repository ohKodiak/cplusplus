#include <iostream>
using std::cin, std::cout, std::endl;
#include "road.h"


int main() {
   Road road(160.0, 23.0, 2, "Frontage");

   // Get the road name
   cout << "Name of road : " << road.getName() <<endl;

   // Get the road length
   cout << "Length of road : " << road.getLength() <<endl;
   // Change the road length
   road.setLength(82.0);
   cout << "New length of road : " << road.getLength() <<endl;


   // Get the road width
   cout << "Width of road : " << road.getWidth() <<endl;
   // Change the road width
   road.setWidth(30.6);
   cout << "New width of road : " << road.getWidth() <<endl;


   // Get the number of lanes
   cout << "Lanes of road : " << road.getLanes() <<endl;
   // Change the road number of lanes
   road.setLanes(4);
   cout << "New lanes of road : " << road.getLanes() <<endl;

   // Get the road surface
   cout << "Surface of road : " << road.getSurface() <<endl;

   return 0;
}
