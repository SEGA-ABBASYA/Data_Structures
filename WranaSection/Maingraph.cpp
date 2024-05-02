#include "Maingraph.h"

MainGraph::MainGraph() {}

vector<pair<int,pair<int,int>>> MainGraph::Search(int floor,int x,int y,Location L)
{
    vector<pair<int,pair<int,int>>> ans;
    if (floor==L.getfloor())
    {
        vector<pair<int,int>>curr = Floors[floor].Search(x,y,L);
        if (curr.empty())
        {
            set<Location>CanReachStairs,CantReachStairs;
            vector<pair<int,int>>v[3],ansabove,ansbelow;
            for (int i =0;i < stairs.size() ;i++)
            {
                v[i] = Floors[floor].Search(x,y,stairs[i]);
                if (v[i].size())
                {
                    CanReachStairs.insert(stairs[i]);
                }
                else
                    CantReachStairs.insert(stairs[i]);
            }
            if (floor != maxfloor - 1)
            {
                for (auto i : CanReachStairs)
                {
                    for (auto j : CantReachStairs)
                    {
                        ansabove = Floors[floor+1].Search;
                    }
                }
            }
        }
        for (auto i : curr)
        {
            ans.push_back({floor,i});
        }
        return ans;
    }
}
