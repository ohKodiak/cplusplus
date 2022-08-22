#include <iostream>
using namespace std;
struct Point {
  int x;
  int y;
};

class Polygon {


protected:
  Point* vertices;
  int numVertices; //size

public:
  Polygon(); // constructor
  virtual ~Polygon(); // destructor  
  Polygon(const Polygon& poly);  // copy constructor
  //copy assignment always checks for self assignment
  //allocates new memory to prevent a shallow copy
  //copy assignment uses *this
  Polygon& operator=(const Polygon& poly);  // copy assignment operator
  // other member functions
  void addVertex(int x, int y);
  Point* getVertices() const    {return this->vertices;};
  int getNumVertices() const    {return this->numVertices;};
  virtual void print(); // outputs the list of vertices (x1, y1), (x2, y2), ... 
};

Polygon::Polygon(): vertices(nullptr), numVertices(0)  {}
Polygon::~Polygon() {
    //need to loop through array and delete values 
    delete vertices;
    vertices = nullptr;
    numVertices = 0;
}
Polygon::Polygon(const Polygon& poly)   {
  this->numVertices = poly.getNumVertices();
  Point* newArray = new Point[numVertices];
  int i = 0;
  for (i = 0; i < numVertices; i++) {
    newArray[i] = poly.vertices[i];}
  vertices = newArray;
}
Polygon& Polygon::operator=(const Polygon& poly)    {
    this->numVertices = poly.getNumVertices();
  Point* newArray = new Point[numVertices];
  int i = 0;
  for (i = 0; i < numVertices; i++) {
    newArray[i] = poly.vertices[i];}
  delete[] this-> vertices;
  this->vertices = newArray;
  return *this;
}
void Polygon::addVertex(int x, int y)   {
  //create point struct
  //add to array
  Point newPoint;
  newPoint.x = x;
  newPoint.y = y;
  this->numVertices += 1; //changes num vertices
  Point* newArray = new Point[numVertices];
  for (int i = 0; i < numVertices - 1; i++) {
    newArray[i] = this->vertices[i];}
  newArray[numVertices-1] = newPoint; //adds new point to end
  delete[] vertices;
  vertices = newArray; //changes array
}
void Polygon::print() {
  for (int i = 0; i < this->numVertices; i++) {
    cout << vertices[i].x << "," << vertices[i].y << endl;
  }
}

class rectangle: public Polygon {
  public:
  //if you were going to override a constructor
  //you would do this:
  //rectangle():  Polygon() {};
  //rectangle (num): Polygon(num) {};
  //if rectangle took different parameters example:
  //class Hybrid: public auto {
  //private:
  //double battery;
  //public:
  //Hybrid(string make, int model, double battery): auto(make, modelyear), battery(battery)
  
  int setArea();
  int getArea() {return this-> area;};
  void print() override;
  private:
  int area;
};

int rectangle::setArea()  {
  int minX = INT32_MAX;
  int maxX = 0;
  int minY = INT32_MAX;
  int maxY = 0;
  int y = 0;
  int x = 0;
  int totalarea;
  for ( int i = 0; i < this->numVertices; i++)  {
    if (vertices[i].x < minX) {minX = vertices[i].x;}
    if (vertices[i].x > maxX) {maxX = vertices[i].x;}
  }
  for ( int i = 0; i < this->numVertices; i++)  {
    if (vertices[i].y < minY) {minY = vertices[i].y;}
    if (vertices[i].y > maxY) {maxY = vertices[i].y;}
  }
  x = maxX - minX;
  y = maxY - minY;
  totalarea = x * y;
  this->area = totalarea;
  return totalarea;}

void rectangle::print()  {
  Polygon::print();
  cout << "the area of the rectangle is " << this->area << endl;}





int main() {
  Polygon p1;
  p1.addVertex(1, 2);
  p1.addVertex(2, 5);
  p1.addVertex(3, 4);
  p1.addVertex(3, 3);
  //p1.print();
  Polygon p2(p1);
  p2.addVertex(3, 2);
  //p2.print();
  Polygon p3;
  p3 = p1;
  p3.addVertex(2, 2);
  //p3.print();
  rectangle p4;
  p4.addVertex(1,1);
  p4.addVertex(1,3);
  p4.addVertex(5,1);
  p4.addVertex(5,3);
  p4.setArea();
  p4.print();

}
