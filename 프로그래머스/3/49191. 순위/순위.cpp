#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    vector<vector<int>> Graph(n, vector<int>(n, 0));
    
    for(vector<int> Res : results)
    {
        Graph[Res[0] - 1][Res[1] - 1] = 1;
        Graph[Res[1] - 1][Res[0] - 1] = -1;
    }
    
    for(int k = 0; k < n; ++k)
    {
       for(int i = 0; i < n; ++i)
        {
            if(k == i)
            {
                continue;
            }
           
            for(int j = 0; j < n; ++j)
            {
                if(i == j)
                {
                    continue;
                }
                
                if(Graph[i][k] == 1 && Graph[k][j] == 1)
                {
                    Graph[i][j] = 1;
                    Graph[j][i] = -1;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < n; ++i)
    {
        bool Checkable = true;
        for(int j = 0; j < n; ++j)
        {
            if(i == j)
            {
                continue;
            }
            
            if(Graph[i][j] == 0)
            {
                Checkable = false;
                break;
            }
        }

        if(Checkable)
        {
            ++answer;
        }
    }
    
    return answer;
}