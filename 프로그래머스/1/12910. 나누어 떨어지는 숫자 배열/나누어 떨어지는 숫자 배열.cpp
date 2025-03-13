#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const int Left, const int Right)
{
    return Left < Right;
}

vector<int> solution(vector<int> arr, int divisor) 
{
    sort(arr.begin(), arr.end(), comp);
    vector<int> answer;
    for(int i : arr)
    {
        if(i % divisor == 0)
        {
            answer.push_back(i);
        }
    }
    
    if(answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}