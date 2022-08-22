#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <string>

class Road {
   public:
      Road(double len, double wid, int lan, std::string nam);
      void setLength( double len );
      void setWidth( double wid );
      void setLanes( int lan );
      double getLength( void );
      double getWidth( void );
      int getLanes( void );
      std::string getName();
      double getSurface( void );

   private:
      double length;
      double width;
      int lanes;
      std::string name;
};
#endif
