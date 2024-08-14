#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    int EndTileNumber = 0;

    for(int i : section)
    {
        if (EndTileNumber < i)
        {
            EndTileNumber = i - 1 + m;
            answer++;
        }
    }

    return answer;
}
