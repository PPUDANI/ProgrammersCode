#include <vector>
#include <iostream>
using namespace std;

int IsPrimeNumber(int _Num)
{
    int count = 0;
    for (int i = 2; i < _Num; ++i)
    {
        if (_Num % i == 0)
        {
            ++count;
        }
    }

    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int solution(std::vector<int> nums) {
    int answer = 0;

    int Num = nums.size();


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