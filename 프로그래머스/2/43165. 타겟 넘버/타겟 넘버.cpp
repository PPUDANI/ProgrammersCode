#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    stack<pair<int, int>, vector<pair<int, int>> > DFS;
    DFS.push({numbers[0], 1});
    DFS.push({-numbers[0], 1});
    
    int MaxIndex = int(numbers.size());
    while(!DFS.empty())
    {
        int CurSum = DFS.top().first;
        int CurIndex = DFS.top().second;
        DFS.pop();
        
        if(CurIndex == MaxIndex)
        {
            if(CurSum == target)
            {
                ++answer;
            }
            continue;
        }
        
        DFS.push({CurSum + numbers[CurIndex], CurIndex + 1});
        DFS.push({CurSum - numbers[CurIndex], CurIndex + 1});
    }
    
    return answer;
}