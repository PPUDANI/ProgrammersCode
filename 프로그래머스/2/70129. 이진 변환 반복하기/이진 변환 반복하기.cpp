#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {

    int FirstZeroCount = 0;
    for(char c : s)
    {
        if(c == '0')
        {
            ++FirstZeroCount;
        }
    }
    
    int FirstOneCount = s.length() - FirstZeroCount;
    vector<int> answer = {1, FirstZeroCount};
    
    int CurLength = FirstOneCount;
    
    if(CurLength <= 1)
    {
        return answer;
    }
    int ZeroCount = 0;
    int Length = 0;
    
    while(1)
    {
        ZeroCount = 0;
        Length = 0;
        while(CurLength > 0)
        {
            if(CurLength % 2 == 0)
            {
                ++ZeroCount;
            }
            
            CurLength /= 2;
            ++Length;
        }
        
        CurLength = Length - ZeroCount;
        ++answer[0];
        answer[1] += ZeroCount;
        
        if (CurLength <= 1)
        {
            break;
        }
    }
    
    return answer;
}