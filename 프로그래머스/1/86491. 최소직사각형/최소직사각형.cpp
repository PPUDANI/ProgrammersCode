#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int NumOfValue = static_cast<int>(sizes.size());
    int MinSize = 0;
    int MaxSize = 0;

    for (int i = 0; i < NumOfValue; ++i)
    {
        int CurMin = std::min(sizes[i][0], sizes[i][1]);
        int CurMax = std::max(sizes[i][0], sizes[i][1]);

        if (MinSize < CurMin)
        {
            MinSize = CurMin;
        }

        if (MaxSize < CurMax)
        {
            MaxSize = CurMax;
        }
    }

    return MinSize * MaxSize;
}