/*
Class Zoo {

Attributes {

- name : Text

- address : Location

- menagerie : Collection { aggregation of Animal }

}

Methods {

+ Zoo(name : Text)

+ getName() : Text

+ getAddress() : Location

+ getAnimal( name : Text ) : Animal

+ addAnimal(newAnimal : Animal)

}

}*/
#include <iostream>
#include <vector>
using namespace std;
class Animal{
public:
string name;
};
class Location{

};
class Zoo {
private:
string name;
Location address;
vector<Animal> menagerie;
public:
Zoo(string name){
this->name = name;
}
string getName(){
return name;
}

Location getAddress(){
return address;
}
Animal getAnimal(string name){
Animal animal;
for(int i=0;i<menagerie.size();i++){
if(menagerie[i].name.compare(name) == 0){
animal = menagerie[i];
}
}
return animal;
}

void addAnimal( Animal newAnimal ){
menagerie.push_back(newAnimal);
}

};