#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
static int PrevNumber = 0;

static std::vector<int> DivisorVec;

for (int CurNum = PrevNumber + 1; CurNum <= number; ++CurNum) // 모든 기사 순회
{
    int DivNum = CurNum; // 나눠지는 수
    int CurDiv = 2; // 나누는 수
    int DivCount = 0; // CurDiv로 나눠진 횟수
    int Divisor = 1; // 약수 결과값

    // 소인수분해
    while(1)
    {
        if (DivNum % CurDiv == 0)
        {
            ++DivCount;
            DivNum /= CurDiv;
        }
        else
        {
            if (DivCount != 0) // CurDiv로 나눠진 경우
            {
                Divisor *= (1 + DivCount);
                DivCount = 0;
            }

            if (CurDiv > DivNum) // CurDiv가 DivNum보다 큰 경우
            {
                DivisorVec.push_back(Divisor);
                break;
            }

            ++CurDiv;
        }
    }

    
}

for (int i = 0; i < number; ++i)
{
    if (DivisorVec[i] > limit)
    {
        answer += power;
    }
    else
    {
        answer += DivisorVec[i];
    }
}
PrevNumber = number;
return answer;
}