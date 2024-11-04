#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    
    sort(num_list.begin(), num_list.end(), [](int Left, int Right)
        {
            return Left < Right;
        });
    
    vector<int> answer(num_list.begin(), num_list.begin() + 5);
    
    return answer;
}