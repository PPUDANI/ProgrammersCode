#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) 
{
    sort(phone_book.begin(), phone_book.end());
    int NumOfNumber = int(phone_book.size());
    for(int i = 0 ; i < NumOfNumber -1; ++i)
    {
        if(phone_book[i + 1].find(phone_book[i]) == 0)
        {
            return false;
        }
    }
    return true;
}