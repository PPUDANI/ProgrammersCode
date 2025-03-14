#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    stack<int, vector<int>> DFS;
    
    vector<bool> Visit(n, false);
    
    DFS.push(0);
    Visit[0] = true;
    
    int VisitMax = 0;
    bool IsEnd = false;
    int answer = 0;
    while(IsEnd == false)
    {
        while(!DFS.empty())
        {
            int CurIndex = DFS.top();
            Visit[CurIndex] = true;
            DFS.pop();

            for(int i = 0; i < n; ++i)
            {
                if(computers[CurIndex][i] == 1 && Visit[i] == false)
                {
                    DFS.push(i);
                }
            }
        }
        
        ++answer;
        IsEnd = true;
        for(int i = VisitMax + 1; i < n; ++i)
        {
            if(Visit[i] == false)
            {
                IsEnd = false;
                DFS.push(i);
                VisitMax = i;
                break;
            }
        }
    }
    
    return answer;
}