#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    int sNum = static_cast<int>(s.length());
    int skipNum = static_cast<int>(skip.length());
    char Alphabet[26];

    for (int i = 0; i < 26; ++i)
    {
        Alphabet[i] = 'a' + i;
    }

    for (int i = 0 ; i < skipNum; ++i)
    {
        Alphabet[skip[i] - 97] = -1;
    }

    for (int i = 0; i < sNum; ++i)
    {
        int CurIndex = s[i] - 97;
        int Count = index;
        while (Count)
        {
            ++CurIndex;

            if (CurIndex > 25)
            {
                CurIndex -= 26;
            }

            if (Alphabet[CurIndex] != -1)
            {
                --Count;
            }
        }

        answer.push_back(Alphabet[CurIndex]);
    }


    return answer;
}