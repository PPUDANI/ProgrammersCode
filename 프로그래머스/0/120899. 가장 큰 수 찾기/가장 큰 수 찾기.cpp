#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(vector<int> array) 
{
    vector<int> answer;
    
    vector<int>::iterator MaxIndex = max_element(array.begin(), array.end());
    
    answer.push_back(*MaxIndex);
    answer.push_back(int(MaxIndex - array.begin())); 
    
    return answer;
}