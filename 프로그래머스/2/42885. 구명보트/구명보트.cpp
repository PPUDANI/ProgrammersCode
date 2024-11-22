#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit)
{
    vector<int> ASC_People(people.begin(), people.begin());
    sort(people.rbegin(), people.rend());
    
    
    int DESC_index = 0;
    int ASC_index = int(people.size()) - 1;
    
    int answer = 0;
    while(true)
    {
        if(people[DESC_index] + people[ASC_index] <= limit)
        {
            --ASC_index;
            ++DESC_index;
        }
        else
        {
            ++DESC_index;
        }
        ++answer;
        
        if(DESC_index == ASC_index)
        {
            ++answer;
            break;
        }
        
        if(DESC_index > ASC_index)
        {
            break;
        }
    }
    
    return answer;
}