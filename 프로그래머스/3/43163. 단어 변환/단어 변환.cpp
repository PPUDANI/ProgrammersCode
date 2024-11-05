#include <string>
#include <vector>
#include <stack>
using namespace std;

#define INF 100;
int solution(string begin, string target, vector<string> words) 
{
    int NumOfWord = int(words.size());
    int WordLength = int(begin.length());
    
    // Target Check
    bool AbleChangeWord = false;
    for(int i = 0; i < NumOfWord; ++i)
    {
        if(words[i] == target)
        {
            AbleChangeWord = true;
        }
    }
        
    if(AbleChangeWord == false)
    {
        return 0;
    }
    
    
    stack <pair<pair<int, int>, vector<bool>>, vector<pair<pair<int, int>, vector<bool>>>> DFS;
    vector<bool> Visit(NumOfWord, false);
    
    // First Element
    for(int i = 0; i < NumOfWord; ++i)
    {
        int DifCount = 0;
        for(int j = 0; j < WordLength; ++j)
        {
            if(words[i][j] != begin[j])
            {
                ++DifCount;
            }
        }
        
        if(DifCount == 1)
        {
            Visit[i] = true;
            DFS.push({{i, 1}, Visit});
        }
    }


    int answer = INF;
    while(!DFS.empty())
    {
        auto CurInfo = DFS.top().first;
        auto CurVisit = DFS.top().second;
        DFS.pop();
        
        if(words[CurInfo.first] == target)
        {
            answer = min(answer, CurInfo.second);
            continue;
        }
        
        for(int i = 0; i < NumOfWord; ++i)
        {
            if(CurVisit[i] == false)
            {
                int DifCount = 0;
                for(int j = 0; j < WordLength; ++j)
                {
                    if(words[CurInfo.first][j] != words[i][j])
                    {
                        ++DifCount;
                    }
                }
                
                if(DifCount == 1)
                {
                    CurVisit[i] = true;
                    DFS.push({{i, CurInfo.second + 1}, CurVisit});
                }
            }
        }
    }
    
    return answer;
}