#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 999999999

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) 
{
    vector<int> answer;
    
    for(vector<int> ball : balls)
    {
        vector<int> Result(4, 0);
        Result[0] = pow(startX + ball[0],       2) + pow(startY - ball[1], 2); // Left
        Result[1] = pow(startX - ((2 * m) - ball[0]), 2) + pow(startY - ball[1], 2); // Right
        Result[2] = pow(startX - ball[0], 2) + pow(startY - ((2 * n) - ball[1]), 2); // Up
        Result[3] = pow(startX - ball[0], 2) + pow(startY + ball[1],       2); // Down
        
        // x축이 같음
        if(startX == ball[0])
        {
            if(startY - ball[1] < 0) // 위쪽에 위치
            {
                Result[2] = MAX;
            }
            else // 아래쪽에 위치
            {
                Result[3] = MAX;
            }
        }
        // y축이 같음
        else if(startY == ball[1])
        {
            if(startX - ball[0] > 0) // 왼쪽에 위치
            {
                Result[0] = MAX;
            }
            else // 오른쪽에 위치
            {
                Result[1] = MAX;
            }
        }
        
        answer.push_back(Result[min_element(Result.begin(), Result.end()) - Result.begin()]);
    }
    
    return answer;
}