#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long DNum = static_cast<long long>(num);

    while (DNum != 1)
    {
        if (DNum % 2 == 0)
        {
            DNum /= 2;
            ++answer;
        }
        else
        {
            DNum = ((DNum * 3) + 1) / 2;
            answer += 2;
        }

        if (answer >= 500)
        {
            return -1;
        }
    }
    return answer;
}