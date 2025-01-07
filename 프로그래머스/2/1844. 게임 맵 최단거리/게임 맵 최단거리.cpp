#include<vector>
#include<queue>

using namespace std;

struct int2
{
    int x;
    int y;
    
    int2 operator+(int2 _Val)
    {
        int2 Res;
        Res.x = x + _Val.x;
        Res.y = y + _Val.y;
        return Res;
    }
    
    bool operator ==(int2 _Val)
    {
        return x == _Val.x && y == _Val.y;
    }
    
};

int solution(vector<vector<int> > maps)
{
    int Max_x = int(maps[0].size());
    int Max_y = int(maps.size());
    int2 Goal = {Max_x - 1, Max_y - 1};
    
    queue<pair<int2, int>> BFS;
    vector<vector<bool>> Visit(Max_y, vector<bool>(Max_x, false));
    
    BFS.push({{0, 0}, 1});
    Visit[0][0] = true;

    vector<int2> MoveDirs = {{-1, 0},{1, 0},{0, -1},{0, 1}};
    while(!BFS.empty())
    {
        int2 CurTile = BFS.front().first;
        int CurMoveCount = BFS.front().second;
        BFS.pop();
        
        if(CurTile == Goal)
        {
            return CurMoveCount;
        }
        
        for(int2 MoveDir : MoveDirs)
        {
            int2 NextTile = CurTile + MoveDir;
            if(NextTile.x < 0 || NextTile.y < 0 || NextTile.x >= Max_x || NextTile.y >= Max_y)
            {
                continue;
            }
            
            if(maps[NextTile.y][NextTile.x] == 0)
            {
                continue;
            }
            
            if(Visit[NextTile.y][NextTile.x] == false)
            {
                Visit[NextTile.y][NextTile.x] = true;
                BFS.push({NextTile, CurMoveCount + 1});
            }
        }
    }
    
    return -1;
}