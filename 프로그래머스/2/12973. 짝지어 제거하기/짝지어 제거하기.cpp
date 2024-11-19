#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    int StrLen = s.length();
    vector<char> CharStack;
    CharStack.reserve(StrLen);
    CharStack.push_back(s[0]);
    int CurIndex = 0;
    
    for(int i = 1; i < StrLen; ++i)
    {
        if(CharStack.empty() || CharStack.back() != s[i])
        {
            CharStack.push_back(s[i]);
        }
        else
        {
            CharStack.pop_back();
        }
    }
    
    if(CharStack.empty())
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}