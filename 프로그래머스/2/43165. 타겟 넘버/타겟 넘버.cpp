#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    int ArrSize = int(numbers.size());

    stack<pair<int, int>, vector<pair<int, int>>> DFS_Stack;

    DFS_Stack.push({ 0, numbers[0]});
    DFS_Stack.push({ 0, -numbers[0] });

    while (!DFS_Stack.empty())
    {
        int NextIndex = DFS_Stack.top().first + 1;
        int StackOfNum = DFS_Stack.top().second;
        DFS_Stack.pop();

        if (NextIndex == ArrSize)
        {
            if (StackOfNum == target)
            {
                ++answer;
            }
        }
        else
        {
            DFS_Stack.push({ NextIndex, StackOfNum + numbers[NextIndex] });
            DFS_Stack.push({ NextIndex, StackOfNum - numbers[NextIndex] });
        }
    }

    return answer;
}