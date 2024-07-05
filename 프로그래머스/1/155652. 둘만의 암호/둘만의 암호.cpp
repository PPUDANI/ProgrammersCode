#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    int sNum = static_cast<int>(s.length());
    int skipNum = static_cast<int>(skip.length());

    // 모든 Alphabet을 따로 적재
    char Alphabet[26] = { 0, };

    // skip에 있는 Alphabet값을 -1로 수정 
    for (int i = 0 ; i < skipNum; ++i)
    {
        --Alphabet[skip[i] - 97];
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

        answer.push_back(static_cast<char>(CurIndex + 97));
    }

    return answer;
}