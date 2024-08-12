#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    
    for(int i : numbers)
    {
        answer += i;
    }
    
    return 44 - answer;
}