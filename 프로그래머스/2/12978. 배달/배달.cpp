#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 999999999
int solution(int N, vector<vector<int>> road, int K) 
{
    //            pair<Cost, Node>
    vector<vector<pair<int, int>>> Graph(N+1);
    for(vector<int> Edge : road)
    {
        Graph[Edge[0]].push_back({Edge[2], Edge[1]});
        Graph[Edge[1]].push_back({Edge[2], Edge[0]});
    }
    
    vector<int> CostToNode(N+1, INF);
    CostToNode[1] = 0;
    
    //             pair<Cost, Node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, 1});
    
    while(!PQ.empty())
    {
        int CurNode = PQ.top().second;
        int CurCost = PQ.top().first;
        PQ.pop();
        
        if(CostToNode[CurNode] < CurCost)
        {
            continue;
        }
        
        for(pair<int, int> Edge : Graph[CurNode])
        {
            int NextNode = Edge.second;
            int NewCost = CurCost + Edge.first;
            if(CostToNode[NextNode] > NewCost)
            {
                CostToNode[NextNode] = NewCost;
                PQ.push({NewCost, NextNode});
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(CostToNode[i] <= K)
        {
            ++answer;
        }
    }
    
    return answer;
}