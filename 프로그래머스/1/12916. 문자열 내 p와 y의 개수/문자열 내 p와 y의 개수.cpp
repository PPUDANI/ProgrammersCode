#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int PCount = 0;
    int YCount = 0;
    
    for(char c : s)
    {
        c = std::tolower(c);
        
        if(c == 'p')
        {
            ++PCount;
        }
        else if(c == 'y')
        {
            ++YCount;
        }
    }
    
    return PCount == YCount ? true : false;
}