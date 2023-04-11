#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i = 0; i < my_string.length(); i++)
    {
        switch(my_string[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            break;
        default:
            answer += my_string[i];
        }
    }
    
    return answer;
}