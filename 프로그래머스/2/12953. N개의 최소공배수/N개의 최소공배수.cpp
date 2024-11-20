#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define Min_Val 100
int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    
    int Max = arr.back();
    int ArrSize = int(arr.size());
    
    int CurMax = Max;
    while(true)
    {
        bool IsMultiple = true;
        for(int i = 0; i < ArrSize; ++i)
        {
            if(CurMax % arr[i] != 0)
            {
                IsMultiple = false;
                break;
            }
        }
        
        if(IsMultiple == true)
        {
            return CurMax;
        }
        else
        {
            CurMax += Max;
        }
    }
}