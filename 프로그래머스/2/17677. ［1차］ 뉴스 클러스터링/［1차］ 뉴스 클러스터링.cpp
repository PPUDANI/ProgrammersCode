#include <string>
#include <unordered_set>
#include <cctype>
#include <algorithm>

using namespace std;

void StandardizationStr(string& Res, const string& str)
{
    int StrLen = str.length();
    for(int i = 0; i < StrLen; ++i)
    {
        Res += toupper(str[i]);
    }
}


int solution(string str1, string str2) 
{
    unordered_multiset<string> Eliments;
    unordered_multiset<string> Eliment2;
    
    string StandardStr1 = "";
    string StandardStr2 = "";
    StandardizationStr(StandardStr1, str1);
    StandardizationStr(StandardStr2, str2);
    
    if(StandardStr1.length() > StandardStr2.length())
    {
        swap(StandardStr1, StandardStr2);
    }
    
    int str1Loop = StandardStr1.length() - 1;
    for(int i = 0; i < str1Loop; ++i)
    {
        string NewEliment = StandardStr1.substr(i, 2);
        if(isalpha(NewEliment[0]) && isalpha(NewEliment[1]))
        {
            Eliments.insert(NewEliment);
        }
    }

    int UnionCount = 0;
    int ItersectionCount = 0;
    
    int str2Loop = StandardStr2.length() - 1;
    for(int i = 0; i < str2Loop; ++i)
    {
        string NewEliment = StandardStr2.substr(i, 2);
        
        if(isalpha(NewEliment[0]) && isalpha(NewEliment[1]))
        {
            auto FindedEliment = Eliments.find(NewEliment);
            if(FindedEliment != Eliments.end())
            {
                Eliments.erase(FindedEliment);
                ++ItersectionCount;
            }
            ++UnionCount;
        }
    }
    UnionCount += Eliments.size();
    
    
    float res;
    if(UnionCount == 0 && ItersectionCount == 0)
    {
        res = 1;
    }
    else
    {
        res = float(ItersectionCount) / float(UnionCount);
    }
    int answer = res * 65536.0f;
    
    return answer;
}