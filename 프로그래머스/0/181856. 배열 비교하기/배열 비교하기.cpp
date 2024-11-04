#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) 
{
    int answer = 0;
    int Arr1Size = int(arr1.size());
    int Arr2Size = int(arr2.size());
    
    if(Arr1Size > Arr2Size)
    {
        return 1;
    }
    else if(Arr1Size < Arr2Size)
    {
        return -1;
    }
    else
    {
        int Arr1Sum = 0;
        int Arr2Sum = 0;
        for(int i = 0; i < Arr1Size; ++i)
        {
            Arr1Sum += arr1[i];
            Arr2Sum += arr2[i];
        }
        if(Arr1Sum > Arr2Sum)
        {
            return 1;
        }
        else if(Arr1Sum < Arr2Sum)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    
    return answer;
}