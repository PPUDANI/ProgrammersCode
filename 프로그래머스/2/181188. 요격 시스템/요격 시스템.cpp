#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class int2
{
public:
    int2(int _Start = 0, int _End = 0)
        : Start(_Start), End(_End)
    {

    }
    
    static const int2 NotOverlap;

    static int2 GetOverlapRange(int2 _Left, int2 _Right)
    {
        int2 Res;

        Res.Start = _Left.Start > _Right.Start ? _Left.Start : _Right.Start;
        Res.End = _Left.End < _Right.End ? _Left.End : _Right.End;

        if (Res.Start >= Res.End)
        {
            return NotOverlap;
        }

        return Res;
    }

    bool operator == (int2 _Val)
    {
        bool Res = Start == _Val.Start && End == _Val.End;
        return Res;
    }

    bool operator != (int2 _Val)
    {
        bool Res = Start != _Val.Start || End != _Val.End;
        return Res;
    }
    int Start;
    int End;
};

const int2 int2::NotOverlap = int2(0, 0);


int solution(vector<vector<int>> targets) 
{
    sort(targets.begin(), targets.end(), [](const vector<int>& Left, const vector<int>& Right)
        {
            return Left[0] < Right[0];
        }
    );

    vector<int2> Shots;
    Shots.push_back(int2(targets[0][0], targets[0][1]));

    for (const vector<int>& Target : targets)
    {
        int2 OverlapRange;
        OverlapRange = int2::GetOverlapRange(Shots.back(), int2(Target[0], Target[1]));

        if (OverlapRange != int2::NotOverlap)
        {
            Shots.back() = OverlapRange;
            continue;
        }

        if (OverlapRange == int2::NotOverlap)
        {
            Shots.push_back(int2(Target[0], Target[1]));
        }
    }

    int answer = static_cast<int>(Shots.size());
    return answer;
}