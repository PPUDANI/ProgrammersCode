#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    for(auto i : num_list)
    {
        if(i % 2 == 1)
        {
            answer[1]++;
        }
        else if(i % 2 == 0)
        {
            answer[0]++;
        }
    }
    return answer;
}