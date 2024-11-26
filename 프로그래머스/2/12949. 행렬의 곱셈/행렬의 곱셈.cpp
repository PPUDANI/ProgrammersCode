#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    int ResLow = arr1.size();
    int ResColumn = arr2[0].size();
    int SameLength = arr1[0].size();
    
    vector<vector<int>> answer(ResLow, vector<int>(ResColumn, 0));
    
    for(int i = 0; i < ResLow; ++i)
    {
        for(int j = 0; j < ResColumn; ++j)
        {
            int CurMultiply = 0;
            for(int k = 0; k < SameLength; ++k)
            {
                CurMultiply += arr1[i][k] * arr2[k][j];
            }
            answer[i][j] = CurMultiply;
        }
    }
    return answer;
}