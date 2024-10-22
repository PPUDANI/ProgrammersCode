#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> Graph(n + 1, vector<int>());

    for (const vector<int>& EdgeInfo : edge)
    {
        Graph[EdgeInfo[0]].push_back(EdgeInfo[1]);
        Graph[EdgeInfo[1]].push_back(EdgeInfo[0]);
    }

    vector<int> DistanceToNode(n + 1, 0);
    vector<bool> VisitedNode(n + 1, false);
    int MaxDist = 0;

    queue<int> BFS_Q;
    BFS_Q.push(1);
    VisitedNode[1] = true;
    while (!BFS_Q.empty())
    {
        int CurNode = BFS_Q.front();
        BFS_Q.pop();

        int DistToNextNode = DistanceToNode[CurNode] + 1;

        for (int NextNode : Graph[CurNode])
        {
            if(VisitedNode[NextNode] == false)
            {
                DistanceToNode[NextNode] = DistToNextNode;

                if (DistToNextNode > MaxDist)
                {
                    MaxDist = DistToNextNode;
                }

                VisitedNode[NextNode] = true;
                BFS_Q.push(NextNode);
            }
        }
    }

    int answer = 0;
    for (int Dist : DistanceToNode)
    {   
        if (Dist == MaxDist)
        {
            ++answer;
        }
    }

    return answer;
}