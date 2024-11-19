#include <string>
#include <vector>

using namespace std;

#define INF 99999999
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    vector<vector<int>> Graph(n + 1, vector<int>(n + 1, INF));
    for(vector<int> FaresInfo : fares)
    {
        Graph[FaresInfo[0]][FaresInfo[1]] = FaresInfo[2];
        Graph[FaresInfo[1]][FaresInfo[0]] = FaresInfo[2];
    }
    for(int i = 1; i <= n; ++i)
    {
        Graph[i][i] = 0;
    }
    
    // Floid-Washal
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            if(k == i)
            {
                continue;
            }
            for(int j = 1; j  <= n; ++j)
            {
                if(k == j)
                {
                    continue;
                }
                
                int NewFares = Graph[i][k] + Graph[k][j];
                if(NewFares < Graph[i][j])
                {
                    Graph[i][j] = NewFares;
                    Graph[j][i] = NewFares;
                }
            }
        }
    }
    
    int answer = INF;
    for(int i = 1; i <= n; ++i)
    {
        int CurFares = Graph[s][i] + Graph[i][a] + Graph[i][b];
        answer = min(answer, CurFares);
    }
    
    
    
    return answer;
}