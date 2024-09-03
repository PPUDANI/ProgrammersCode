#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> solution(vector<string> c, int n) 
{
    std::sort(c.begin(), c.end(), [&](const string& Left, const string& Right)
        {
            if (Left[n] == Right[n])
            {
                return Left < Right;
            }
            return Left[n] < Right[n];
        });

    return c;
}
