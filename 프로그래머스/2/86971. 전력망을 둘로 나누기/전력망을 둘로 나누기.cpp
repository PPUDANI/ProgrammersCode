#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999999
int DFS(vector<vector<int>> _Graph, int StartNode, int DeleteNode)
{
    vector<bool> Visit(_Graph.size(), false);
    Visit[StartNode] = true;
    Visit[DeleteNode] = true;
    
    stack<int, vector<int>> Stack;
    Stack.push(StartNode);
    int NumOfNode = 1;
    
    while(!Stack.empty())
    {
        int CurNode = Stack.top();
        Stack.pop();
        
        for(int NextNode : _Graph[CurNode])
        {
            if(Visit[NextNode] == false)
            {
                Visit[NextNode] = true;
                Stack.push(NextNode);
                ++NumOfNode;
            }
        }
    }
    
    return NumOfNode;
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = INF;
    
    vector<vector<int>> Graph(n + 1);
    for(vector<int> Wire : wires)
    {
        Graph[Wire[0]].push_back(Wire[1]);
        Graph[Wire[1]].push_back(Wire[0]);
    }
    
    for(vector<int> Wire : wires)
    {
        int NumOfLeftNode = DFS(Graph, Wire[0], Wire[1]);
        int NumOfRightNode = DFS(Graph, Wire[1], Wire[0]);
        answer = min(answer, abs(NumOfLeftNode - NumOfRightNode));
    }
    
    return answer;
}