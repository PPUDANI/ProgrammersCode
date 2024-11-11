#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_COST 999999
int solution(int N, vector<vector<int> > road, int K) 
{
    vector<vector<pair<int, int>>> Graph(N + 1);
    
    for(vector<int> RoadInfo : road)
    {
        int From = RoadInfo[0];
        int To = RoadInfo[1];
        int Cost = RoadInfo[2];
        Graph[From].push_back({Cost, To});
        Graph[To].push_back({Cost, From});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> CostToNode(N+1, MAX_COST);
    PQ.push({0, 1});
    CostToNode[1] = 0;
    while(!PQ.empty())
    {
        int CurNode = PQ.top().second;
        int CurCost = PQ.top().first;
        PQ.pop();
        if(CostToNode[CurNode] > CurCost)
        {
            continue;
        }
        
        for(auto Next : Graph[CurNode])
        {
            int NextNode = Next.second;
            int NewDist = Next.first + CurCost;
            if(NewDist < CostToNode[NextNode])
            {
                CostToNode[NextNode] = NewDist;
                PQ.push({NewDist, NextNode});
            }
        }
    }
    
    int answer = 0;
    for(int Cost : CostToNode)
    {
        if(Cost <= K)
        {
            ++answer;
        }
    }

    return answer;
}