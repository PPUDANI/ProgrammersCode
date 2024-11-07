#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int YSize = int(board.size());
    int XSize = int(board[0].size());
    vector<vector<int>> AccumBoard(YSize + 1, vector<int>(XSize + 1));

    for (vector<int> Info : skill)
    {
        int Type = 1;
        if (Info[0] == 1)
        {
            Type = -1;
        }

        int StartY = Info[1];
        int StartX = Info[2];
        int EndY = Info[3] + 1;
        int EndX = Info[4] + 1;
        int Force = Info[5] * Type;

        AccumBoard[StartY][StartX] += Force;
        AccumBoard[StartY][EndX] += -Force;
        AccumBoard[EndY][StartX] += -Force;
        AccumBoard[EndY][EndX] += Force;
    }

    for (int i = 0; i < YSize; ++i)
    {
        int Accum = 0;
        for (int j = 0; j < XSize; ++j)
        {
            Accum += AccumBoard[i][j];
            AccumBoard[i][j] = Accum;
        }
    }

    for (int i = 0; i < XSize; ++i)
    {
        int Accum = 0;
        for (int j = 0; j < YSize; ++j)
        {
            Accum += AccumBoard[j][i];
            AccumBoard[j][i] = Accum;
        }
    }

    for (int i = 0; i < YSize; ++i)
    {
        for (int j = 0; j < XSize; ++j)
        {
            board[i][j] += AccumBoard[i][j];

            if (board[i][j] > 0)
            {
                ++answer;
            }
        }
    }


    return answer;
}