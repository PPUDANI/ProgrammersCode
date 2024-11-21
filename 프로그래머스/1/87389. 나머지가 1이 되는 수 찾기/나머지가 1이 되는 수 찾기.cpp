#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int Loop = n/2;
    for(int i = 2; i <= Loop; ++i)
    {
        if(n % i == 1)
        {
            return i;
        }
    }
    
    return n-1;
}