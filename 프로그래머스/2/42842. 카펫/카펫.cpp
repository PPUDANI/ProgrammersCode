#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    // All - Yellow = Brown;
    // Ax * Ay - Yx * Yy = Brown;
    // Ax * Ay - (Ax - 2) * (Ay - 2) = Brown;
    // Ax * Ay - (Ax * Ay - 2Ax - 2Ay + 4) = Brown;
    // Ax * Ay - Ax * Ay + 2Ax + 2Ay - 4 = Brown;
    // 2Ax + 2Ay - 4 = Brown;
    // 
    // Ax * Ay = All
    // Ax + Ay = (Brown / 2) + 2;

    vector<int> answer(2, 0);
    int WidthPlusHeight = (brown / 2) + 2;
    int AllTile = brown + yellow;
    
    for(int i = 1; i < WidthPlusHeight; ++i)
    {
        int CheckTile = (WidthPlusHeight - i) * i;
        if(AllTile == CheckTile)
        {
            answer[0] = WidthPlusHeight - i;
            answer[1] = i;
        }
    }
    
    if(answer[0] <= answer[1])
    {
        swap(answer[0], answer[1]);
    }
    
    return answer;
}