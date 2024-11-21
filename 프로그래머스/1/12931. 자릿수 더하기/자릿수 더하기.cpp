#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int Div = 10;
    while(true)
    {
        int CurNum = n % Div;
        n /= Div;
        cout << CurNum << endl;
        answer += CurNum;
        if(n == 0)
        {
            break;
        }
    }

    return answer;
}