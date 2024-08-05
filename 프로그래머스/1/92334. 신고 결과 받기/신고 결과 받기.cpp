#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

std::vector<int> solution(std::vector<string> id_list, std::vector<string> report, int k) 
{
    std::vector<int> answer(id_list.size(), 0);
    std::unordered_map<std::string, int> Reports;

    std::unordered_map<std::string, std::set<string>> Respondents;
    int IdNumber = static_cast<int>(id_list.size());

    for (int i = 0; i < IdNumber; ++i)
    {
        Respondents[id_list[i]] = std::set<std::string>();
        Reports[id_list[i]] = i;
    }

    for (std::string str : report)
    {
        int index = static_cast<int>(str.find(" "));
        std::string Reporter = str.substr(0, index);
        std::string Respondent = str.substr(index + 1);

        Respondents[Respondent].insert(Reporter);
    }

    for (int i = 0; i < IdNumber; ++i)
    {
        std::string CurReporter = id_list[i];
        int ReportNumber = static_cast<int>(Respondents[CurReporter].size());
        if (k <= ReportNumber)
        {
            for (std::string Respondent : Respondents[CurReporter])
            {
                ++answer[Reports[Respondent]];
            }
        }
    }
    return answer;
}  