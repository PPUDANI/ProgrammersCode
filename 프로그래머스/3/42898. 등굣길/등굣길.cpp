#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define PUDDLE 0
#define EMPTY 999999999

int solution(int m, int n, vector<vector<int>> puddles) 
{
    vector<vector<int>> Map(n, vector<int>(m, EMPTY));
        
    for(vector<int> Puddle : puddles)
    {
        Map[Puddle[1] - 1][Puddle[0] - 1] = PUDDLE;
    }
    
    for(int i = 0; i < m; ++i)
    {
        if(Map[0][i] == PUDDLE)
        {
            break;
        }
        
        Map[0][i] = 1;
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(Map[i][0] == PUDDLE)
        {
            break;
        }
        Map[i][0] = 1;
    }

    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < m; ++j)
        {
            if(Map[i][j] == PUDDLE)
            {
                continue;
            }
            
            int Up = Map[i-1][j];
            int Left = Map[i][j-1];
            
            if(Up == EMPTY)
            {
                Up = 0;
            }
            
            if(Left == EMPTY)
            {
                Left = 0;
            }
            
            Map[i][j] = (Up + Left) % 1000000007;
        }
    }
    
    int answer = Map[n-1][m-1] % 1000000007;
    return answer;
}