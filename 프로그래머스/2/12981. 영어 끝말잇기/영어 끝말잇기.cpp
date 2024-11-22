#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    unordered_set<string> WordCheck;
    WordCheck.insert(words[0]);
        
    int NumOfWord = int(words.size());
    int NumOfGame = 1;
    
    bool RetireCheck = false;
    for(int i = 1; i < NumOfWord; ++i)
    {  
        if(words[i - 1].back() != words[i].front())
        {
            RetireCheck = true;
            break;
        }
        
        if(WordCheck.find(words[i]) == WordCheck.end())
        {
            WordCheck.insert(words[i]);
        }
        else
        {
            RetireCheck = true;
            break;
        }
        ++NumOfGame;
    }
    
    if(RetireCheck == false)
    {
        return {0, 0};
    }

    return { NumOfGame % n + 1, (NumOfGame / n) + 1};
}