#include <iostream>
#include <bitset>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    bitset<20> bs = n;
    for(int i = 0; i < 20; ++i)
    {
        if(bs[i] == 1)
        {
            break;
        }
        ++answer;
    }

    while(n != 1)   
    {
        n /= 2;
        
        if(n >= a && n < b ||
           n >= b && n < a )
        {
            break;
        }
        
        if(n < a && n < b)
        {
            a -= n;
            b -= n;
        }
        --answer;
    }
    
    return answer;
}