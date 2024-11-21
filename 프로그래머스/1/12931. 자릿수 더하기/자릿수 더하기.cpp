using namespace std;
int solution(int n)
{
    int answer = 0;
    int Div = 10;
    while(n != 0)
    {
        int CurNum = n % Div;
        n /= Div;
        answer += CurNum;
    }
    return answer;
}