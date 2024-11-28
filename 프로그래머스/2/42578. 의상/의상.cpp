#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) 
{
    map<string, int> NumOfType;
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