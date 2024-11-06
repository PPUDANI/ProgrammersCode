#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999

int solution(int N, vector<vector<int> > road, int K) 
{
    vector<vector<pair<int, int>>> Graph(N + 1);
    for(auto Edge : road)
    {
        int From = Edge[0];
        int To = Edge[1];
        int Cost = Edge[2];
        
        Graph[From].push_back({Cost, To});
        Graph[To].push_back({Cost, From});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> CostToNode(N + 1, INF);
    
    PQ.push({0, 1});
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
        
        for(auto Edge : Graph[CurNode])
        {
            int NewCost = Edge.first + CurCost;
            int NextNode = Edge.second;
            if(CostToNode[NextNode] > NewCost)
            {
                CostToNode[NextNode] = NewCost;
                PQ.push({NewCost, NextNode});
            }
        }
    }
    
    int answer = 1;
    for(int i = 2; i <= N; ++i)
    {
        if(CostToNode[i] <= K)
        {
            ++answer;
        }
    }
    return answer;
}