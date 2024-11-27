#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> Visit(n, false);
    queue<int> Q;
    Visit[0] = true;
    for(int i = 1; i < n; ++i)
    {
        if(computers[0][i] == 1)
        {
            Visit[i] = true;
            Q.push(i);
        }
    }
    
    int AllVisitCheck = false;
    while(AllVisitCheck == false)
    {
        while(!Q.empty())
        {
            int CurIndex = Q.front();
            cout << CurIndex << endl;
            Q.pop();
            
            for(int i = 0; i < n; ++i)
            {
                if(CurIndex == i)
                {
                    continue;
                } 

                if(computers[CurIndex][i] == 1) 
                {
                    if(Visit[i] == false)
                    {
                        Visit[i] = true;
                        Q.push(i);
                    }
                }
            }
        }
        
        ++answer;
        AllVisitCheck = true;
        for(int i = 0; i < n; ++i)
        {
            if(Visit[i] == false)
            {
                Visit[i] = true;
                Q.push(i);
                AllVisitCheck = false;
                break;
            }
        }
    }
    
    return answer;
}