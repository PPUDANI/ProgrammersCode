#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum class EHAND
{
    LEFT = 0,
    RIGHT,
    NONE
};

static std::unordered_map<int, std::vector<int>> DistanceFromCenter =
{
    { 0, { 0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1} },
    { 2, { 3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4 } },
    { 5, { 2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3 } },
    { 8, { 1, 3, 2, 3, 2, 1 ,2, 1, 0, 1, 2, 2 } }
};

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    EHAND HandCheck = hand[0] == 'r' ? EHAND::RIGHT : EHAND::LEFT;

    int CurLeftHandLocation = 10;
    int CurRightHandLocation = 11;

    EHAND CurMovedHand = EHAND::NONE;

    int DistanceOfLeft = 0;
    int DistanceOfRight = 0;

    for (int Num : numbers)
    {
        int NumCheck = Num % 3;

        if (Num == 0 || Num > 9)
        { 
            NumCheck = 2; 
        }

        switch (NumCheck)
        {
        case 0:
            CurMovedHand = EHAND::RIGHT;
            break;

        case 1:
            CurMovedHand = EHAND::LEFT;
            break;

        case 2:

            DistanceOfLeft = DistanceFromCenter[Num][CurLeftHandLocation];
            DistanceOfRight = DistanceFromCenter[Num][CurRightHandLocation];

			if (DistanceOfLeft == DistanceOfRight) 
            {
                CurMovedHand = HandCheck; 
            }
            else
            {
                CurMovedHand = DistanceOfLeft > DistanceOfRight ? EHAND::RIGHT : EHAND::LEFT;
            }

			break;

        default:
            break;
        }

        switch (CurMovedHand)
        {
        case EHAND::LEFT:
            CurLeftHandLocation = Num;
            answer += 'L';
            break;
        case EHAND::RIGHT:
            CurRightHandLocation = Num;
            answer += 'R';
            break;
        default:
            break;
        }
    }

    return answer;
}


int main()
{
    std::string res = solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right");
}