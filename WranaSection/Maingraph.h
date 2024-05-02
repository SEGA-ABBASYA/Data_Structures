#ifndef MAINGRAPH_H
#define MAINGRAPH_H
#include <vector>
#include <set>
#include "Graph.h"
#include "location.h"
class MainGraph
{
    vector<Graph> Floors;
    int maxfloor = 0;
    vector<Location>stairs;

public:
    MainGraph();
    void addfloor(vector<vector<char>>);
    vector<pair<int,pair<int,int>>> Search(int ,int ,int,Location);

};

#endif // MAINGRAPH_H
