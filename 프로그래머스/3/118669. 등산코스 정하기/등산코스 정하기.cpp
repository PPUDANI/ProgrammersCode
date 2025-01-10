#include <queue>
#include <vector>
using namespace std;

struct NodeInfo
{
    int Cost;
    int Number;
    
    bool operator>(const NodeInfo _Val) const
    {
        return Cost > _Val.Cost;
    }
};

#define INF 999999999
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) 
{
    vector<vector<NodeInfo>> Graph(n + 1);
    
    for(vector<int> Path : paths)
    {
        Graph[Path[0]].push_back({Path[2], Path[1]});
        Graph[Path[1]].push_back({Path[2], Path[0]});
    }
    
    //                 max, CurNode
    priority_queue<NodeInfo, vector<NodeInfo>, greater<NodeInfo>> PQ;
    vector<bool> IsGate(n + 1, false);
    for(int Gate : gates)
    {
        IsGate[Gate] = true;
        PQ.push({0, Gate});
    }
    
    vector<bool> IsSummit(n + 1, false);
    for(int Summit : summits)
    {
        IsSummit[Summit] = true;
    }
    
    vector<int> CostToNode(n + 1, INF);
    
    while(!PQ.empty())
    {
        int CurCost = PQ.top().Cost;
        int CurNode = PQ.top().Number;
        
        PQ.pop();
        
        if(IsSummit[CurNode])
        {
            continue;
        }
        
        if(CostToNode[CurNode] < CurCost)
        {
            continue;
        }
        
        for(NodeInfo NextInfo : Graph[CurNode])
        {
            int NextNode = NextInfo.Number;
            int NewCost = max(CurCost, NextInfo.Cost);
            
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
    
    int Res_Summit = INF;
    int Res_Cost = INF;
    for(int CurNode : summits)
    {
        if(Res_Cost > CostToNode[CurNode])
        {
            Res_Cost = CostToNode[CurNode];
            Res_Summit = CurNode;
        }
        else if(Res_Cost == CostToNode[CurNode])
        {
            Res_Summit = min(Res_Summit, CurNode);
        }
    }
    
    vector<int> answer = {Res_Summit, Res_Cost};
    return answer;
}