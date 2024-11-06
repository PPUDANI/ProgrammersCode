#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<int>& Left, const vector<int>& Rigjt)
{
    return Left[1] < Rigjt[1];
}

int solution(vector<vector<int>> targets) 
{
    sort(targets.begin(), targets.end(), comp);
        
    int InterceptCnt = 0;
    int InterceptCoord = -1;
    for(vector<int> Target : targets)
    {
        if(Target[0] >= InterceptCoord)
        {
            InterceptCoord = Target[1];
            ++InterceptCnt;
        }
    }
    
    return InterceptCnt;
}