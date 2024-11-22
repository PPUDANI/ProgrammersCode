#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    int Count = 0;
    while(n != 1)
    {
        if(n % 2 == 1)
        {
            ++ans;
            n -= 1;
        }
        n /= 2;
    }
    
    
    return ans;
}