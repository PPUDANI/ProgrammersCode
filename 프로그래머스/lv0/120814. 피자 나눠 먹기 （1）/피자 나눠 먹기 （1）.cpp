#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while(0 < n)
    {
        n -= 7;
        answer++;
    }
    return answer;
}