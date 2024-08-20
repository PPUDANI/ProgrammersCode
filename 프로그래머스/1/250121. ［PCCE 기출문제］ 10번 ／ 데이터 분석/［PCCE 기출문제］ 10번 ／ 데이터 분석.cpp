#include <string>
#include <vector>
#include <algorithm>

int CheckDataIndex = -1;
int SortDataIndex = -1;

bool compare(std::vector<int>& Left, std::vector<int>& Right)
{
    return Left[SortDataIndex] < Right[SortDataIndex];
}

int GetDataIndex(const char _ext)
{
    switch (_ext)
    {
    case 'c': return  0;
    case 'd': return  1;
    case 'm': return  2;
    case 'r': return  3;

    default: 
        return -1;
    }
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> data, std::string ext, int val_ext, std::string sort_by)
{
    std::vector<std::vector<int>> answer;
    answer.reserve(data.size());

    CheckDataIndex = GetDataIndex(ext[0]);
    SortDataIndex = GetDataIndex(sort_by[0]);

    for (std::vector<int> Data : data)
    {
        if (Data[CheckDataIndex] < val_ext)
        {
            answer.push_back(std::vector<int>{ Data[0], Data[1], Data[2], Data[3] });
        }
    }
    std::sort(answer.begin(), answer.end(), compare);
  
    return answer;
}