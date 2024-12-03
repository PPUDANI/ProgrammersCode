#include<vector>
#include<queue>
using namespace std;

class int2
{
public:
    int X = 0;
    int Y = 0;
    
    bool IsMapOver(int2 EndPos)
    {
        if(X < 0 || Y < 0 || X > EndPos.X || Y > EndPos.Y)
        {
            return true;
        }
        return false;
    }
    
    bool operator==(int2 _Value)
    {
        if(X == _Value.X && Y == _Value.Y)
        {
            return true;
        }
        return false;
    }
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int2 MapSize = {int(maps[0].size()), int(maps.size())};
    
    int2 StartPos = {0, 0};
    int2 EndPos = {MapSize.X - 1, MapSize.Y - 1};
    
    vector<vector<bool>> Visit(MapSize.Y, vector<bool>(MapSize.X, false));
    
    queue<pair<int2, int>> BFS;
    BFS.push({StartPos, 1});
    
    vector<int> Move_X = {0, 1 ,0 ,-1};
    vector<int> Move_Y = {1, 0, -1, 0};
    while(!BFS.empty())
    {
        int2 CurPos = BFS.front().first;
        int CurDist = BFS.front().second;
        BFS.pop();
        
        if(CurPos == EndPos)
        {
            return CurDist;
        }
        
        for(int i = 0; i < 4; ++i)
        {
            int2 NextPos = {CurPos.X + Move_X[i], CurPos.Y + Move_Y[i]};
            if(NextPos.IsMapOver(EndPos) || maps[NextPos.Y][NextPos.X] == 0)
            {
                continue;
            }
            if(Visit[NextPos.Y][NextPos.X] == false)
            {
                Visit[NextPos.Y][NextPos.X] = true;
                BFS.push({NextPos, CurDist + 1});
            }
        }
    }
                          
    return -1;
}