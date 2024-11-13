#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

bool IsPrime(int Num)
{
    if(Num == 1) return false;
    if(Num == 2) return true;
    if(Num % 2 == 0) return false;
    
    for(int i = 3; i * i <= Num; i += 2)
    {
        if(Num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) 
{
    set<int> Permutations;
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.length(); ++i) {
            int num = stoi(numbers.substr(0, i));
            Permutations.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int answer = 0;
    
    for (int Permutation : Permutations)
    {
        if (IsPrime(Permutation))
        {
            ++answer;
        }
    }
                
    return answer;
}