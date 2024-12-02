#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    int NumOfNum = int(numbers.size());
    
    stack<pair<int, int>, vector<pair<int, int>>> DPS;
    
    DPS.push({-numbers[0], 0});
    DPS.push({numbers[0], 0});
    
    while(!DPS.empty())
    {
        int CurAccum = DPS.top().first;
        int NextIndex = DPS.top().second + 1;
        DPS.pop();
        if(NextIndex < NumOfNum)
        {
            DPS.push({CurAccum - numbers[NextIndex], NextIndex});
            DPS.push({CurAccum + numbers[NextIndex], NextIndex});
        }
        else
        {
            if(CurAccum == target)
            {
                ++answer;
            }
        }
    }
    
    return answer;
}