#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


int solution(vector<int> topping) 
{
    std::unordered_map<int, int> LeftTopping;
    std::unordered_map<int, int> RightTopping;

    int LeftPoint = -1;
    int RightPoint = topping.size();
    
    while(RightPoint - LeftPoint > 1)
    {
        if(LeftTopping.size() <= RightTopping.size())
        {
            ++LeftPoint;
            ++LeftTopping[topping[LeftPoint]];
        }
        else
        {
            --RightPoint;
            ++RightTopping[topping[RightPoint]];
        }
    }

    int answer = 0;
    while(LeftTopping.size() >= RightTopping.size())
    {
        if(LeftTopping.size() == RightTopping.size())
        {
            ++answer;
        }

        --LeftTopping[topping[LeftPoint]];
    
        
        if(LeftTopping[topping[LeftPoint]] <= 0)
        {
            LeftTopping.erase(topping[LeftPoint]);
        }

        ++RightTopping[topping[LeftPoint]];
        --LeftPoint;
    }
    
    return answer;
}