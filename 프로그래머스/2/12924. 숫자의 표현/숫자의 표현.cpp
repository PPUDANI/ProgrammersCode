#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int n) 
{
    if(n <= 2)
    {
        return 1;
    }
    
    int answer = 1;
    for (int i = 3; i <= n; i += 2)
	{
		if (n % i == 0)
		{
			answer += 1;
		}
	}
    
    return answer;
}