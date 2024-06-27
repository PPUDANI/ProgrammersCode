#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    std::vector<int> answer;
    for (int i = 0; i < commands.size(); ++i)
    {
        std::vector<int> Vec;
        for (int j = commands[i][0] - 1; j <= commands[i][1] - 1; ++j)
        {   
            Vec.push_back(array[j]);
        }
        
        std::sort(Vec.begin(), Vec.end());
        answer.push_back(Vec[commands[i][2] - 1]);
    }

    return answer;
}