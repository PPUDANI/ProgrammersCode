#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) 
{
    int ArrSize = int(arr.size());
    if(ArrSize % 2 == 0)
    {
        for(int i = 1; i < ArrSize; i += 2)
        {
            arr[i] += n;
        }
    }
    else
    {
        for(int i = 0; i < ArrSize; i += 2)
        {
            arr[i] += n;
        }
    }
    
    
    return arr;
}