#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for(char c : rsp)
    {
        switch(c)
        {
        case '0':
            answer += '5';    
            break;
        case '2':
            answer += '0';
            break;
        case '5':
            answer += '2';    
            break;
        default:
            break;
        }
    }
    return answer;
}