#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define EMPTY 0

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int NumOfTruck = int(truck_weights.size());
    int CurIndex = 0;

    int CurWeight = 0;

    queue<int> Bridge;

    for (int i = 0; i < bridge_length; ++i)
    {
        Bridge.push(EMPTY);
    }

    int answer = 0;

    while (CurIndex < NumOfTruck)
    {
        CurWeight -= Bridge.front();
        Bridge.pop();
        ++answer;

        int NextTruckWeight = truck_weights[CurIndex];
        if ((CurWeight + NextTruckWeight) <= weight)
        {
            Bridge.push(NextTruckWeight);
            CurWeight += NextTruckWeight;
            ++CurIndex;
        }
        else
        {
            Bridge.push(EMPTY);
        }
    }

    answer += min(bridge_length, int(Bridge.size()));

    return answer;
}