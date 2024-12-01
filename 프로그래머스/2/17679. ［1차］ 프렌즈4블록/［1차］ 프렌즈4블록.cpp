#include <string>
#include <vector>

using namespace std;

#define EMPTY_BLOCK '.'

bool CheckMatch(char CheckIndex1, char CheckIndex2, char CheckIndex3, char CheckIndex4)
{
    bool IsAbleMatch = false;

    if (CheckIndex1 == CheckIndex2 &&
        CheckIndex2 == CheckIndex3 &&
        CheckIndex3 == CheckIndex4)
    {
        IsAbleMatch = true;
    }

    return IsAbleMatch;
}

int solution(int m, int n, vector<string> board) 
{
    int Loop_Height = m - 1;
    int Loop_Width = n - 1;
    
    int NumOfScore = 0;
    bool IsAbleMatch = true;
    
    while (IsAbleMatch)
    {
        IsAbleMatch = false; // 전체 매치 가능 여부 체크
        vector<vector<bool>> IsMatchBlock(m, vector<bool>(n, false)); // 매치된 블록 체크

        for (int i = 0; i < Loop_Height; ++i)
        {
            for (int j = 0; j < Loop_Width; ++j)
            {
                if (board[i][j] == EMPTY_BLOCK)
                {
                    continue;
                }

                if (CheckMatch(board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1]))
                {
                    IsMatchBlock[i][j] = true;
                    IsMatchBlock[i][j + 1] = true;
                    IsMatchBlock[i + 1][j] = true;
                    IsMatchBlock[i + 1][j + 1] = true;
                    IsAbleMatch = true;
                }
            }
        }

        // 매치된 블록 제거 
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (IsMatchBlock[i][j] == true)
                {
                    board[i][j] = EMPTY_BLOCK;
                    ++NumOfScore;
                }
            }
        }

        // 빈공간으로 내리기
        for (int j = 0; j < n; ++j)
        {
            for (int i = m - 2; i >= 0; --i)
            {
                if (board[i][j] == EMPTY_BLOCK)
                {
                    continue;
                }

                int CheckHeight = i;
                bool IsAbleDown = false;
                while (CheckHeight < m - 1)
                {
                    if (board[CheckHeight + 1][j] == EMPTY_BLOCK)
                    {
                        IsAbleDown = true;
                        ++CheckHeight;
                    }
                    else
                    {
                        break;
                    }
                }

                if (IsAbleDown)
                {
                    board[CheckHeight][j] = board[i][j];
                    board[i][j] = EMPTY_BLOCK;
                }
            }
        }
    }

    return NumOfScore;
}