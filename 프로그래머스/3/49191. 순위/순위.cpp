#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) 
{
    vector<vector<int>> Graph(n + 1, vector<int>(n + 1, 0));
    
    for (vector<int> Res : results)
    {
        int Winner = Res[0];
        int Loser = Res[1];
        Graph[Winner][Loser] = 1;
        Graph[Loser][Winner] = -1;
    }
    for (int i = 0; i < 2; ++i)
    {
        for (int Winner = 1; Winner <= n; ++Winner)
        {
            for (int Loser = 1; Loser <= n; ++Loser)
            {
                if (Graph[Winner][Loser] == 1)
                {
                    for (int MoreLoser = 1; MoreLoser <= n; ++MoreLoser)
                    {
                        if (Graph[Loser][MoreLoser] == 1)
                        {
                            Graph[Winner][MoreLoser] = 1;
                            Graph[MoreLoser][Winner] = -1;
                        }
                    }
                }
            }
        }
    }
    

    int answer = 0;
    for (int i = 1; i <= n; ++i)
    {
        int UnableToRank = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i != j && Graph[i][j] != 0)
            {
                ++UnableToRank;
            }
        }

        if (UnableToRank == n - 1)
        {
            ++answer;
        }
    }

    return answer;
}