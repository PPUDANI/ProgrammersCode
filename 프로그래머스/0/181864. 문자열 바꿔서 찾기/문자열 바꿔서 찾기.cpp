#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(char& c : pat)
    {
        switch(c)
        {
        case 'A':
            c = 'B';
            break;
                
        case 'B':
            c = 'A';
            break;
                
        default:
            break;
        }
    }
    
    if(myString.find(pat) != string::npos)
    {
        answer = 1;
    }
    return answer;
}