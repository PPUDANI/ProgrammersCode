#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = n;
    int Loop = n / 2;
    for(int i = 1; i <= Loop; ++i)
    {
        if(n % i == 0)
        {
            answer += i;
        }
    }
    
    return answer;
}