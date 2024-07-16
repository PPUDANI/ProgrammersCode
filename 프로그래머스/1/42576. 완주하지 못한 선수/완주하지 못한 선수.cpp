
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_multiset<string> Players;

    for (string Player : participant)
    {
        Players.insert(Player);
    }

    for (string Goal : completion)
    {
        auto a = Players.find(Goal);
        Players.erase(a);
    }

    string answer = Players.begin()->data();
    return answer;
}