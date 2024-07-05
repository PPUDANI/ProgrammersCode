#include <vector>
#include <iostream>
int IsPrimeNumber(int _Num)
{
    for (int i = 2; i < _Num; ++i)
    {
        if (_Num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int solution(std::vector<int> nums) 
{
    int answer = 0;
    int Num = static_cast<int>(nums.size());

    for (int i = 0; i < Num; ++i)
    {
        for (int j = i + 1; j < Num; ++j)
        {
            for (int k = j + 1; k < Num; ++k)
            {
                int sum_k = nums[i] + nums[j] + nums[k];
                answer += IsPrimeNumber(sum_k);
            }
        }
    }

    return answer;
}