#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    vector<vector<pair<int, int>>> Graph(n + 1);
    
    for(vector<int> Path : paths)
    {        
        Graph[Path[0]].push_back({Path[2], Path[1]});
        Graph[Path[1]].push_back({Path[2], Path[0]});
    }
    
    //                 Cost, Node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    
    vector<bool> IsGate(n+1, false);
    for(int gate: gates)
    {
        IsGate[gate] = true;
        PQ.push({0, gate});
    }
    
    vector<bool> IsSummit(n+1, false);
    for(int Summit : summits)
    {
        IsSummit[Summit] = true;
    }
    
    //       MinCost, Gate
    vector<int> CostToNode(n+1, INF);
    while(!PQ.empty())
    {
        int CurCost = PQ.top().first;
        int CurNode = PQ.top().second;
        
        PQ.pop();
        
        if(IsSummit[CurNode])
        {
            if(CostToNode[CurNode] > CurCost)
            {
                CostToNode[CurNode] = CurCost;
            }
            continue;
        }
        
        if(CostToNode[CurNode] < CurCost)
        {
            continue;
        }
        
        for(auto Edge : Graph[CurNode])
        {       
            int NewCost = max(Edge.first, CurCost);
            int NextNode = Edge.second;
            if(IsGate[NextNode])
            {
                continue;
            }

            if(CostToNode[NextNode] > NewCost)
            {
                CostToNode[NextNode] = NewCost;
                PQ.push({NewCost, NextNode});
            }
        }
    }
    
    int MinCost = INF;
    int MinSummit = INF;
    for(int Summit : summits)
    {
        if(MinCost > CostToNode[Summit])
        {
            MinCost = CostToNode[Summit];
            MinSummit = Summit;
        }
        else if(MinCost == CostToNode[Summit] &&
               MinSummit > Summit)
        {
            MinSummit = Summit;
        }
    }
    
    return {MinSummit, MinCost};
}