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
    
    int BaseCase = 1;
    for(int i = 1; i < n; ++i)
    {
        if(TileMap[i][0] == PUDDLE)
        {
            BaseCase = 0;
        }
        TileMap[i][0] = BaseCase;
    }
    
    BaseCase = 1;
    for(int j = 1; j < m; ++j)
    {
        if(TileMap[0][j] == PUDDLE)
        {
            BaseCase = 0;
        }
        TileMap[0][j] = BaseCase;
    }
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            if(TileMap[i][j] == PUDDLE)
            {
                continue;
            }
            
            TileMap[i][j] = (TileMap[i - 1][j] + TileMap[i][j - 1]) % 1000000007;
        }
    }
    
    int answer = TileMap[n-1][m-1];
    return answer;
}