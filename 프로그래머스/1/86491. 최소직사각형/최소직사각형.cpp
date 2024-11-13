#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int Maxwidth = 0;
    int MaxHeight = 0;
    for(vector<int> Size: sizes)
    {
        int MaxIndex = 1;
        int MinIndex = 0;
        if(Size[0] > Size[1])
        {
            swap(MaxIndex, MinIndex);
        }
        
        Maxwidth = max(Maxwidth, Size[MaxIndex]);
        MaxHeight = max(MaxHeight, Size[MinIndex]);
    }
    int answer = Maxwidth * MaxHeight;
    return answer;
}