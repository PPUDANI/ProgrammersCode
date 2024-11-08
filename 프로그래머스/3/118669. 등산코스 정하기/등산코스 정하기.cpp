#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INDEX_MAX 999999
#define COST_MAX 99999999
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<bool> IsGates(n + 1, false);
    vector<bool> IsSummit(n + 1, false);
    
    for(int SummitNode : summits)
    {
        IsSummit[SummitNode] = true;
    }
    
    vector<vector<pair<int, int>>> Graph(n + 1);
    for (vector<int> Path : paths)
    {
        int From = Path[0];
        int To = Path[1];
        int Rset = Path[2];
        
        Graph[From].push_back({ Rset, To });
        Graph[To].push_back({ Rset, From });
    }
    
    //         Rset  From
    vector<pair<int, int>> MinRestToNode(n + 1, { COST_MAX, INDEX_MAX });

    //                  Rset    From,  To
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> PQ;

    for (int GateNode : gates)
    {
        IsGates[GateNode] = true;
        for (pair<int, int> NextNode : Graph[GateNode])
        {
            PQ.push({ NextNode.first, {GateNode, NextNode.second} });
        }
    }

    while (!PQ.empty())
    {
        int CurMaxRest = PQ.top().first;
        int FromNode = PQ.top().second.first;
        int CurNode = PQ.top().second.second;
        PQ.pop();
        
        if (IsSummit[CurNode] == true)
        {
            if (MinRestToNode[CurNode].first > CurMaxRest)
            {
                MinRestToNode[CurNode].first = CurMaxRest;
                MinRestToNode[CurNode].second = FromNode;
            }
            continue;
        }

        for (pair<int, int> Path : Graph[CurNode])
        {
            int MaxRest = max(Path.first, CurMaxRest);
            int NextNode = Path.second;
            
            if (IsGates[NextNode] == true)
            {
                continue;
            }
            
            if (MinRestToNode[NextNode].first > MaxRest)
            {
                MinRestToNode[NextNode].first = MaxRest;
                MinRestToNode[NextNode].second = FromNode;
                PQ.push({ MaxRest, {FromNode, NextNode} });
            }
            else if (MinRestToNode[NextNode].first == MaxRest)
            {
                if(MinRestToNode[NextNode].second > FromNode)
                {
                    MinRestToNode[NextNode].second = FromNode;
                    PQ.push({ MaxRest, {FromNode, NextNode} });
                }
            }
        }
    }
    
    vector<int> answer = { INDEX_MAX, COST_MAX };
    for (int Summit : summits)
    {
        if (answer[1] > MinRestToNode[Summit].first)
        {
            answer[1] = MinRestToNode[Summit].first;
            answer[0] = Summit;
        }
        else if (answer[1] == MinRestToNode[Summit].first)
        {
            answer[0] = min(answer[0], Summit);
        }
    }
    
    return answer;
}