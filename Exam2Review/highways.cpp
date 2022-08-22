/*City.h :

class City{
private:
    string id;
    string name;
    string state;
    long long int population;
public:
    //getters for data members
    string getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getState()
    {
        return state;
    }
    long long int getPopulation()
    {
        return population;
    }
    //setters for data members
    void setId(string id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setState(string state)
    {
        this->state = state;
    }
    void setPopulation(long long int population)
    {
        this->population = population;
    }
};
Highway.h :

class Highway{
private:
    string id;
    int numCitiesCrosses;
    string *cityIds;
public:
    //getters for data members
    string getId()
    {
        return id;
    }
    int getNumCitiesCrosses()
    {
        return numCitiesCrosses;
    }
    string* getCityIds()
    {
        return cityIds;
    }
    //setters for data members
    void setId(string id)
    {
        this->id = id;
    }
    void setNumCitiesCrosses(int n)
    {
        numCitiesCrosses = n;
    }
    void setCityIds(string *ids)
    {
        cityIds = ids;
    }
};
TestCitiesHighways.h :

class TestCitiesHighways{
private:
    City *cities; //to store the city data
    int numCities; //to store the number of cities
    Highway *highways; //to store the highway data
    int numHighways; //to store the number of highways
public:
    //to set the cities and number of cities
    void setCities(City *cities,int numCities)
    {
        this->cities = cities;
        this->numCities = numCities;
    }
    //to set the highways and number of highways
    void setHighways(Highway *highways,int numHighways)
    {
        this->highways = highways;
        this->numHighways = numHighways;
    }
    //lists the cities and highways 
    void listCitiesAndHighways();
    //lists all the highways in a given state
    void listHighwaysInState(string state);
    //lists the cities crossed by a given highway
    void listCitiesCrossedByHighway(Highway highway_);
};*/