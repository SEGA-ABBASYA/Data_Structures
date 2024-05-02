#ifndef LOCATION_H
#define LOCATION_H
#include <string>
using namespace std;

class Location
{
    // zero for the ground floor
    int floor;

    //checks if it is a hall or not
    bool hall;

    //location name
    string name;

    //index (x,y)
    pair<int, int> node;

public:
    Location();
    Location(int, bool, string, pair<int, int>);

    void setFloor(int);
    void setHall(bool);
    void setName(string);
    void setNode(pair<int, int>);

    int getFloor();
    bool getHall();
    string getName();
    pair<int, int> getNode();

    ~Location();
};

#endif // LOCATION_H
