#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{ 
    int answer = 0;
    int NumOfDungeon = int(dungeons.size());
    vector<bool> Visit(NumOfDungeon, false);
    
    stack<pair<int, vector<bool>>, vector<pair<int, vector<bool>>>> DFS;
    
    for(int i = 0; i < NumOfDungeon; ++i)
    {
        if(k >= dungeons[i][0])
        {
            vector<bool> NextVisit = Visit;
            NextVisit[i] = true;
            DFS.push({k - dungeons[i][1], NextVisit});
        }
    }
    
    while(!DFS.empty())
    {
        int CurStemina = DFS.top().first;
        vector<bool> CurVisit = DFS.top().second;
        DFS.pop();

        bool IsEnd = true;
        for(int i = 0; i < NumOfDungeon; ++i)
        {
            if(CurVisit[i] == true)
            {
                continue;
            }
            
            if(CurStemina >= dungeons[i][0])
            {
                vector<bool> NextVisit = CurVisit;
                NextVisit[i] = true;
                DFS.push({CurStemina - dungeons[i][1], NextVisit});
                IsEnd = false;
            }
        }
        
        if(IsEnd == true)
        {
            int NumOfVisit = count(CurVisit.begin(), CurVisit.end(), true);
            answer = max(answer, NumOfVisit);
        }
    }
    
    return answer;
}