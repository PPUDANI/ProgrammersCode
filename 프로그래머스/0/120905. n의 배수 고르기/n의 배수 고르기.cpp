#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    
    for(int Num : numlist)
    {
        if(Num % n == 0)
        {
            answer.push_back(Num);
        }
    }
    return answer;
}