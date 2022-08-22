struct Coord3D {
    unsigned int x = 0, y = 0, z = 0;
};
 
class DynamicCoord3D {
    Coord3D* data;
    //data is an array of objects built from the Coord3D struct
 public:
    DynamicCoord3D(Coord3D c) : data(new Coord3D(c)) {}
 
    // value access by dereference
    const Coord3D & operator*() const { return *data; }
    Coord3D& operator*() { return *data; }
 
    // value assignment – This is NOT the copy assignment
    DynamicCoord3D& operator=(const Coord3D& c) {
        *data = c;
        return *this;
    }
 
    // TODO(student): declare and define the rule of three methods
    //copy constructor
    DynamicCoord3D(const DynamicCoord3D& data);
    //copy assignment
    DynamicCoord3D& operator=(const DynamicCoord3D& data);
    //destructor
    ~DynamicCoord3D();
    //to test
};

DynamicCoord3D::DynamicCoord3D(const DynamicCoord3D& data) {
    //allocate memory on the heap for new object that will be stored
    Coord3D* newCoord = new Coord3D[1]; //data array only holds on coordinate
    //transfer Coord3D data from DynamicCoord object being passed in
    newCoord = data.data;
    //make deep copy of this data
    this->data = newCoord;
}
//copy assignment has same syntax, returns *this
DynamicCoord3D& DynamicCoord3D::operator=(const DynamicCoord3D& data)   {
    if (this->data == data.data)    {return *this;} //check if self assignment is happening
    Coord3D* newCoord = new Coord3D[1];
    newCoord = data.data;
    this->data = newCoord;
    return *this;
}

DynamicCoord3D::~DynamicCoord3D()   {
    delete this->data;
    this->data = nullptr;
}

int main()  {
Coord3D firstPoint = {25, 35, 45};
// firstPoint := {25, 35, 45}
Coord3D secondPoint = {180, 180, 180};
// secondPoint := {180, 180, 180}
DynamicCoord3D dynamicPointOne(firstPoint);
// dynamicPointOne := {25, 35, 45}
DynamicCoord3D dynamicPointTwo(secondPoint);
// dynamicPointTwo := {180, 180, 180}
*dynamicPointOne = secondPoint;
// dynamicPointOne := {180, 180, 180}
*dynamicPointOne = firstPoint;
// dynamicPointOne := {25, 35, 45}
{
DynamicCoord3D dynamicPoint = dynamicPointTwo;
    // dynamicPoint := {180, 180, 180}
}
// dynamicPointTwo:= {180, 180, 180}
{
    DynamicCoord3D dynamicPoint = dynamicPointTwo;
    // dynamicPoint := {180, 180, 180}
    dynamicPoint = dynamicPoint;
    // dynamicPoint := {180, 180, 180}
    dynamicPoint = dynamicPointOne;
    // dynamicPoint := {25, 35, 45}
}
// dynamicPointOne := {25, 35, 45}
}