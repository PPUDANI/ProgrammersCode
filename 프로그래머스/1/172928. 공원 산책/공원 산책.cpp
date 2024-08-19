#include <string>
#include <vector>

using namespace std;

class Coordinate
{
public:
    Coordinate() 
    {
        X = 0;
        Y = 0;
    };
    Coordinate(int _X, int _Y) : X(_X), Y(_Y)
    { 

    }

    int X;
    int Y;

    Coordinate operator +=(const Coordinate Value)
    {
        Coordinate Res;
        X += Value.X;
        Y += Value.Y;
        return *(this);
    }

    Coordinate operator +(const Coordinate Value) const
    {
        Coordinate Res;
        Res.X += Value.X;
        Res.Y += Value.Y;
        return Res;
    }

private:

};

vector<int> solution(vector<string> park, vector<string> routes) 
{
    vector<int> answer = {0, 0};

    int ParkHeight = static_cast<int>(park.size());
    int ParkWidth = static_cast<int>(park[0].length());

    // 시작 지점 찾기
    Coordinate CurRobotIndex;
    for (int Y = 0; Y < ParkHeight; ++Y)
    {
        for (int X = 0; X < ParkWidth; ++X)
        {
            if (park[Y][X] == 'S')
            {
                CurRobotIndex = { X, Y };
                break;
            }
        }
    }

    // 명령 수행
    int RoutesNum = static_cast<int>(routes.size());
    for (int i = 0; i < RoutesNum; ++i)
    {
        // 방향 체크
        Coordinate Direction;
        switch (routes[i][0])
        {
        case 'E': // 동
            Direction = { 1, 0 };
            break;

        case 'W': // 서
            Direction = { -1, 0 };
            break;

        case 'S': // 남
            Direction = { 0, 1 };
            break;

        case 'N': // 북
            Direction = { 0, -1 };
            break;

        default:
            Direction = { 0, 0 };
            break;
        }

        // 이동 여부 체크
        bool IsMoved = true;
        Coordinate MoveIndex = CurRobotIndex;
        int Distance = static_cast<int>(routes[i][2] - '0');
        for (int j = 0; j < Distance; ++j)
        {
            MoveIndex += Direction;

            if (0 > MoveIndex.Y ||
                0 > MoveIndex.X ||
                ParkHeight <= MoveIndex.Y ||
                ParkWidth <= MoveIndex.X ||
                park[MoveIndex.Y][MoveIndex.X] == 'X')
            {
                IsMoved = false;
                break;
            }
        }

        if (IsMoved == true)
        {
            CurRobotIndex = MoveIndex;
        }
    }
    answer[0] = CurRobotIndex.Y;
    answer[1] = CurRobotIndex.X;
    return answer;
}
