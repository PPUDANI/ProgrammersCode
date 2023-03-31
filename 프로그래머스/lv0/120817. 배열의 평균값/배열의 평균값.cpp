#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    
    float answer = 0.0f;
    int count = 0;
    for(auto i : numbers)
    {
        count++;
        answer += i;
    }
    
    
    return answer / (float)count;
}