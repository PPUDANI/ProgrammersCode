#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long DNum = num;
    while(DNum != 1)
    {
        if(DNum % 2 == 0)
        {
            DNum /= 2;
        }
        else
        {
            DNum = (DNum * 3) + 1;
        }
        
        ++answer;
    }
    
    if(answer >= 500)
    {
        answer = -1;
    }
    
    return answer;
}