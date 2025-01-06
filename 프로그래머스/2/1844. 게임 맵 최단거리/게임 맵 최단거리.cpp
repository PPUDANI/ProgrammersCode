#include<vector>
#include<queue>

using namespace std;

struct int2
{
    int x;
    int y;
    
    int2 operator +(int2 _Val)
    {
        int2 Res;
        Res.x = _Val.x + x;
        Res.y = _Val.y + y;
        return Res;
    }
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int XSize = int(maps[0].size());
    int YSize = int(maps.size());
    
    queue<pair<int2, int>> BFS;
    vector<vector<bool>> Visit(YSize, vector<bool>(XSize, false));
    
    //                            Up      Down    Right   Left
    vector<int2> Dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    BFS.push({{0, 0}, 1});
    maps[0][0] = 0;
    
    while(!BFS.empty())
    {
        int2 CurLocation = BFS.front().first;
        int NumOfMovedTile = BFS.front().second;
        BFS.pop();
        
        if(CurLocation.y == YSize - 1 && CurLocation.x == XSize - 1 )
        {
            return NumOfMovedTile;
        }
        
        for(int2 Dir : Dirs)
        {
            int2 NextLocation = CurLocation + Dir;
            if((NextLocation.y >= 0 && NextLocation.y < YSize && NextLocation.x >= 0 && 
               NextLocation.x < XSize) && maps[NextLocation.y][NextLocation.x] == 1)
            {    
                maps[NextLocation.y][NextLocation.x] = 0;
                BFS.push({NextLocation, NumOfMovedTile + 1});
            }
        }
    }

    return -1;
}