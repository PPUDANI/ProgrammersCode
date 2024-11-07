#include <vector>
#include <queue>

using namespace std;

#define INF 999999

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
    //                 cost, Node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<int> CostToNode(N + 1, INF);
    
    PQ.push({0, 1});
    CostToNode[1] = 0;
    
    while(!PQ.empty())
    {
        int CurCost = PQ.top().first;
        int CurNode = PQ.top().second;
        PQ.pop();
        
        if(CostToNode[CurNode] < CurCost)
        {
            continue;
        }
        
        for(auto Edge : Graph[CurNode])
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