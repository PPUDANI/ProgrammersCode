#include <vector>
#include <set>
#include <algorithm>

int solution(int n, int k, std::vector<int> enemy)
{
    int answer = 0;

    size_t RoundCount = enemy.size();

    std::multiset<int, std::greater<int>> ClearRound;

    for (size_t i = 0; i < RoundCount; ++i)
    {
        n -= enemy[i];

        if (n < 0)
        {
            if (k > 0)
            {
                --k;
                ClearRound.insert(enemy[i]);
                n += *(ClearRound.begin());
                ClearRound.erase(ClearRound.begin());
                ++answer;
            }
            else
            {
                break;
            }
        }
        else
        {
            ++answer;
            ClearRound.insert(enemy[i]);
        }
    }

    return answer;
}