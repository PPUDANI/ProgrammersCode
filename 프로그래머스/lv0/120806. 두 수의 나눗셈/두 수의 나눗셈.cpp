#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    float val = (float)num1 / (float)num2 ;
    int answer = val * 1000;
    return answer;
}