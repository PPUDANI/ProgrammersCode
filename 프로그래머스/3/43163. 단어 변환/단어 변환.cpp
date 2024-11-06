#include <string>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;


int solution(string begin, string target, vector<string> words)
{
    int NumOfWord = int(words.size());
    int WordLength = int(begin.length());

    bool CanChange = false;
    for (int i = 0; i < NumOfWord; ++i)
    {
        if (words[i] == target)
        {
            CanChange = true;
        }
    }

    if (CanChange == false)
    {
        return 0;
    }

    words.push_back(begin);
    ++NumOfWord;

    // pair<pair<index, ChangeCount>, VisitCheck>
    queue<pair<pair<int, int>, vector<bool>>, list<pair<pair<int, int>, vector<bool>>>> BFS;
    vector<bool> VisitCheck(NumOfWord, false);
    VisitCheck[NumOfWord - 1] = true;
    BFS.push({ {NumOfWord - 1, 0}, VisitCheck });

    while (!BFS.empty())
    {
        int CurIndex = BFS.front().first.first;
        int CurCount = BFS.front().first.second;
        vector<bool> CurVisit = BFS.front().second;
        BFS.pop();

        if (target == words[CurIndex])
        {
            return CurCount;
        }

        for (int i = 0; i < NumOfWord; ++i)
        {
            if (CurVisit[i] == false)
            {
                // Same Word Check
                int SameWordCount = 0;
                for (int j = 0; j < WordLength; ++j)
                {
                    if (words[CurIndex][j] == words[i][j])
                    {
                        ++SameWordCount;
                    }
                }

                if (SameWordCount == WordLength - 1)
                {
                    CurVisit[i] = true;
                    BFS.push({ {i, CurCount + 1}, CurVisit });
                }
            }
        }
    }

    return 0;
}