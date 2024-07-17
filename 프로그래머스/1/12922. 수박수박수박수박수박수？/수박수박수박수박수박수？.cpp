#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int SooBackNum = n / 2;

    for (int i = 0; i < SooBackNum; ++i)
    {
        answer += "수박";
    }

    if (n % 2 == 1)
    {
        answer += "수";
    }

    return answer;
}