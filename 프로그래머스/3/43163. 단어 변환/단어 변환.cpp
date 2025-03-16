#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int solution(string begin, string target, vector<string> words) 
{
    int answer = 0;
    
    // target이 있는지부터 확인
    bool Changeable = false;
    for(const string& str : words)
    {
        if(str == target)
        {
            Changeable = true;
            break;
        }
    }
    
    if(Changeable == false)
    {
        return answer;
    }
    
    // begin과 글자 수 가 1개 다른 경우 push
    // DFS와 BFS 뭐가 더 좋을까.
    int WordLength = begin.length();
    int NumOfWord = int(words.size());
    
    vector<bool> IsVisit(NumOfWord, false);
    
    stack<pair<pair<string, int>, vector<bool>>, vector<pair<pair<string, int>, vector<bool>>>> DFS;
  
    DFS.push({{begin, 0}, IsVisit});

    while(!DFS.empty())
    {
        string CurStr = DFS.top().first.first;
        int CurNum = DFS.top().first.second;
        vector<bool> CurVisit = DFS.top().second;
        DFS.pop();
        
        if(CurStr == target)
        {
            answer = CurNum;
            break;
        }
        
        for(int i = 0; i < NumOfWord; ++i)
        {
            if(CurVisit[i] == true)
            {
                continue;
            }
            
            int Count = 0;
            for(int j = 0; j < WordLength; ++j)
            {
                if(words[i][j] == CurStr[j])
                {
                    ++Count;
                }
            }
            
            if(Count == WordLength - 1)
            {
                CurVisit[i] = true;
                DFS.push({{words[i], CurNum + 1}, CurVisit});
            }
        }
    }
    
    return answer;
}