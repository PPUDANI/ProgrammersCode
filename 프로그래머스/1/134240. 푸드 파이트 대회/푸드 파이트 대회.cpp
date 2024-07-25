#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food)
{
    std::string answer = "";

    std::vector<std::string> Foods(9, "");
    int NumberOfFoodTypes = static_cast<int>(food.size());

    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        int NumberOfFood = food[i] / 2;
        Foods[i].assign(NumberOfFood, i + '0');
    }

    for (int i = 0; i < NumberOfFoodTypes; ++i)
    {
        answer += Foods[i];
    }

    answer += '0';

    for (int i = NumberOfFoodTypes - 1; i >= 0; --i)
    {
        answer += Foods[i];
    }

    return answer;
}