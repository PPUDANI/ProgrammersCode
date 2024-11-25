#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iostream>

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
        cout << PQ.top() << " ";
        NumOfTang -= PQ.top();
        PQ.pop();
        ++answer;
        
        if(NumOfTang <= 0)
        {
            break;
        }
    }
    
    return answer;
}