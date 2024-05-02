#include "Graph.h"

bool Graph::inborders(int x,int y,int limitx,int limity)
{
    return x >= 0 && x < limitx && y >= 0 && y < limity;
}

Graph::Graph(int rows,int cols,vector<vector<char>>grid) {
    this->rows = rows;
    this->cols = cols;
    vector<vector<Cell>>currgrid(rows,vector<Cell>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '.')
                currgrid[i][j].Passable = true;
            else
                currgrid[i][j].Passable = false;
        }
    }
}

void Cell::Update(string locationstring)
{
    this->HasLocation = true;
    this->location = locationstring;
};

void Graph::addlocation(int x,int y,Location l)
{
    //Invalid Check!
    bool isFound = false;
    for (int i = 0;i < locations.size();i++)
    {
        if (locations[i] == l.getName())
        {
            return;
        }
    }
    if (maingraph[x][y].HasLocation) return;
    locations.push_back(l.getName());
    maingraph[x][y].Update(l.getName());
}

vector<pair<int,int>> Graph::Search(int startx,int starty,Location l)
{
    vector<pair<int,int>> answer;
    map<pair<int,int>,pair<int,int>>parent;
    vector<vector<bool>> vis(rows,vector<bool>(cols));
    queue<pair<int,int>>q;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    q.push({startx,starty});
    while (q.size())
    {
        int currx = q.front().first;
        int curry = q.front().second;
        for (int i = 0; i < 4; ++i) {
            int newx = currx + dx[i];
            int newy = curry + dy[i];
            if (inborders(newx,newy,rows,cols))
            {
                if (maingraph[newx][newy].HasLocation && maingraph[newx][newy].location == l.getName())
                {
                    pair<int,int> currparent = {currx,curry};
                    answer.push_back(currparent);
                    pair<int,int> originalpair = {startx,starty};
                    while (currparent != originalpair)
                    {
                        currparent = parent[currparent];
                        answer.push_back(currparent);
                    }
                    break;
                }
            }
            if (inborders(newx,newy,rows,cols) && maingraph[newx][newy].Passable && !vis[newx][newy])
            {
                vis[newx][newy] = true;
                q.push({newx,newy});
                parent[{newx,newy}] = {currx,curry};
            }
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
