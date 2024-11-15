#include <string>
#include <vector>
using namespace std;

int solution(int n) 
{
    if(n == 1)
    {
        return 1;
    }
    int answer = 1; // 본인

    int loop = n;
    if(n % 2 == 1) // 홀수는 무조건 하나 가능
    {
        ++answer;
    }
     
    for(int i = 3; i < loop; i += 2)
    {
        if(n % i == 0 && i % 2 == 1)
        {
            ++answer;
        }
    }
    
    
    return answer;
}