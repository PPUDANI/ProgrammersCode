#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for(char c : myString)
    {
        if(c == 'a' || c == 'A')
        {
            c = 'A';
        }
        else if(isupper(c))
        {
            c = tolower(c);
        }
        
        answer += c;
    }
    return answer;
}