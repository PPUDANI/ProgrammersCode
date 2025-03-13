#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(vector<string> seoul)
{
    int Index;
    int NumOfStr = seoul.size();
    for(int i = 0; i < NumOfStr; ++i)
    {
        if(seoul[i] == "Kim")
        {
            Index = i;
            break;
        }
    }
    
    string answer = "김서방은 " + to_string(Index) + "에 있다";
    return answer;
}