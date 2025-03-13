#include <string>
#include <vector>

using namespace std;

bool solution(int x) 
{
    string str = to_string(x);
    
    int Sum = -(str.length() * '0');
    for(const char c : str)
    {
        Sum += c;
    }
    
    if(x % Sum == 0)
    {
        return true;
    }
    
    return false;
}