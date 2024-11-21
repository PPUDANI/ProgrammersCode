#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> Count (3, 0);
    
    int Ones_Ans = 1;
    
    vector<int> Twos_Ans = {2, 1, 2, 3, 2, 4, 2, 5};
    int Two_Index = 0;
    int Two_AnsSize = int(Twos_Ans.size());
    
    vector<int> Tres_Ans = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int Tre_Index = 0;
    int Tre_AnsSize = int(Tres_Ans.size());
    
    for(int Ans : answers)
    {
        // 1
        if(Ans == Ones_Ans)
        {
           ++Count[0];
        }

        if(Ones_Ans == 5)
        {
            Ones_Ans = 0;
        }
        ++Ones_Ans;
        
        // 2
        if(Ans == Twos_Ans[Two_Index])
        {
           ++Count[1]; 
        }
        ++Two_Index;
        if(Two_Index == Two_AnsSize)
        {
            Two_Index = 0;
        }
        
        // 3
        if(Ans == Tres_Ans[Tre_Index])
        {
           ++Count[2];
        }
        ++Tre_Index;
        if(Tre_Index == Tre_AnsSize)
        {
            Tre_Index = 0;
        }
    }
    
    vector<int> answer;
    int MaxAns = max( Count[0], max( Count[1],  Count[2]));
    for(int i = 0; i < 3; ++i)
    {
        if(MaxAns == Count[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}