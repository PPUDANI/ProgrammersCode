#include <vector>
#include <cmath>

using namespace std;

class int4
{
public:
    int4(int _Left = 0, int _Right = 0, int _Up = 0, int _Down = 0)
        :Left(_Left), Right(_Right), Up(_Up), Down(_Down) 
    {
    }

    union
    {
        int LRUD[4];
        struct
        {
            int Left;
            int Right;
            int Up;
            int Down;
        };
    };

    int4 operator +(const int4& _RValue) const
    {
        int4 Res;
        Res.Left = Left + _RValue.Left;
        Res.Right = Right + _RValue.Right;
        Res.Up = Up + _RValue.Up;
        Res.Down = Down + _RValue.Down;
        return Res;
    }
};

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;

    // 흰 공의 위치와 4방향의 쿠션과의 거리값
    int4 Start(startX, m - startX, n - startY, startY);
    for (vector<int> Ball : balls)
    {
        // Target의 위치와 4방향의 쿠션과의 거리값
        int4 Target(Ball[0], m - Ball[0], n - Ball[1], Ball[1]);

        // Start와 Target의 한 축이 겹친다면 갈 수 없는 방향 체크
        int ImmovableCushionDir = -1;
        if (startX == Ball[0])
        {
            ImmovableCushionDir = startY > Ball[1] ? 3 : 2;
        }
        else if(startY == Ball[1])
        {
            ImmovableCushionDir = startX > Ball[0] ? 0 : 1;
        }

        // 갈 수 없는 방향을 제외한 나머지 방향의 거리를 구하여 최소값 색출
        int4 Sum = Start + Target;
        int MinDistance = 2147483647;
        for (int i = 0; i < 4; ++i)
        {
            if (i == ImmovableCushionDir)
            {
                continue;
            }
            
            int StartToTarget = 0;
			switch (i)
			{
			case 0: case 1:
				StartToTarget = abs(startY - Ball[1]);
				break;
			case 2: case 3:
				StartToTarget = abs(startX - Ball[0]);
				break;
			}

            int Result = pow(Sum.LRUD[i], 2) + pow(StartToTarget, 2);
            MinDistance = min(Result, MinDistance);
        }

        answer.push_back(MinDistance);
    }

    return answer;
}