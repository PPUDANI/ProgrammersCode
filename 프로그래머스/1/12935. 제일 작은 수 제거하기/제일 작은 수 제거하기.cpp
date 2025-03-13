#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    auto MinIter = min_element(arr.begin(), arr.end());
    arr.erase(MinIter);
    if(arr.empty() == true)
    {
        arr.push_back(-1);
    }
    return arr;
}