#include <vector>
#include <iostream>

std::string solution(std::string X, std::string Y) {
    std::string answer = "";

    int XLength = static_cast<int>(X.length());
    int YLength = static_cast<int>(Y.length());

    std::vector<int> XNum(10, 0);
    std::vector<int> YNum(10, 0);

    for (int i = 0 ; i < XLength; ++i)
    {
        int Num = static_cast<int>(X[i]) - 48;
        ++XNum[Num];
    }

    for (int i = 0; i < YLength; ++i)
    {
        int Num = static_cast<int>(Y[i]) - 48;
        ++YNum[Num];
    }

    for (int i = 9; i >= 0 ; --i)
    {
        while (XNum[i] > 0 && YNum[i] > 0)
        {
            answer.push_back(i + 48);
         
            --XNum[i];
            --YNum[i];
        }
    }

    if (answer.length() == 0)
    {
        return "-1";
    }
    else if (answer[0] == '0')
    {
        return "0";
    }

    return answer;
}
