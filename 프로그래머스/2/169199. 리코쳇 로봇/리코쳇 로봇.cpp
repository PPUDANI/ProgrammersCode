#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<string> board)
{
    struct int2
    {
        int X = 0;
        int Y = 0;
    };

    int2 StartIndex;

    int Index_Y = static_cast<int>(board.size());
    int Index_X = static_cast<int>(board[0].size());

    vector<vector<bool>> Visit(Index_Y, vector<bool>(Index_X, false));

    // 시작위치 찾기 및 NodeIndex매핑
    for (int Y = 0; Y < Index_Y; ++Y)
    {
        for (int X = 0; X < Index_X; ++X)
        {
            if (board[Y][X] == 'R')
            {
                board[Y][X] = '.';
                Visit[Y][X] = true;
                StartIndex.X = X;
                StartIndex.Y = Y;
            }
        }
    }


    queue<int2> BFS_Queue;
    BFS_Queue.push(StartIndex);
    int BreadthNum = 1;
    int BreadthCount = 0;
    int answer = 1;
    while (true)
    {
        int2 CurIndex = BFS_Queue.front();
        BFS_Queue.pop();
        --BreadthNum;

        // Left
        int2 MovedToLeft = CurIndex;
        while (true)
        {
            if ((MovedToLeft.X - 1 < 0) || (board[MovedToLeft.Y][MovedToLeft.X - 1] == 'D'))
            {
                if (board[MovedToLeft.Y][MovedToLeft.X] == 'G')
                {
                    return answer;
                }
                else if (Visit[MovedToLeft.Y][MovedToLeft.X] == false)
                {
                    Visit[MovedToLeft.Y][MovedToLeft.X] = true;
                    BFS_Queue.push(MovedToLeft);
                    ++BreadthCount;
                }
                break;
            }
            --MovedToLeft.X;
        }

        // Right
        int2 MovedToRight = CurIndex;
        while (true)
        {
            if ((MovedToRight.X + 1 > Index_X - 1) || (board[MovedToRight.Y][MovedToRight.X + 1] == 'D'))
            {
                if (board[MovedToRight.Y][MovedToRight.X] == 'G')
                {
                    return answer;
                }
                else if (Visit[MovedToRight.Y][MovedToRight.X] == false)
                {
                    Visit[MovedToRight.Y][MovedToRight.X] = true;
                    BFS_Queue.push(MovedToRight);
                    ++BreadthCount;
                }
                break;
            }
            ++MovedToRight.X;
        }

        // Up
        int2 MovedToUp = CurIndex;
        while (true)
        {
            if ((MovedToUp.Y - 1 < 0) || (board[MovedToUp.Y - 1][MovedToUp.X] == 'D'))
            {
                if (board[MovedToUp.Y][MovedToUp.X] == 'G')
                {
                    return answer;
                }
                else if (Visit[MovedToUp.Y][MovedToUp.X] == false)
                {
                    Visit[MovedToUp.Y][MovedToUp.X] = true;
                    BFS_Queue.push(MovedToUp);
                    ++BreadthCount;
                }
                break;
            }
            --MovedToUp.Y;
        }

        // Down
        int2 MovedToDown = CurIndex;
        while (true)
        {
            if ((MovedToDown.Y + 1 > Index_Y - 1) || (board[MovedToDown.Y + 1][MovedToDown.X] == 'D'))
            {
                if (board[MovedToDown.Y][MovedToDown.X] == 'G')
                {
                    return answer;
                }
                else if (Visit[MovedToDown.Y][MovedToDown.X] == false)
                {
                    Visit[MovedToDown.Y][MovedToDown.X] = true;
                    BFS_Queue.push(MovedToDown);
                    ++BreadthCount;
                }
                break;
            }
            ++MovedToDown.Y;
        }

        if (BreadthNum == 0)
        {
            ++answer;
            BreadthNum = BreadthCount;
            BreadthCount = 0;
        }

        if (BFS_Queue.empty())
        {
            break;
        }
    }
    
    return -1;
}