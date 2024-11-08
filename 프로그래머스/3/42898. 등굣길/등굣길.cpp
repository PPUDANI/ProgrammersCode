#include <string>
#include <vector>

using namespace std;

#define PUDDLE 0

int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<int>> TileMap(n, vector<int>(m, -1));
    
    for(vector<int> puddle : puddles)
    {
        TileMap[puddle[1] - 1][puddle[0] - 1] = PUDDLE;
    }
    int YBaseCase = 1;
    for(int i = 1; i < n; ++i)
    {
        if(TileMap[i][0] == PUDDLE)
        {
            YBaseCase = 0;
        }
        TileMap[i][0] = YBaseCase;
    }
    int XBaseCase = 1;
    for(int j = 1; j < m; ++j)
    {
        if(TileMap[0][j] == PUDDLE)
        {
            XBaseCase = 0;
        }
        TileMap[0][j] = XBaseCase;
    }
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            if(TileMap[i][j] == PUDDLE)
            {
                continue;
            }
            int Up = TileMap[i - 1][j] % 1000000007;
            int Left = TileMap[i][j - 1] % 1000000007;
            TileMap[i][j] = (Up + Left) % 1000000007;
        }
    }
    
    int answer = TileMap[n-1][m-1];
    return answer;
}