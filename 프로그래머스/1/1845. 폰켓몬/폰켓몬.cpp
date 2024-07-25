#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    std::set<int> Ponketmons;
    for (int Ponketmon : nums)
    {
        Ponketmons.insert(Ponketmon);
    }
    
    int MaxNumberOfPick = static_cast<int>(nums.size()) / 2;
    int NumberOfPonketmon = static_cast<int>(Ponketmons.size());

    if (MaxNumberOfPick < NumberOfPonketmon)
    {
        return MaxNumberOfPick;
    }
    else
    {
        return NumberOfPonketmon;
    }
}