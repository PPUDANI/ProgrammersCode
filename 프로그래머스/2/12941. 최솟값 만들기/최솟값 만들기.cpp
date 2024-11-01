#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ARRAY_A 0
#define ARRAY_B 1

bool comp(int Left, int Right)
{
    return Left > Right;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int ArrSize = static_cast<int>(A.size());
    
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    
    int MaxIndex_A = 0;
    int MaxIndex_B = 0;
    int MinIndex_A = ArrSize - 1;
    int MinIndex_B = ArrSize - 1;
    
    for(int i = 0; i < ArrSize; ++i)
    {
        int MaxA = A[MaxIndex_A] * B[MinIndex_B];
        int MaxB = B[MaxIndex_B] * A[MinIndex_A];
        
        if(MaxA < MaxB)
        {
            ++MaxIndex_A;
            --MinIndex_B;
            answer += MaxA;
        }
        else
        {
            ++MaxIndex_B;
            --MinIndex_A;
            answer += MaxB;
        }
    }
    
    return answer;
}