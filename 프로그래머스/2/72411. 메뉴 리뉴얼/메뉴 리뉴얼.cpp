#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
class Combination_Str
{
public:
    Combination_Str(const string& _Str) 
        : StrData(_Str)
    {
        sort(StrData.begin(), StrData.end(), [](const char _Left, const char _Right)
            {
                return _Left < _Right;
            });
    }

    int GetNumOfMaxCombi()
    {
        return NumOfMaxCombi;
    }

    /*
    문자열 조합 재귀
    StrData : A B C F G 이고 _CombiLength : 3 라면
    
      1.          A             B        C
      2.     B    C    F      C   F     F
      3.  C F G  F G  G     F G  G     G

    위와 같이 10개의 조합이 나올 수 있음.
    */ 

 
	// 총 10개의 조합이 만들어짐.

    void GetAllCombination(string _CurCombi, int _CombiLength, int _StartIndex, map<string, int>& _Result)
    {
        if (_CurCombi.length() == _CombiLength)
        {
            int NumberOfCurStr = ++_Result[_CurCombi];
            if (NumOfMaxCombi < NumberOfCurStr)
            {
                NumOfMaxCombi = NumberOfCurStr;
            }
            return;
        }

        for (int i = _StartIndex; i < StrData.length(); ++i)
        {
            GetAllCombination(_CurCombi + StrData[i], _CombiLength, i + 1, _Result);
        }
    }

private:
    string StrData;
    int NumOfMaxCombi = 0;

};


vector<string> solution(vector<string> orders, vector<int> course) 
{
    set<string> answer;

    for (int CourseSize : course)
    {
        map<string, int> CourseMap;
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

        for (const pair<string, int>& Course : CourseMap)
        {
            if (Course.second == NumOfMaxCombi)
            {
                answer.insert(Course.first);
            }
        }
    }

    vector<string> a(answer.begin(), answer.end());

    return a;
}