#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int N = n / 2;

    for (int i = 0; i < N; ++i)
    {
        answer += "수박";
    }

    if (n % 2 == 1)
    {
        answer += "수";
    }

    return answer;
}