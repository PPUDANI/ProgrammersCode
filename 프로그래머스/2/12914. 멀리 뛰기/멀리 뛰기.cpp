#include <vector>
using namespace std;

#define NO_DATA -1

int Fibonachi(int n, vector<int>& DP)
{
    if(DP[n] != NO_DATA)
    {
        return DP[n];
    }
    
    DP[n] = (Fibonachi(n - 1, DP) + Fibonachi(n - 2, DP) )% 1234567;
    return DP[n] ;
}

long long solution(int n)
{
    vector<int> DP(n + 1, NO_DATA);
    DP[0] = 1;
    DP[1] = 1;
    int answer = Fibonachi(n, DP);
    return answer;
}

