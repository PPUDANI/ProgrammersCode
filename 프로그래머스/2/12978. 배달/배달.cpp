#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999

int solution(int N, vector<vector<int> > road, int K)
{
    vector<vector<pair<int, int>>> Graph(N + 1);
    for (vector<int> Edge : road)
    {
        int From = Edge[0];
        int To = Edge[1];
        int Dist = Edge[2];
        
        Graph[From].push_back({Dist, To});
        Graph[To].push_back({Dist, From});
    }

    vector<int> DistToNodes(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Dijkstra_PQ;
    
    DistToNodes[1] = 0;
    Dijkstra_PQ.push({ 0, 1 });

    while (!Dijkstra_PQ.empty())
    {
        int CurNode = Dijkstra_PQ.top().second;
        int CurDist = Dijkstra_PQ.top().first;
        Dijkstra_PQ.pop();

        if (DistToNodes[CurNode] < CurDist)
        {
            continue;
        }

        for (auto Edge : Graph[CurNode])
        {
            int NextNode = Edge.second;
            int NewDist = Edge.first + CurDist;

            if (DistToNodes[NextNode] > NewDist)
            {
                DistToNodes[NextNode] = NewDist;
                Dijkstra_PQ.push({ NewDist, NextNode });
            }
        }
    }

    int answer = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (K >= DistToNodes[i])
        {
            ++answer;
        }
    }

    return answer;
}