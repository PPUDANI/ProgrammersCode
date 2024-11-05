#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(islower(s[0]))
    {
        s[0] = toupper(s[0]);
    }
    
    int StrLength = int(s.length());
    
    for(int i = 1; i < StrLength; ++i)
    {
        if(s[i - 1] == ' ')
        {
            if(islower(s[i]))
            {
                s[i] = toupper(s[i]);
            }
        }
        else
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    return  s;
}