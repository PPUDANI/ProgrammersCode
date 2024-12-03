#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<bool> Visit(n, false);
    
    stack<int, vector<int>> DFS;
    for(int i = 0; i < n; ++i)
    {
        if(computers[0][i] == 1)
        {
            DFS.push(i);
        }
    }
         
    bool IsVisitedAll = false;
    while(IsVisitedAll == false)
    {
        while(!DFS.empty())
        {
            int CurNode = DFS.top();
            DFS.pop();

            for(int i = 0; i < n; ++i)
            {
                if(computers[CurNode][i] == 0)
                {
                    continue;
                }

                if(Visit[i] == false)
                {
                    Visit[i] = true;
                    DFS.push(i);
                }
            }
        }
        ++answer;
        IsVisitedAll = true;
        for(int i = 0; i < n; ++i)
        {
            if(Visit[i] == false)
            {
                Visit[i] = true;
                IsVisitedAll = false; 
                DFS.push(i);
                break;
            }
        }
    }
    
    return answer;
}