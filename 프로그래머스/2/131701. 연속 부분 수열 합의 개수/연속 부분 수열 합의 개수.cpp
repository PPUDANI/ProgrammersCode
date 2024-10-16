#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{
    int ElementsNum = static_cast<int>(elements.size());

    set<int> Nums;
    vector<int> Num(ElementsNum, 0);

    for (int i = 0; i < ElementsNum - 1; ++i)
    {
        for (int j = 0; j < ElementsNum; ++j)
        {
            int NextNum = (j + i) % ElementsNum;
            Num[j] += elements[NextNum];
        }

        Nums.insert(Num.begin(), Num.end());
    }

    int answer = Nums.size() + 1;
    return answer;
}
