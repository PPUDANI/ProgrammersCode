#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    // 중복이 없고 정렬이 필요없는 unordered_set을 사용
    std::unordered_set<int> Ponketmons(nums.begin(), nums.end());
    
    int MaxNumberOfPick = static_cast<int>(nums.size()) / 2;
    int NumberOfPonketmon = static_cast<int>(Ponketmons.size());

    return MaxNumberOfPick < NumberOfPonketmon ? MaxNumberOfPick : NumberOfPonketmon;
}