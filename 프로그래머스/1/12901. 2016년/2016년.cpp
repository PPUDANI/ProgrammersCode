#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
	std::vector<int> SumMonthError = { 0, 1, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5 };
	int NumberOfDays = --a * 30 + SumMonthError[a] + b;
	int CurDay = NumberOfDays % 7;

	switch (CurDay)
	{
	case 0: return "THU";
	case 1: return "FRI";
	case 2: return "SAT";
	case 3: return "SUN";
	case 4: return "MON";
	case 5: return "TUE";
	case 6: return "WED";
	default: return "";
	}
}
