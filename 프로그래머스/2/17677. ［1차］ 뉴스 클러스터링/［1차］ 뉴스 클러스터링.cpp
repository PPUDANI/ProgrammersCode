#include <string>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <numeric>
using namespace std;

void ToUpperStr(string& str)
{
    int StrLen = str.length();
    for(int i = 0; i < StrLen; ++i)
    {
        str[i] = toupper(str[i]);
    }
}

int solution(string str1, string str2) 
{
    ToUpperStr(str1);
    ToUpperStr(str2);
    
    unordered_map<string, int> Eliments;
    
    if(str1.length() > str2.length())
    {
        swap(str1, str2);
    }
    
    int str1Loop = str1.length() - 1;
    for(int i = 0; i < str1Loop; ++i)
    {
        string NewEliment = std::move(str1.substr(i, 2));
        if(!isalpha(NewEliment[0]))
        {
            continue;
        }
        else if(!isalpha(NewEliment[1]))
        {
            ++i;
        }
        else
        {
            ++Eliments[NewEliment];
        }
    }

    int UnionCount = 0;
    int ItersectionCount = 0;
    
    int str2Loop = str2.length() - 1;
    for(int i = 0; i < str2Loop; ++i)
    {
        string NewEliment = std::move(str2.substr(i, 2));
        if(!isalpha(NewEliment[0]))
        {
            continue;
        }
        else if(!isalpha(NewEliment[1]))
        {
            ++i;
            continue;
        }
        else
        {
            if(Eliments.find(NewEliment) != Eliments.end())
            {
                if(Eliments[NewEliment] > 0)
                {
                    --Eliments[NewEliment];
                    ++ItersectionCount;
                }
            }
            
            ++UnionCount;
        }
    }
    
    UnionCount += accumulate(Eliments.begin(), Eliments.end(), 0, 
                             [](int acc, const pair<string, int>& p)
                             {
                                 return acc + p.second;
                             });
    float res = 1;
    if(UnionCount != 0 || ItersectionCount != 0)
    {
        res = float(ItersectionCount) / float(UnionCount);
    }

    int answer = res * 65536.0f;
    
    return answer;
}