#include <string>
#include <vector>
#include <iostream>
using namespace std;

int GetNeedDate(int _progress, int _speed)
{
    int Task = 100 - _progress;
    int NeedDate = (Task / _speed) + (((Task % _speed) != 0) ? 1 : 0);
    return NeedDate;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    
    int NumOfProgram = progresses.size();;
    int CurDate = GetNeedDate(progresses[0], speeds[0]);
    int Count = 1;
    
    for(int i = 1; i < NumOfProgram; ++i)
    {
        int NeedDate = GetNeedDate(progresses[i], speeds[i]);
        if(CurDate < NeedDate)
        {
            answer.push_back(Count);
            CurDate = NeedDate;
            Count = 1;
        }
        else
        {
            ++Count;
        }
    }
    answer.push_back(Count);
    
    return answer;
}