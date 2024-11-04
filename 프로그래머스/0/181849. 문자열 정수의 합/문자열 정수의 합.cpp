#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    for(const char c : num_str)
    {
        answer += c;
    }
    answer -= int(num_str.length()) * '0';
    
    return answer;
}