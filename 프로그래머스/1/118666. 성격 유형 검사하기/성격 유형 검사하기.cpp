#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class CACAO_MBTI
{
public:
    CACAO_MBTI() {}

    static bool CheckTypeSequence_Left(char _Left)
    {
        if (_Left == 'R' ||
            _Left == 'C' ||
            _Left == 'J' ||
            _Left == 'A')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string GetMBTI()
    {
        string Res = "";
        Res += GetDominantType(RT, 'R', 'T');
        Res += GetDominantType(CF, 'C', 'F');
        Res += GetDominantType(JM, 'J', 'M');
        Res += GetDominantType(AN, 'A', 'N');
        return Res;
    }

    void AddScore(char _Left, int _Score)
    {
        switch (_Left)
        {
        case 'R': case 'T':
            RT += _Score;
            break;

        case 'C': case 'F':
            CF += _Score;
            break;

        case 'J': case 'M':
            JM += _Score;
            break;

        case 'A': case 'N':
            AN += _Score;
            break;

        default:
            break;
        }
    }

private:

    int RT = 0;
    int CF = 0;
    int JM = 0;
    int AN = 0;

    char GetDominantType(float Score, char _Left, char _Right)
    {
        if (Score <= 0)
        {
            return _Left;
        }
        else
        {
            return _Right;
        }
    }
};


string solution(vector<string> survey, vector<int> choices) 
{
    CACAO_MBTI Result;

    int QnANum = static_cast<int>(survey.size());

    for (int i = 0; i < QnANum; ++i)
    {
        int Score = choices[i] - 4;
        if (CACAO_MBTI::CheckTypeSequence_Left(survey[i][0]) == false)
        {
            Score *= -1;
        }
        Result.AddScore(survey[i][0], Score);
    }

    return Result.GetMBTI();
}

