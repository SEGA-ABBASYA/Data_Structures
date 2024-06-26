#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <map>
#include "Location.h"
class Cell
{

public:
    bool HasLocation = false;
    string location;
    bool Passable;
    void Update(string locationstring);
};

class Graph
{

public:
    vector<vector<Cell>>maingraph;
    int rows, cols;
    vector<string>locations;
    bool inborders(int x, int y, int limitx, int limity);
    Graph(int rows, int cols, vector<string>grid);
    vector<pair<int, int>>Search(int startx, int starty, Location l);
    void addlocation(int x, int y, Location l);
};

#endif // GRAPH_H
