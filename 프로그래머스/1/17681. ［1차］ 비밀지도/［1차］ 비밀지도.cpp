#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer(n, "");

    for (int i = 0; i < n; ++i)
    {
        bitset<16> Left(arr1[i]);
        bitset<16> Right(arr2[i]);

        for (int j = n - 1; j >= 0; --j)
        {
            char AddChar = ' ';
            if (Left[j] || Right[j] == true)
            {
                AddChar = '#';
            }
            answer[i] += AddChar;
        }
    }

    return answer;
}