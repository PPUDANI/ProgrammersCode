#include <string>
#include <vector>

using namespace std;

int solution(string num_str) {
    int answer = 0;
    
    int Count = 0;
    for(const char c : num_str)
    {
        answer += c;
        ++Count;
    }
    answer -= '0' * Count;
    
    return answer;
}