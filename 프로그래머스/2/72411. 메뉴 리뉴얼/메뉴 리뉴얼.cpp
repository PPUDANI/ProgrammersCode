#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 재귀로 넘기는 Parameter를 최소화 하기위해 Class로 제작함.
class Combination_Str
{
public:
    Combination_Str(const string& _Eliments, const int _CombiLength)
        : Eliments(_Eliments), CombiLength(_CombiLength)
    {
        // 생성 시 문자열을 오름차순으로 정렬
        sort(Eliments.begin(), Eliments.end(), [](const char _Left, const char _Right)
            {
                return _Left < _Right;
            });

        NumOfElement = static_cast<int>(Eliments.length());
    }

    // 가장 많은 조합 리턴
    inline int GetNumOfMostCombi() const
    {
        return NumOfMostCombi;
    }
    
    void GetAllCombination(int _StartIndex, string _CurCombi, unordered_map<string, int>& _Combis)
    {
        int _DigitCount = CombiLength - 1;
        CalculateCombination(_StartIndex, _DigitCount, _CurCombi, _Combis);
    }

    // 재귀 함수
    void CalculateCombination(int _StartIndex, int _DigitCount, string _CurCombi, unordered_map<string, int>& _Combis)
    {
        if (_CurCombi.length() == CombiLength)
        {
            int NumberOfCurStr = ++_Combis[_CurCombi];
            NumOfMostCombi = max(NumOfMostCombi, NumberOfCurStr);
            return;
        }

        if (_DigitCount > 0)
        {
            --_DigitCount;
        }

        for (int i = _StartIndex; i < NumOfElement - _DigitCount; ++i)
        {
            CalculateCombination(i + 1, _DigitCount, _CurCombi + Eliments[i], _Combis);
        }

        return;
    }

private:
    string Eliments;
    int NumOfElement;

    int CombiLength;
    int NumOfMostCombi = 0;

};


vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;

    for (int CourseLength : course)
    {
        unordered_map<string, int> CourseMap;
        int NumOfMostCombi = 0;

        // 모든 코스 생성.
        for (const string& Order : orders)
        {
            Combination_Str CombiInst(Order, CourseLength);
            CombiInst.GetAllCombination(0, "", CourseMap);
            NumOfMostCombi = max(NumOfMostCombi, CombiInst.GetNumOfMostCombi());
        }

        // 가장 많이은 조합의 개수가 1이라면 continue.
        if (NumOfMostCombi == 1)
        {
            continue;
        }

        // 가장 많이은 조합의 개수와 일치하면 적재
        for (const pair<string, int>& Course : CourseMap)
        {
            if (Course.second == NumOfMostCombi)
            {
                answer.push_back(Course.first);
            }
        }
    }

    // 정렬
    sort(answer.begin(), answer.end(), [](const string& _Left, const string& _Right)
        {
            return _Left < _Right;
        });

    return answer;
}