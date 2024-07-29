#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int VectorNumber = static_cast<int>(sizes.size());

    int Minimum = 0;
    int Maximum = 0;

    for (int i = 0; i < VectorNumber; ++i)
    {
        int CurrentMinimum = sizes[i][0] < sizes[i][1] ? sizes[i][0] : sizes[i][1];
        int CurrentMaximum = sizes[i][0] < sizes[i][1] ? sizes[i][1] : sizes[i][0];

        if (Minimum < CurrentMinimum)
        {
            Minimum = CurrentMinimum;
        }

        if (Maximum < CurrentMaximum)
        {
            Maximum = CurrentMaximum;
        }
    }
    answer = Minimum * Maximum;
    return answer;
}