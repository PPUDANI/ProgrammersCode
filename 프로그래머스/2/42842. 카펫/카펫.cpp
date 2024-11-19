#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer(2, 0);
    int WidthPlusHeight = (brown / 2) + 2;
    int NumOfTile = brown + yellow;
    
    for(int i = 1; i < WidthPlusHeight; ++i)
    {
        int CurPair = (WidthPlusHeight - i) * i;
        if(NumOfTile == CurPair)
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