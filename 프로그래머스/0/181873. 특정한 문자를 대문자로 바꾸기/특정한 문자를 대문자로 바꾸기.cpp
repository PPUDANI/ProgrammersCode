#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    
    for(char c : my_string)
    {
        for(char alp_c : alp)
        {
            if(c == alp_c)
            {
               c = toupper(c);
            }
            answer += c;
        }
    }
    return answer;
}