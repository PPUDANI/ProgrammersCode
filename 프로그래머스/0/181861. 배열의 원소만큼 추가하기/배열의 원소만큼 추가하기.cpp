#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int Element : arr)
    {
        for(int i = 0; i < Element; ++i)
        {
            answer.push_back(Element);
        }
    }
    return answer;
}