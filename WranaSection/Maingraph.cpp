#include "Maingraph.h"

void MainGraph::addfloor(vector<string> grid)
{
    Floors.push_back(Graph(grid.size(), grid[0].size(), grid));
    maxfloor++;
}
MainGraph::MainGraph() {}

vector<pair<int, pair<int, int>>> MainGraph::SearchBig(int floor, int x, int y, Location L)
{
    //0 -> underground (backrooms)
    //1 -> ground
    //2 -> first lvl
    vector<pair<int, pair<int, int>>> ans;
    if (floor == L.getFloor())
    {
        vector<pair<int, int>>curr = Floors[floor].Search(x, y, L);
        if (curr.empty())
        {
            set<int>CanReachStairs, CantReachStairs;
            int indxwon;
            vector<pair<int, int>>v[3], ansabove, ansbelow;
            for (int i = 0;i < stairs.size();i++)
            {
                v[i] = Floors[floor].Search(x, y, stairs[i][floor]);
                if (v[i].size())
                {
                    CanReachStairs.insert(i);
                }
                else
                    CantReachStairs.insert(i);
            }
            int requiredfloor;
            if (floor > 1)
            {
                requiredfloor = 3;
            }
            else
            {
                requiredfloor = 1;
            }
            if (CanReachStairs.size() > CantReachStairs.size())
            {
                for (auto i : CanReachStairs)
                {
                    vector<pair<int, int>> temp = Floors[requiredfloor].Search(stairs[i][requiredfloor].getNode().first, stairs[i][requiredfloor].getNode().second, stairs[(*CantReachStairs.begin())][requiredfloor]);
                    if (ansabove.empty() || ansabove.size() + v[(*CanReachStairs.begin())].size() > temp.size() + v[i].size())
                    {
                        ansabove = temp;
                        indxwon = i;
                    }
                }
                ansbelow = Floors[floor].Search(stairs[(*CantReachStairs.begin())][floor].getNode().first, stairs[(*CantReachStairs.begin())][floor].getNode().second, L);

                for (auto i : v[indxwon])
                {
                    ans.push_back({ floor,i });
                }
                for (auto i : ansabove)
                {
                    ans.push_back({ requiredfloor,i });
                }
                for (auto i : ansbelow)
                {
                    ans.push_back({ floor,i });
                }
            }
            else
            {
                for (auto i : CantReachStairs)
                {
                    vector<pair<int, int>> temp = Floors[requiredfloor].Search(stairs[(*CanReachStairs.begin())][requiredfloor].getNode().first, stairs[(*CanReachStairs.begin())][requiredfloor].getNode().second, stairs[i][requiredfloor]);
                    if (ansabove.empty() || ansabove.size() > temp.size())
                    {
                        ansabove = temp;
                        indxwon = i;
                    }
                }
                ansbelow = Floors[floor].Search(stairs[indxwon][floor].getNode().first, stairs[indxwon][floor].getNode().second, L);

                for (auto i : v[(*CanReachStairs.begin())])
                {
                    ans.push_back({ floor,i });
                }
                for (auto i : ansabove)
                {
                    ans.push_back({ requiredfloor,i });
                }
                for (auto i : ansbelow)
                {
                    ans.push_back({ floor,i });
                }
            }
            return ans;
        }
        for (auto i : curr)
        {
            ans.push_back({ floor,i });
        }
        return ans;
    }
    else
    {
        //4 cases

        //they both are on a connected floor (1,3) :
        //minimize on all three stairs

        //begin on a disconnected floor :
        //check which stairs are available and bfs through them

        //end on a disconnected floor :
        //check which stairs are available first then bfs through the main floor

        //both on a disconnected floor :
        //we will have to use transit floor to reach the location

        vector<pair<int, int>>ans1[3], ans2[3];
        map<int, bool>available, available2;
        for (int i = 0; i < 3;i++)
        {
            ans1[i] = Floors[floor].Search(x, y, stairs[i][floor]);
            if (ans1[i].size() > 0) available[i] = true;
        }
        for (int i = 0;i < 3;i++)
        {
            ans2[i] = Floors[L.getFloor()].Search(stairs[i][L.getFloor()].getNode().first, stairs[i][L.getFloor()].getNode().second, L);
            if (ans2[i].size() > 0) available2[i] = true;
        }
        int indxbig = -1, mini = 1e7;
        for (int i = 0; i < 3; ++i) {
            if (!available[i] || !available2[i])continue;
            if (ans2[i].size() + ans1[i].size() < mini)
            {
                mini = ans2[i].size() + ans1[i].size();
                indxbig = i;
            }
        }

        if (indxbig != -1)
        {
            for (auto i : ans1[indxbig])
            {
                ans.push_back({ floor,i });
            }
            for (auto i : ans2[indxbig])
            {
                ans.push_back({ L.getFloor(),i });
            }
            return ans;
        }
        else
        {
            int requiredfloor;
            if ((floor == 0 && L.getFloor() == 2) || (floor == 2 && L.getFloor() == 0))
            {
                requiredfloor = 1;
            }
            else
            {
                requiredfloor = 3;
            }
            //ans1.availability = 2 -> ans2 = 1 and vice verse

            map<pair<int, int>, vector<pair<int, int>>>ans3;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0;j < 3;j++)
                {
                    if (available[i] && available2[j])
                    {
                        ans3[{i, j}] = (Floors[requiredfloor].Search(stairs[i][requiredfloor].getNode().first, stairs[i][requiredfloor].getNode().second, stairs[j][requiredfloor]));
                    }
                }
            }

            //ans1 + ans3 + ans2
            int minis = 1e7, indxans1 = -1, indxans2 = -1;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0;j < 3;j++)
                {
                    if (available[i] && available2[j])
                    {
                        if (ans1[i].size() + ans2[j].size() + ans3[{i, j}].size() < minis)
                        {
                            indxans1 = i;
                            indxans2 = j;
                            minis = ans1[i].size() + ans2[j].size() + ans3[{i, j}].size();
                        }
                    }
                }
            }
            for (auto i : ans1[indxans1])
            {
                ans.push_back({ floor,i });
            }
            for (auto i : ans3[{indxans1, indxans2}])
            {
                ans.push_back({ requiredfloor,i });
            }
            for (auto i : ans2[indxans2])
            {
                ans.push_back({ L.getFloor(),i });
            }
            return ans;
        }

    }
}
