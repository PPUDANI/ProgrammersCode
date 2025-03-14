#include<vector>
#include<queue>
#include<iostream>
using namespace std;

struct int2
{
    int x = 0;
    int y = 0;
    
    bool operator==(const int2 _val) const
    {
        return x == _val.x && y == _val.y;
    }
    
    int2 operator+(const int2 _val) const
    {
        int2 Res;
        Res.x = x + _val.x;
        Res.y = y + _val.y;
        return Res;
    }
};

bool IsOver(int2 _Pos, int2 _MaxPos)
{
    if(_Pos.x < 0 || _Pos.y < 0)
    {
        return true;
    }
    else if(_Pos.x > _MaxPos.x || _Pos.y > _MaxPos.y)
    {
        return true;
    }
    
    return false;
}

int solution(vector<vector<int> > maps)
{
    int2 MaxPos = 
    {
        static_cast<int>(maps[0].size() - 1), 
        static_cast<int>(maps.size() - 1)
    };
    
    queue<pair<int2, int>> BFS;
    BFS.push({{0, 0}, 1});
    maps[0][0] = 0;
    vector<int2> Dirs = 
    {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    
    while(!BFS.empty())
    {
        int2 CurPos = BFS.front().first;
        int CurSum = BFS.front().second;
        BFS.pop();
        
        if(CurPos == MaxPos)
        {
            return CurSum;
        }
        
        for(int2 CurDir : Dirs)
        {
            int2 NewPos = CurPos + CurDir;
            
            if(IsOver(NewPos, MaxPos) == false && 
               maps[NewPos.y][NewPos.x] == 1)
            {
                maps[NewPos.y][NewPos.x] = 0;
                BFS.push({NewPos, CurSum + 1});
            }
        }
    }
    
    return -1;
}