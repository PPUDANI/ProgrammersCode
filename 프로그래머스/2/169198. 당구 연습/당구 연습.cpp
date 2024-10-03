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
        int Arr[4];
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

int4 GetAcsIndex(int4 _Val)
{
    int4 MinSort(0, 1, 2, 3);
    int Min = 2147483647;
    int MinIndex = -1;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = i + 1; j < 4; ++j)
        {
            if (_Val.Arr[i] > _Val.Arr[j])
            {
                swap(_Val.Arr[i], _Val.Arr[j]);
                swap(MinSort.Arr[i], MinSort.Arr[j]);
            }
        }
    }

    return MinSort;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;
    int4 Start(startX, m - startX, n - startY, startY);

    for (vector<int> Ball : balls)
    {
        int4 Target(Ball[0], m - Ball[0], n - Ball[1], Ball[1]);

        int ImmovableCushionDir = -1;
        if (startX == Ball[0])
        {
            ImmovableCushionDir = startY > Ball[1] ? 3 : 2;
        }
        else if(startY == Ball[1])
        {
            ImmovableCushionDir = startX > Ball[0] ? 0 : 1;
        }

        int4 Sum = Start + Target;
        //int4 AcsSumIndex = GetAcsIndex(Sum);

        //int NearDirIndex = AcsSumIndex.Arr[0] != ImmovableCushionDir ? AcsSumIndex.Arr[0] : AcsSumIndex.Arr[1];
        int MinDistance = 2147483647;
        for (int j = 0; j < 4; ++j)
        {
            if (j == ImmovableCushionDir)
            {
                continue;
            }
            
            int StartToTarget = 0;

			switch (j)
			{
			case 0: case 1:
				StartToTarget = abs(startY - Ball[1]);
				break;
			case 2: case 3:
				StartToTarget = abs(startX - Ball[0]);
				break;
			}

            int Result = pow(Sum.LRUD[j], 2) + pow(StartToTarget, 2);
            MinDistance = min(Result, MinDistance);
        }
        answer.push_back(MinDistance);
    }

    return answer;
}
