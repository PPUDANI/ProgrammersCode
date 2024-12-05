#include <vector>
#include <queue>
using namespace std;


int solution(vector<int> priorities, int location) 
{
    int answer = 0;
    int NumOfProcess = int(priorities.size());
    
    queue<pair<int, int>> Q;
    priority_queue<int> PQ(priorities.begin(), priorities.end());
    
    for(int i = 0; i < NumOfProcess; ++i)
    {
        Q.push({priorities[i], i});
    }
    
    int Count = 0;
    while(!Q.empty())
    {
        int CurPri = Q.front().first;
        int CurIdx = Q.front().second;
        Q.pop();
        
        if(CurPri == PQ.top())
        {
            PQ.pop();
            ++answer;
            if(CurIdx == location)
            {
                break;
            }
        }
        else
        {
            Q.push({CurPri, CurIdx});
        }
    }
    
    return answer;
}