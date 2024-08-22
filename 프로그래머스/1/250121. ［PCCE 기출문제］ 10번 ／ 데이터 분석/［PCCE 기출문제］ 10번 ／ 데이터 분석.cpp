#include <string>
#include <vector>
#include <algorithm>

int SortDataIndex = -1;

// sort_by 기준으로 정렬
bool compare(std::vector<int>& Left, std::vector<int>& Right)
{
    return Left[SortDataIndex] < Right[SortDataIndex];
}

// ext, sort_by기준을 index로 반환해주는 함수
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

    // ext와 sort_by를 index로 받아옴
    int CheckDataIndex = GetDataIndex(ext[0]);
    SortDataIndex = GetDataIndex(sort_by[0]);

    for (std::vector<int> Data : data)
    {
        // 받아온 index로 데이터 선별
        if (Data[CheckDataIndex] < val_ext)
        {
            answer.push_back(Data);
        }
    }

    // 정렬
    std::sort(answer.begin(), answer.end(), compare);
  
    return answer;
}
