#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> WishCheck;
    int WishListSize = want.size();
    for(int i = 0; i < WishListSize; ++i)
    {
        WishCheck[want[i]] = number[i];
    }
    
    int Loop = discount.size() - 10;
    for(int i = 0; i <= Loop; ++i)
    {
        auto CurCheck = WishCheck;
        bool AbleAllDiscount = true;
        for(int j = 0; j < 10; ++j)
        {
            const string& CurStr = discount[j + i];
            if(CurCheck.find(CurStr) == CurCheck.end())
            {
                i += j;
                AbleAllDiscount = false;
                break;
            }
            
            if(CurCheck[CurStr] == 0)
            {
                AbleAllDiscount = false;
                break;
            }
            --CurCheck[CurStr];
        }
        
        if(AbleAllDiscount == true)
        {
            ++answer;
        }
    }
    
    return answer;
}