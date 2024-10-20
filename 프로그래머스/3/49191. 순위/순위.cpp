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


    for (int k = 1; k <= n; ++k) 
    {
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                if (Graph[i][k] == 1 && Graph[k][j] == 1) 
                {
                    Graph[i][j] = 1;
                    Graph[j][i] = -1; // j는 i에게 진다
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
            if (Graph[i][j] != 0)
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

