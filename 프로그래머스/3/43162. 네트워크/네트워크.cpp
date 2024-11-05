#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    set<int> VisitCheck;
    for(int i = 0; i < n; ++i)
    {
        VisitCheck.insert(i);
    }
    
    stack<int, vector<int>> DFS;
    
    
    while(true)
    {
        while(!DFS.empty())
        {
            int CurNode = DFS.top();
            VisitCheck.erase(CurNode);
            DFS.pop();
            for(int i = 0; i < n; ++i)
            {
                if(CurNode != i && computers[CurNode][i] == 1 && 
                   VisitCheck.find(i) != VisitCheck.end())
                {
                    DFS.push(i);
                }
            }
        }
        
        if(VisitCheck.empty())
        {
            break;
        }
        else
        {
            ++answer;
            DFS.push(*VisitCheck.begin());
        }
    }

    
    return answer;
}