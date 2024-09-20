#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park)
{
    int ParkSizeY = static_cast<int>(park.size());
    int ParkSizeX = static_cast<int>(park[0].size());

    set<int, greater<int>> MatSizes(mats.begin(), mats.end());
    vector<vector<int>> N_Park(ParkSizeY, vector<int>(ParkSizeX, 0));

    int CurMaxSize = 0;
    for (int Y = 0; Y < ParkSizeY; ++Y)
    {
        for (int X = 0; X < ParkSizeX; ++X)
        {
            if (isalpha(park[Y][X][0]) == false)
            {
                int Left = X > 0 ? N_Park[Y][X - 1] : 0;
                int LeftUp = X > 0 && Y > 0 ? N_Park[Y - 1][X - 1] : 0;
                int Up = Y > 0 ? N_Park[Y - 1][X] : 0;

                int LayableSize = std::min({Left, Up, LeftUp}) + 1;
                N_Park[Y][X] = LayableSize;

                if (CurMaxSize < LayableSize)
                {
                    CurMaxSize = LayableSize;
                }
            }
        }
    }

    
    set<int>::iterator MatSizeIter = MatSizes.lower_bound(CurMaxSize);

    if (MatSizeIter != MatSizes.end())
    {
        return *MatSizeIter;
    }

    return -1;
}