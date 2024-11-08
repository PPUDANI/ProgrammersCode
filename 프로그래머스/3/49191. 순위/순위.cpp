#include <vector>

using namespace std;

#define NON_RESULT 0
int solution(int n, vector<vector<int>> results) 
{
    vector<vector<int>> Graph(n+1 , vector<int>(n + 1, NON_RESULT));
    for(vector<int> result : results)
    {
        Graph[result[0]][result[1]] = 1;
        Graph[result[1]][result[0]] = -1;
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
                if(Graph[i][k] == 1 && Graph[k][j] == 1)
                {
                    Graph[i][j] = 1;
                    Graph[j][i] = -1;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= n; ++i)
    {
        int ResultCount = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(Graph[i][j] != 0)
            {
                
                ++ResultCount;
            }
        }
        
        if(n - 1 == ResultCount)
        {
            ++answer;
        }
    }
    
    
    return answer;
}