#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int answer = 0;
    stack<int, vector<int>> Stack;
    
    int boardY = board.size();
    for(int i : moves)
    {
        for(int j = 0; j < boardY; ++j)
        {
            int CurCheck = board[j][i - 1];
            if(CurCheck != 0)
            {
                board[j][i - 1] = 0;
                if(!Stack.empty() && CurCheck == Stack.top())
                {
                    Stack.pop();
                    answer += 2;
                }
                else
                {
                    Stack.push(CurCheck);
                }
                
                break;
            }
        }
    }
    
    return answer;
}