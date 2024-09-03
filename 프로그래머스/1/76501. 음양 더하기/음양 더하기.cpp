#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) 
{
    int answer = 0;
    int AbsNum = static_cast<int>(absolutes.size());
    for (int i = 0; i < AbsNum; ++i)
    {
        answer += signs[i] == true ? absolutes[i] : -absolutes[i];
    }

    return answer;
}