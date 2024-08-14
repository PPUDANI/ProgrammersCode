#include <string>
#include <vector>
#include <cmath>    
#include <algorithm>

#define EPSILON 
bool compare(std::pair<float, int> Left, std::pair<float, int> Right)
{
    if (fabs(Left.first - Right.first) < 0.00000000001)
    {
        return Left.second < Right.second;
    }

    return Left.first > Right.first;
}

std::vector<int> solution(int N, std::vector<int> stages)
{
    std::vector<std::pair<float, int>> StageClearCounts;

    int PlayerNumber = static_cast<int>(stages.size());

    for (int i = 1; i < N + 2; ++i)
    {
        StageClearCounts.push_back(std::make_pair(0.0f, i));
    }

    for (int i : stages)
    {
        ++StageClearCounts[i - 1].first;
    }

    std::transform(StageClearCounts.begin(), StageClearCounts.end(), StageClearCounts.begin(), [&](std::pair<float, int> i)
        {
            if (PlayerNumber <= 0)
            {
                i.first = 0;
                return i;
            }

            int Num =  static_cast<int>(i.first);
            i.first /= static_cast<float>(PlayerNumber);
            PlayerNumber -= Num;
            return i;
        });

    std::sort(StageClearCounts.begin(), StageClearCounts.end() - 1, compare);
    std::vector<int> answer;

    for (int i = 0; i < N; ++i)
    {
        answer.push_back(StageClearCounts[i].second);
    }

    return answer;
}
