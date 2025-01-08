#include <string>
#include <vector>
#include <queue>

using namespace std;

#define Max 10000
int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
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
    
    queue<pair<string, int>> BFS;
    
    BFS.push({begin, 0});
    while(!BFS.empty())
    {
        string CurStr = BFS.front().first;
        int CurCount = BFS.front().second;
        BFS.pop();
        
        if(CurStr == target)
        {
            return CurCount;
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
                BFS.push({word, CurCount + 1});
            }
            ++WordIndex;
        }
    }
    
    return 0;
}