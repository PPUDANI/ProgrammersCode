#include <vector>
#include <stack>
using namespace std;


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    stack<pair<int, int>, vector<pair<int, int>>> DPS;
    
    DPS.push({-numbers[0], 0});
    DPS.push({numbers[0], 0});
    
    int NumSize = int(numbers.size());
    while(!DPS.empty())
    {
        int CurAccum = DPS.top().first;
        int CurIndex = DPS.top().second;
        DPS.pop();
        
        int NextIndex = CurIndex + 1;
        if(NextIndex == NumSize)
        {
            if(CurAccum == target)
            {
                ++answer;
            }
            continue;
        }
        
        int NextAccum = numbers[NextIndex];
        DPS.push({CurAccum - NextAccum, NextIndex});
        DPS.push({CurAccum + NextAccum, NextIndex});
    }
    
    return answer;
}