#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    std::vector<int> ScoreNumber(k + 1, 0);

    for (int i : score)
    {
        ++ScoreNumber[i];
    }

    int RestApple = 0;
    for (int i = k; i > 0; --i)
    {
        int CurScoreAppleNumber = (ScoreNumber[i] + RestApple);
        int CanMakeBox = CurScoreAppleNumber / m;
        RestApple = CurScoreAppleNumber % m;
        answer += i * m * CanMakeBox;
    }

    return answer;
}