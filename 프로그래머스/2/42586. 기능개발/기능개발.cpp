#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    int NumOfProgram = progresses.size();
    vector<int> EndDate(NumOfProgram);
    for(int i = 0; i < NumOfProgram; ++i)
    {
        int Task = 100 - progresses[i];
        int NeedDate = (Task / speeds[i]) + (((Task % speeds[i]) != 0) ? 1 : 0);
        EndDate[i] = NeedDate;
    }
    
    vector<int> answer;
    
    int Count = 1;
    int CurIndex = 0;
    int PrevMaxDate = EndDate[CurIndex];
    
    while(CurIndex < NumOfProgram)
    {
        ++CurIndex;
        if(CurIndex == NumOfProgram)
        {
            answer.push_back(Count);
            break;
        }
        if(PrevMaxDate >= EndDate[CurIndex])
        {
            ++Count;
        }
        else
        {
            PrevMaxDate = EndDate[CurIndex];
            answer.push_back(Count);
            Count = 1;
        }
    }
    
    return answer;
}