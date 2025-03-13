#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

long long solution(long long n) 
{
    //std::multiset<int, greater<int>> Set;
    //while(n > 0)
    //{
    //    Set.insert(n % 10);
    //    n /= 10;
    //}
    //
    //long long answer = 0;
    //for(int i : Set)
    //{
    //    answer *= 10;
    //    answer += i;
    //}
//
    //return answer;
    
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}