#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n, 0);
    long long longX = static_cast<long long>(x);

    for (int i = 0; i < n; ++i)
    {
        answer[i] = longX * (i + 1);
    }

    return answer;
}