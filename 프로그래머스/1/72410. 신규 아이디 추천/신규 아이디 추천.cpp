#include <string>
#include <vector>

using namespace std;

bool Condition2Check(char _Char)
{
    if (islower(_Char) > 0)
    {
        return true;
    }
    else if (_Char >= '0' && _Char <= '9')
    {
        return true;
    }

    switch (_Char)
    {
    case '-':
    case '_':
    case '.':
        return true;
    default:
        return false;
    }
}


string solution(string new_id) {
    string answer = "";

    for (const char i : new_id)
    {
        char CurChar = tolower(i);
        if (Condition2Check(CurChar) == true)
        {
            answer += CurChar;
        }
    }


    int DotCount = 0;
    for (int i = 0; i < answer.length(); ++i)
    {
        answer[i] == '.' ? ++DotCount : DotCount = 0;
        
        if (DotCount > 1)
        {
            --DotCount;
            --i;
            answer.erase(answer.begin() + i);
        }
    }

    if (answer[0] == '.')
    {
        answer.erase(answer.begin());
    }

    if (answer.back() == '.')
    {
        answer.pop_back();
    }

    if (answer.empty())
    {
        answer += 'a';
    }

    if (answer.size() > 15)
    {
        answer.erase(answer.begin() + 15, answer.end());
    }

    if (answer.back() == '.')
    {
        answer.pop_back();
    }

    while (answer.size() < 3)
    {
        answer += answer.back();
    }


    return answer;
}