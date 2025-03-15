#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

int solution(int N, vector<vector<int>> road, int K) 
{
    vector<vector<pair<int, int>>> Graph(N + 1, vector<pair<int, int>>());
    
    for(vector<int> Edge : road)
    {
        Graph[Edge[0]].push_back({Edge[1], Edge[2]});
        Graph[Edge[1]].push_back({Edge[0], Edge[2]});
    }
    
    vector<int> CostToNode(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>> PQ;
    
    CostToNode[1] = 0;
    PQ.push({1, 0});
    
    while(!PQ.empty())
    {
        int CurNode = PQ.top().first;
        int CurCost = PQ.top().second;
        PQ.pop();
        
        if(CurCost > CostToNode[CurNode])
        {
            continue;
        }
        
        for(pair<int, int> Edge : Graph[CurNode])
        {
            int NextNode = Edge.first;
            int NewCost = CurCost + Edge.second;
            if(NewCost < CostToNode[NextNode])
            {
                CostToNode[NextNode] = NewCost;
                PQ.push({NextNode, NewCost});
            }
        }
    }       
    
    int answer = 0;
    for(int i : CostToNode)
    {
        if(i <= K)
        {
            ++answer;
        }
    }
    

    return answer;
}