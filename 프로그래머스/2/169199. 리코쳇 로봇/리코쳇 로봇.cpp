#include <string>
#include <vector>
#include <queue>

using namespace std;

// 좌표를 담을 구조체
struct int2
{
    int X = 0;
    int Y = 0;

    int2 operator +(int2 _Val)
    {
        int2 Res;
        Res.X = X + _Val.X;
        Res.Y = Y + _Val.Y;
        return Res;
    }

    int2 operator -=(int2 _Val)
    {
        X -= _Val.X;
        Y -= _Val.Y;
        return *this;
    }
};

// Board 이탈 체크 함수
bool IsIndexOver(int2 _Check, int2 Max)
{
    if (_Check.X < 0 || _Check.Y < 0 || _Check.X > Max.X - 1 || _Check.Y > Max.Y - 1)
    {
        return true;
    }

    return false;
}

// 해당 Index가 벽인지 체크
bool IsBlock(char _Index)
{
    if (_Index == 'D')
    {
        return true;
    }

    return false;
}

int solution(vector<string> board)
{
    int2 BoardSize;
    BoardSize.X = static_cast<int>(board[0].size());
    BoardSize.Y = static_cast<int>(board.size());

    vector<vector<bool>> Visit(BoardSize.Y, vector<bool>(BoardSize.X, false));
    int2 StartIndex;

    // 시작위치 찾기 및 NodeIndex매핑
    for (int Y = 0; Y < BoardSize.Y; ++Y)
    {
        for (int X = 0; X < BoardSize.X; ++X)
        {
            if (board[Y][X] == 'R')
            {
                Visit[Y][X] = true;
                StartIndex.X = X;
                StartIndex.Y = Y;
            }
        }
    }

    // BFS를 위한 큐 생성 및 Start 삽입
    queue<int2> BFS_Queue;
    BFS_Queue.push(StartIndex);

    // 횟수 측정
    int answer = 1; // 움직인 횟수
    int BreadthNum = 1; // 너비 크기
    int BreadthCount = 0; // 너비를 탐색한 횟수

    vector<int2> MoveVector = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (BFS_Queue.empty() == false)
    {
        int2 CheckIndex = BFS_Queue.front();
        BFS_Queue.pop();
        --BreadthNum;

        // Left, Right, Up, Down 체크
        for (int i = 0; i < 4; ++i)
        {
            int2 CurIndex = CheckIndex;
            while (true)
            {
                int2 NextIndex = CurIndex + MoveVector[i];
                if (IsIndexOver(NextIndex, BoardSize) || IsBlock(board[NextIndex.Y][NextIndex.X]))
                {
                    if (board[CurIndex.Y][CurIndex.X] == 'G')
                    {
                        return answer;
                    }
                    else if (Visit[CurIndex.Y][CurIndex.X] == false)
                    {
                        Visit[CurIndex.Y][CurIndex.X] = true;
                        BFS_Queue.push(CurIndex);
                        ++BreadthCount;
                    }
                    break;
                }
                CurIndex = NextIndex;
            }
        }
        
        // 현재 라인 전부 탐색했다면 다음 라인 탐색
        if (BreadthNum == 0)
        {
            ++answer;
            BreadthNum = BreadthCount;
            BreadthCount = 0;
        }
    }
    
    return -1;
}
