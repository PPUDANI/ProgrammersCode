#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    double sum = 0.0;
    for(int a : arr)
    {
        sum += a;
    }
    
    answer = sum / arr.size();
    return answer;
}