#include <string>
#include <vector>
#include <stack>
using namespace std;




int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> Visit(n, false);
    stack<int, vector<int>> DFS;
    DFS.push(0);
    Visit[0] = true;
    
    bool IsEnd = false;
    while(IsEnd == false)
    {
        while(!DFS.empty())
        {
            int CurNum = DFS.top();
            DFS.pop();
            
            for(int i = 0; i < n; ++i)
            {
                if(computers[CurNum][i] == 1 && Visit[i] == false)
                {
                    Visit[i] = true;
                    DFS.push(i);
                }
            }
        }
        ++answer;
        
        bool EndCheck = true;
        for(int i = 0; i < n; ++i)
        {
            if(Visit[i] == false)
            {
                EndCheck = false;
                Visit[i] = true;
                DFS.push(i);
                break;
            }
        }
        
        if(EndCheck == true)
        {
            IsEnd = true;
        }
    }
    
    return answer;
}