#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const string& Left, const string& Right)
{
    return Left + Right > Right + Left;
}

string solution(vector<int> numbers) 
{
    string answer = "";
    int NumOfNum = int(numbers.size());
    vector<string> strs;
    strs.reserve(NumOfNum);
    
    for(int num : numbers)
    {
        strs.push_back(to_string(num));
    }
    
    sort(strs.begin(), strs.end(), comp);
    
    for(const string& str : strs)
    {
        answer += str;
    }
    
    return answer[0] == '0' ? "0" : answer;
}