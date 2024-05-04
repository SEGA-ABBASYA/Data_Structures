#ifndef MAINGRAPH_H
#define MAINGRAPH_H
#include <vector>
#include <set>
#include "Graph.h"
#include "Location.h"
class MainGraph
{
    vector<Graph> Floors;
    int maxfloor = 0;

public:
    vector<Location>stairs;
    MainGraph();
    void addfloor(vector<string>);
    vector<pair<int, pair<int, int>>> SearchBig(int, int, int, Location);

};

#endif // MAINGRAPH_H
