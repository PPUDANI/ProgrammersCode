#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

long long solution(long long n) 
{
    std::multiset<int, greater<int>> Set;
    while(n > 0)
    {
        Set.insert(n % 10);
        n /= 10;
    }
    
    long long answer = 0;
    for(int i : Set)
    {
        answer = answer * 10 + i;
    }

    return answer;
}