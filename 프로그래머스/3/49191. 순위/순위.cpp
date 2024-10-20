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
    for (int m = 0; m < 2; ++m)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (Graph[i][j] == 1)
                {
                    for (int k = 1; k <= n; ++k)
                    {
                        if (Graph[j][k] == 1)
                        {
                            Graph[i][k] = 1;
                            Graph[k][i] = -1;
                        }
                    }
                }
            }
        }

    }

    int answer = 0;
    int UnableToRank = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (Graph[i][j] != 0)
            {
                ++UnableToRank;
            }
        }

        if (UnableToRank == n - 1)
        {
            ++answer;
        }

        UnableToRank = 0;
    }

    return answer;
}
