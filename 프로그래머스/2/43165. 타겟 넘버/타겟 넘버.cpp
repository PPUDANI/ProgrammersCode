#include <string>
#include <vector>
#include <stack>
using namespace std;


int solution(vector<int> numbers, int target) 
{
    int answer = 0;
       
    stack<pair<int, int>, vector<pair<int, int>>> DFS;
    DFS.push({1, numbers[0]});
    DFS.push({1, -numbers[0]});
    
    while(!DFS.empty())
    {
        int CurIndex = DFS.top().first;
        int CurSum = DFS.top().second;
        DFS.pop();
        
        if(CurIndex == numbers.size())
        {
            if(CurSum == target)
            {
                ++answer;
            }
            continue;
        }
        
        DFS.push({CurIndex + 1, CurSum + numbers[CurIndex]});
        DFS.push({CurIndex + 1, CurSum - numbers[CurIndex]});
    }
    
    return answer;
}