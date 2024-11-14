#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INF 9999999
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    vector<vector<int>> Graph(n+1, vector<int>(n+1, INF));
    
    for(int i = 1; i <= n; ++i)
    {
        Graph[i][i] = 0;
    }
    
    for(vector<int> Edge : fares)
    {
        Graph[Edge[0]][Edge[1]] = Edge[2];
        Graph[Edge[1]][Edge[0]] = Edge[2];
    }
    
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(i == k)
            {
                continue;
            }
            
            for(int j = 1; j <= n; ++j)
            {
                int SumFares = Graph[i][k] + Graph[k][j];
                if(SumFares < INF && Graph[i][j] > SumFares)
                {
                    Graph[i][j] = SumFares;
                    Graph[j][i] = SumFares;
                }
            }
        }
    }
    
    int answer = INF;
    for(int i = 1; i <= n; ++i)
    {
        int Curfares = Graph[s][i] + Graph[i][a]+ Graph[i][b];
        answer = min(answer, Curfares);
    }
    
    return answer;
}