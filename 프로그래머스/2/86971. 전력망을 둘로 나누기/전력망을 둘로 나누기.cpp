#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int BFS(int Start, int DeleteNode, vector<vector<int>> Graph, int NumOfNode)
{
    queue<int> Q;
    vector<bool> VisitCheck(NumOfNode + 1, false);
    Q.push(Start);
    VisitCheck[Start] = true;
    
    int Count = 0;
    while(!Q.empty())
    {
        ++Count;
        int CurNode = Q.front();
        Q.pop();
        
        for(int NextNode : Graph[CurNode])
        {
            if(DeleteNode == NextNode)
            {
                continue;
            }
            
            if(VisitCheck[NextNode] == false)
            {
                VisitCheck[NextNode] = true;
                Q.push(NextNode);
            }
        }
    }
    
    return Count;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 100;
    vector<vector<int>> Graph(n + 1);
    for(vector<int> Wire : wires)
    {
        Graph[Wire[0]].push_back(Wire[1]);
        Graph[Wire[1]].push_back(Wire[0]);
    }
    
    for(vector<int> Wire : wires)
    {
        int Left = BFS(Wire[0], Wire[1], Graph, n);
        int Right = BFS(Wire[1], Wire[0], Graph, n);
        answer = min(abs(Left - Right), answer);
    }
    
    return answer;
}