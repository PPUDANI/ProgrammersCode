#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    std::stack<int> Basket;
    Basket.push(-1);

    int Height = board.size(); // N * N size
    for (int i : moves)
    {
        --i;
        for (int j = 0; j < Height; ++j)
        {
            if (board[j][i] == 0)
            {
                continue;
            }
            else
            {
                int a = Basket.top();
                int b = board[j][i];
                if (a == b)
                {
                    Basket.pop();
                    answer += 2;
                }
                else
                {
                    Basket.push(board[j][i]);
                }
                board[j][i] = 0;
                break;
            }
        }
    }
    return answer;
}