#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647

int solution(int N, vector<vector<int> > road, int K) 
{
    int answer = 0;
    //         Cost  NextNode
    vector<vector<pair<int, int>>> Graph(N + 1, vector<pair<int, int>>());
    for(vector<int> EdgeInfo : road)
    {
        Graph[EdgeInfo[0]].push_back({EdgeInfo[2], EdgeInfo[1]});  
        Graph[EdgeInfo[1]].push_back({EdgeInfo[2], EdgeInfo[0]});
    }
    
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, 1});
    
    vector<int> CostToNode(N + 1, INF);
    CostToNode[1] = 0;
    
    while(!PQ.empty())
    {
        int CurCost = PQ.top().first;
        int CurNode = PQ.top().second;
        PQ.pop();
        
        if(CurCost > CostToNode[CurNode])
        {
            continue;
        }
        
        for(pair<int, int> Edge : Graph[CurNode])
        {
            int NewCost = CurCost + Edge.first;
            int NextNode = Edge.second;
            
            if(NewCost < CostToNode[NextNode])
            {
                CostToNode[NextNode] = NewCost;
                PQ.push({NewCost, NextNode});
            }
        }
    }
    
    for(int i = 1; i <= N; ++i)
    {
        if(CostToNode[i] <= K)
        {
            ++answer;
        }
    }
    
    return  answer;
}