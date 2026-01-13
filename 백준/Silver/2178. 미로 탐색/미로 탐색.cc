#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int x;
    int y;
    
    Node operator +(const Node& _Node)
    {
        Node Res;
        Res.x = this->x + _Node.x;
        Res.y = this->y + _Node.y;
        return Res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Map(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= M; ++j)
        {
            Map[i][j] = str[j - 1] - '0';
        }
    }
    
    vector<Node> Dir = 
    {
    {-1, 0}, // Left
    {1, 0}, // Right
    {0, 1}, // Up
    {0, -1} // Down
    };
    
    // 현재 위치를 저장해야하고
    // 방문 저장.
    queue<pair<Node, int>> Q;
    vector<vector<bool>> Visit(N + 1, vector<bool>(M + 1, false));
    Q.push({{1, 1}, 1});
    Visit[1][1] = true;
    
    while (!Q.empty())
    {
        Node CurNode = Q.front().first;
        int CurCount = Q.front().second;
        Q.pop();
        
        if (CurNode.x == M && CurNode.y == N)
        {
            cout << CurCount << endl;
            return 0;
        }
        
        for (int i = 0; i < Dir.size(); ++i)
        {
            Node Next = Dir[i] + CurNode;
            if (Next.y > N || Next.y <= 0 || Next.x > M || Next.x <= 0 || Map[Next.y][Next.x] == 0)
            {
                continue;
            }
            
            if (Visit[Next.y][Next.x] == false)
            {
                Visit[Next.y][Next.x] = true;
                Q.push({Next, CurCount + 1});
            }
        }
    }
}