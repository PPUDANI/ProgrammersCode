#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    int ArrSize = int(numbers.size());

    //         idx  sum
    queue<pair<int, int>> BFS_Q;
    
    BFS_Q.push({0, numbers[0]});
    BFS_Q.push({0, -numbers[0]});
    
    while(!BFS_Q.empty())
    {
        int CurIndex = BFS_Q.front().first;
        int CurSum = BFS_Q.front().second;

        BFS_Q.pop();
        
        if(ArrSize == ++CurIndex)
        {
            if(CurSum == target)
            {
                ++answer;
                continue;
            }
        }
        else
        {
            BFS_Q.push({CurIndex, CurSum + numbers[CurIndex]});
            BFS_Q.push({CurIndex, CurSum - numbers[CurIndex]});
        }
    }

    return answer;
}