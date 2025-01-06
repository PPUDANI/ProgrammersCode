#include <string>
#include <vector>
#include <stack>

using namespace std;

#define Max 10000
int solution(string begin, string target, vector<string> words) 
{
    int answer = Max;
    int wordlength = int(begin.length());
    bool IsChangeable = false;
    for(const string& word : words)
    {
        if(word == target)
        {
            IsChangeable = true;
        }
    }
    
    if(IsChangeable == false)
    {
        return 0;
    }
    
    vector<bool> Changed( words.size(), false);
    
    stack<pair<pair<string, int>, vector<bool>>> DFS;
    
    DFS.push({{begin, 0}, Changed});
    while(!DFS.empty())
    {
        string CurStr = DFS.top().first.first;
        int CurCount = DFS.top().first.second;
        vector<bool> CurChanged = DFS.top().second;
        DFS.pop();
        
        if(CurStr == target)
        {
            answer = min(answer, CurCount);
        }
        
        int WordIndex = 0;
        for(const string& word : words)
        {
            int SameAlpha = 0;
            for(int i = 0; i < wordlength; ++i)
            {
                if(CurStr[i] == word[i])
                {
                    ++SameAlpha;
                }
            }
            
            if(SameAlpha == wordlength - 1)
            {
                if (Changed[WordIndex] == false)
                {
                    Changed[WordIndex] = true;
                    DFS.push({{word, CurCount + 1}, CurChanged});
                }
            }
            ++WordIndex;
        }
    }
    
    return answer;
}