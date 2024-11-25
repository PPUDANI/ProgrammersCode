#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {

    unordered_map<int, int> Tangerine_Sizes;
    
    for(int Size: tangerine)
    {
        ++Tangerine_Sizes[Size];
    }
    
    priority_queue<int> PQ;
    for(auto Size : Tangerine_Sizes)
    {
        PQ.push(Size.second);
    }
    
    int NumOfTang = k;
    int answer = 0;
    
    while(!PQ.empty())
    {
        NumOfTang -= PQ.top();
        ++answer;
        PQ.pop();
        
        if(NumOfTang <= 0)
        {
            break;
        }
    }
    
    return answer;
}