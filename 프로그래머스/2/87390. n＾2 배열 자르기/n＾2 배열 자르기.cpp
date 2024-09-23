#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve(right - left);

    int LeftIndexY = left / n;
    int LeftIndexX = left % n;

    int RightIndexY = right / n;
    int RightIndexX = right % n;

    for (int Y = LeftIndexY; Y <= RightIndexY; ++Y)
    {
        int Count = (Y == LeftIndexY) ? LeftIndexX : 0;
        int Max_X = (Y == RightIndexY) ? RightIndexX + 1 : n;

        for (int X = Count; X < Max_X; ++X)
        {
            int Eliment = X < Y ? Y + 1 : X + 1;
            answer.push_back(Eliment);
        }
    }

    return answer;
}