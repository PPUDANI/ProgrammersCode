#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int EmptyBottle = 0;
    int AddCoke = 0;

    while (n >= a)
    {
        int Division = n / a;
        int Remainder = n % a;
        EmptyBottle += Division * b;
        n = Division * b + Remainder;
    }
    return EmptyBottle;
}