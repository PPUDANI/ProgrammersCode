#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
using namespace std;

class MineralCost
{
public:
    MineralCost(int _Diamond = 0, int _Iron = 0, int _Stone = 0)
        : Diamond(_Diamond), Iron(_Iron), Stone(_Stone)
    {

    }

    union
    {
        int Mineral[3];

        struct
        {
            int Diamond;
            int Iron;
            int Stone;
        };
    };


    void AddCost(int _MineralCost)
    {
        int DiaPickCost = static_cast<int>(pow(5, _MineralCost - 3));
        int IronPickCost = static_cast<int>(pow(5, _MineralCost - 2));
        int StonePickCost = static_cast<int>(pow(5, _MineralCost - 1));

        Diamond += DiaPickCost > 0 ? DiaPickCost : 1;
        Iron += IronPickCost > 0 ? IronPickCost : 1;
        Stone += StonePickCost > 0 ? StonePickCost : 1;
    }

    bool operator < (const MineralCost& _Value) const 
    {
        if (Stone == _Value.Stone)
        {
            if (Iron == _Value.Iron)
            {
                return Diamond > _Value.Diamond;
            }
            return Iron > _Value.Iron;
        }
        return Stone > _Value.Stone;
    }
};

int solution(vector<int> picks, vector<string> minerals) 
{
    unordered_map<string, int> CostOfMineral;
    CostOfMineral.insert({ "diamond", 3 });
    CostOfMineral.insert({ "iron", 2 });
    CostOfMineral.insert({ "stone", 1 });

    // 채굴 횟수 최댓값
    int NumOfMineral = static_cast<int>(minerals.size());
    int AllPickax = picks[0] + picks[1] + picks[2];
    int MaxNumToMine = NumOfMineral < (AllPickax * 5) ? NumOfMineral : (AllPickax * 5);

    // i를 한번 더 돌릴 생각 해야함.
    priority_queue<MineralCost> CostOfSets;

    int MaxSet = (MaxNumToMine / 5) * 5;
    for (int i = 0; i < MaxSet; i += 5)
    {
        MineralCost CurSetCost = MineralCost();
        for (int j = i; j < i + 5; ++j)
        {
            CurSetCost.AddCost(CostOfMineral[minerals[j]]);
        }

        CostOfSets.push(CurSetCost);
        CurSetCost = MineralCost();
    }

    if (MaxSet != MaxNumToMine)
    {
        MineralCost EndSetCost = MineralCost();
        for (int j = MaxSet; j < MaxNumToMine; ++j)
        {
            EndSetCost.AddCost(CostOfMineral[minerals[j]]);
        }

        CostOfSets.push(EndSetCost);
    }

    MineralCost UsePickax = MineralCost();
    int SetSize = static_cast<int>(CostOfSets.size());
    for (int i = 0; i < 3; ++i)
    {
        if (picks[i] <= SetSize)
        {
            SetSize -= picks[i];
            UsePickax.Mineral[i] += picks[i];
        }
        else
        {
            UsePickax.Mineral[i] += SetSize;
            break;
        }
    }

    int answer = 0;
    for (int i = 2; i >= 0; --i)
    {
        while (UsePickax.Mineral[i] > 0)
        {
            answer += CostOfSets.top().Mineral[i];
            CostOfSets.pop();
            --UsePickax.Mineral[i];
        }
    }

    return answer;
}