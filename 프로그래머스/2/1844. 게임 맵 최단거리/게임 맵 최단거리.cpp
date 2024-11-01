#include<vector>
#include<queue>

using namespace std;
class int2
{
public:
    int2(int _X = 0, int _Y = 0)
        : X(_X), Y(_Y)
    {

    }

    int X;
    int Y;

    int2 operator+ (const int2& _Val) const
    {
        return int2 (X + _Val.X, Y + _Val.Y);
    }

    bool operator == (const int2& _Val) const
    {
        return (X == _Val.X) && (Y == _Val.Y);
    }
};


int solution(vector<vector<int>> maps)
{
    int YSize = maps.size();
    int XSize = maps[0].size();
    int2 Finish = int2(XSize - 1, YSize - 1);

    vector<vector<bool>> VisitCheck(YSize, vector<bool>(XSize, false));
    queue<pair<int2, int>> BFS_Q;
    BFS_Q.push({ int2(0, 0), 1 });
    VisitCheck[0][0] = true;


    vector<int2> MoveDirs = { int2(0, -1), int2(0, 1), int2(-1, 0), int2(1, 0) };

    while (!BFS_Q.empty())
    {
        int2 CurTile = BFS_Q.front().first;
        int CurDist = BFS_Q.front().second;
        BFS_Q.pop();

        if (CurTile == Finish)
        {
            return CurDist;
        }

        for (const int2 MoveDir : MoveDirs)
        {
            int2 MoveTile = CurTile + MoveDir;
            if (MoveTile.X < 0 || MoveTile.X >= XSize ||
                MoveTile.Y < 0 || MoveTile.Y >= YSize ||
                maps[MoveTile.Y][MoveTile.X] == 0)
            {
                continue;
            }
            else
            {
                if (VisitCheck[MoveTile.Y][MoveTile.X] == false)
                {
                    BFS_Q.push({ MoveTile, CurDist + 1 });
                    VisitCheck[MoveTile.Y][MoveTile.X] = true;
                }
            }
        }
    }

    return -1;
}