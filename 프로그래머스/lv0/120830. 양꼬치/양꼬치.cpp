#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int SheepPrice = n * 12000;
    int DrinkPrice = (k - (n/10)) * 2000;
    
    answer = SheepPrice + DrinkPrice;
    return answer;
}