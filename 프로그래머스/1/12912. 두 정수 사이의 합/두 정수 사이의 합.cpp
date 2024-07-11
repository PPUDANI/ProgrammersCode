#include <string>
#include <vector>

using namespace std;
long long Sum(int a, int b)
{
    long long res = 0;
    long long Num = b - a + 1;
    long long sum = a + b;
    if (Num % 2 == 1)
    {
        --Num;
        res += sum / 2;
    }

    res += sum * (Num / 2);
    return res;
}

long long solution(int a, int b) 
{
    long long answer = 0;

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a < 0)
    {
        if (b < 0)
        {
            answer -= Sum(abs(b), abs(a));
        }
        else
        {
            answer -= Sum(1, abs(a));
            answer += Sum(1, b);
        }
    }
    else
    {
        answer = Sum(a, b);
    }

    return answer;
}
