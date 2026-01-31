#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> NameToIndex;
    vector<string> IndexToName;
    IndexToName.push_back("");
    for (int i = 1; i <= n; ++i)
    {
        string Name;
        cin >> Name;
        NameToIndex.insert({ Name, i });
		IndexToName.push_back(Name);
    }

    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        if (isdigit(str[0]))
        {
			cout << IndexToName[stoi(str)] << "\n";
        }
        else
        {
            cout << NameToIndex[str] << "\n";
        }
    }
}