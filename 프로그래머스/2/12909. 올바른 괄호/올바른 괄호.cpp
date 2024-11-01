#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int Left = 0;
    int Right = 0;
    for(char c :  s)
    {
        if(c == '(')
        {
            ++Left;
        }
        
        if(c == ')' )
        {
            ++Right;
        }
        
        if(Left < Right)
        {
            return false; 
        }
    }

    return Left == Right;
}