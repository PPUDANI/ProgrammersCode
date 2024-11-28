#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    unordered_map<string, int> NumOfType;
    int answer = 1;
    for(vector<string> cloth : clothes)
    {
        ++NumOfType[cloth[1]];
    }
    
    for(auto Type : NumOfType)
    {
        answer *= (Type.second + 1);
    }
    
    return answer - 1;
}