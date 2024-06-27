#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    std::vector<int> answer;
    for (int i = 0; i < commands.size(); ++i)
    {
        std::vector<int> Vec;
        int Start = commands[i][0] - 1;
        int End = commands[i][1] - 1;
        int K = commands[i][2] - 1;
        for (int j = Start; j <= End; ++j)
        {   
            Vec.push_back(array[j]);
        }
        
        std::sort(Vec.begin(), Vec.end());
        answer.push_back(Vec[K]);
    }

    return answer;
}