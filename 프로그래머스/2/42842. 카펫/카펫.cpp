#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    // All - Yellow = Brown;
    // x.y - Yx.Yy = Brown;
    // x.y - (x - 2).(y - 2) = Brown;
    // x.y - (x.y - 2x - 2y + 4) = Brown;
    // x.y - x.y + 2x + 2y - 4 = Brown;
    // 2x + 2y - 4 = Brown;
    
    // 즉 아래 식으로 x와 y의 합을 구할 수 있음.
    // x + y = (Brown / 2) + 2;
    
    int WidthPlusHeight = (brown / 2) + 2;
    int AllTile = brown + yellow;
    
    // "x * y = All" 이 성립하는 {x, y} 조합을 찾음.
    for(int i = 1; i < WidthPlusHeight; ++i)
    {
        int CheckTile = (WidthPlusHeight - i) * i;
        if(AllTile == CheckTile)
        {
            return {WidthPlusHeight - i, i};
        }
    }
}