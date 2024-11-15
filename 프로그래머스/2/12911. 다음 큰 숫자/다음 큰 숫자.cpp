#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {

    bitset<32> bs = n;
    int TrueCount = bs.count();
    
    while(true)
    {
        bs = ++n;
        if(TrueCount == bs.count())
        {
            break;
        }
    }
    
    return n;
}