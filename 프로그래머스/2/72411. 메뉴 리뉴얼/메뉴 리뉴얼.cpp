#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Combination_Str
{
public:
    Combination_Str(const string& _Str) 
        : StrData(_Str)
    {

    }

    int GetNumOfMaxCombi()
    {
        return NumOfMaxCombi;
    }

    void GetAllCombination(string _Combi, int _CombiLength, int _Start, unordered_map<string, int>& _Result)
    {
        if (_Combi.length() == _CombiLength)
        {
            sort(_Combi.begin(), _Combi.end(), [](const char _Left, const char _Right)
                {
                    return _Left < _Right;
                });

            int NumberOfCurStr = ++_Result[_Combi];
            if (NumOfMaxCombi < NumberOfCurStr)
            {
                NumOfMaxCombi = NumberOfCurStr;
            }

            return;
        }

        for (int i = _Start; i < StrData.length(); ++i)
        {
            GetAllCombination(_Combi + StrData[i], _CombiLength, i + 1, _Result);
        }
    }

private:
    string StrData;
    int NumOfMaxCombi = 0;
};


vector<string> solution(vector<string> orders, vector<int> course) 
{
    vector<string> answer;

    for (int CourseSize : course)
    {
        unordered_map<string, int> CourseMap;
        int NumOfMaxCombi = 0;
        for (const string& Order : orders)
        {
            Combination_Str CourseCombi(Order);
            CourseCombi.GetAllCombination("", CourseSize, 0, CourseMap);
            if (NumOfMaxCombi < CourseCombi.GetNumOfMaxCombi())
            {
                NumOfMaxCombi = CourseCombi.GetNumOfMaxCombi();
            }
        }

        if (NumOfMaxCombi == 1)
        {
            continue;
        }

        for (pair<string, int> Course : CourseMap)
        {
            if (Course.second == NumOfMaxCombi)
            {
                answer.push_back(Course.first);
            }
        }
    }

    sort(answer.begin(), answer.end(), [](const string& _Left, const string& _Right)
        {
            return _Left < _Right;
        });

    return answer;
}