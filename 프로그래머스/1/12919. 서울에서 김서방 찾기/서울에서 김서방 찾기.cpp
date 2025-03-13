#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul)
{
    int Index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    return "김서방은 " + to_string(Index) + "에 있다";
}