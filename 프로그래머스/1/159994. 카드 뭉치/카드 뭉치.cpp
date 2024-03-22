#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    
    int Card1Num = 0;
    int Card2Num = 0;
    for(int i = 0 ; i < goal.size(); ++i)
    {
        if(goal[i] == cards1[Card1Num])
        {
            ++Card1Num;
        }
        else if(goal[i] == cards2[Card2Num])
        {
            ++Card2Num;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}