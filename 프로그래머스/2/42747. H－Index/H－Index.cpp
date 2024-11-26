#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(int Left, int Right)
{
    return Left > Right;
}

int solution(vector<int> citations) 
{
    int answer = 0;
    sort(citations.begin(), citations.end(), comp);
    
    int citationsSize = citations.size();

    for(int Cnt = citations[0]; Cnt > 0; --Cnt)
    {
        int Count = 0;
        for(int i = 0; i < citationsSize; ++i)
        {
            if(Cnt <= citations[i])
            {
                ++Count;
            }
        }
        
        if(Count >= Cnt)
        {
            answer = max(answer, Cnt);
        }
    }

    
    return answer;
}