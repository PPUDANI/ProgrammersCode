#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    if(cacheSize == 0)
    {
        return 5 * cities.size();
    }
    
    int answer = 0;

    for(string& str : cities)
    {
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    }
    
    vector<pair<int, string>> Cache(cacheSize);
    
    for(int i = 0 ; i < cacheSize; ++i)
    {
        Cache[i] = {cacheSize - i, "NONE"};
    }
    
    int ProcessNum = int(cities.size());
    for(int i = 0; i < ProcessNum; ++i)
    {
        int HitIndex = -1;
        for(int j = 0; j < cacheSize; ++j)
        {
            if(Cache[j].second == cities[i])
            {
                HitIndex = j;
                break;
            }
        }
        
        if(HitIndex != -1)
        {
            answer += 1;
            Cache[HitIndex].first = 0;
        }
        else //miss
        {
            answer += 5;
            int MaxTime = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>> PQ;
            
            for(int j = 0; j < cacheSize; ++j)
            {
                PQ.push({Cache[j].first, j});
            }
            
            int MaxIndex = PQ.top().second;
            
            Cache[MaxIndex] = {0, cities[i]};
        }
        
        for(int j = 0; j < cacheSize; ++j)
        {
            ++Cache[j].first;
        }
    }
    
    return answer;
}