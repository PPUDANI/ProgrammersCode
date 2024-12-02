#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> PQ(scoville.begin(), scoville.end());
    
    while(PQ.top() < K)
    {
        if(PQ.size() < 2)
        {
            return -1;
        }
        
        int CurMin_First = PQ.top();
        PQ.pop();
        
        int CurMin_Second = PQ.top();
        PQ.pop();
        
        PQ.push(CurMin_First + (2 * CurMin_Second));
        ++answer;
    }
    
    return answer;
}