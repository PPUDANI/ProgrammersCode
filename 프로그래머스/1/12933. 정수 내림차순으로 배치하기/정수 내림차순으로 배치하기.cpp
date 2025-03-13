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
        cout << i;
        answer *= 10;
        answer += i;
    }

    
    return answer;
}