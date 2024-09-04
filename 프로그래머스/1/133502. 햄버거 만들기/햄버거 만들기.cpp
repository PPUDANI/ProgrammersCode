#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    int NumberOfIngredient = static_cast<int>(ingredient.size());

    stack<int> Burger;
    Burger.push(-1);

    for (int i = 0; i < NumberOfIngredient; ++i)
    {
        if (ingredient[i] == 1 && Burger.top() == 123)
        {
            Burger.pop();
            ++answer;
            continue;
        }

        if (ingredient[i] == 2 && Burger.top() == 1)
        {
            Burger.top() = 12;
            continue;
        }

        if (ingredient[i] == 3 && Burger.top() == 12)
        {
            Burger.top() = 123;
            continue;
        }

        Burger.push(ingredient[i]);
    }
    return answer;
}