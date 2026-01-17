#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool visited[10001];

bool dfs(const string& Airport, const vector<vector<string>>& tickets, int count)
{
    if(count == tickets.size())
    {
        return true;
    }

    for(int i = 0; i < tickets.size(); ++i)
    {
        if(visited[i] == false && tickets[i][0] == Airport)
        {
            visited[i] = true;
            answer.push_back(tickets[i][1]);
            if(dfs(tickets[i][1], tickets, count + 1))
            {
                return true;
            }
            
            answer.pop_back();
            visited[i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
    sort(tickets.begin(), tickets.end());
    
    string Start = "ICN";
    answer.push_back(Start);
    dfs(Start, tickets, 0);
    
    
    return answer;
}