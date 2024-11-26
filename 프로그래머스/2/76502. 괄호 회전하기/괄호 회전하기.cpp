#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) 
{
    string NewString = s + s;
    int StringLength = NewString.length();
    int S_Length = s.length();
    
    stack<char> StackCheck;
    StackCheck.push('_');
    int answer = 0;
    for(int x = 0; x < S_Length; ++x)
    {
        bool IsWrong = false;
        for(int j = 0; j < S_Length; ++j)
        {
            char CurChar = NewString[x + j];
            switch(CurChar)
            {
            case '(': case '{': case '[':
                StackCheck.push(CurChar);
                break;
        
            case ')':
                if(StackCheck.top() == '(')
                {
                    StackCheck.pop();
                    break;
                }
                IsWrong = true;
                break;
                    
            case '}':
                if(StackCheck.top() == '{')
                {
                    StackCheck.pop();
                    break;
                }
                IsWrong = true;
                break;
                    
            case ']':
                if(StackCheck.top() == '[')
                {
                    StackCheck.pop();
                    break;
                }
                IsWrong = true;
                break;
            }
            
            if(IsWrong == true)
            {
                break;
            }
        }

        if(IsWrong != true &&StackCheck.size() == 1)
        {
            ++answer;
        }
    }

    return answer;
}