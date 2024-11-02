#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    for(int& Element : numbers)
    {
        Element *= 2;
    }
    
    return numbers;
}