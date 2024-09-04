#include <string>
#include <sstream>

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class GiftInfo
{
public:
    GiftInfo()
    {

    }

    void ReceiveGift(const string& _Name)
    {
        ReceiveFriends.insert(_Name);
    }

    void GiveGift(const string& _Name)
    {
        GiveFriends.insert(_Name);
    }

    int GetGiveCountToFriend(const string& _Name)
    {
        int Count = static_cast<int>(GiveFriends.count(_Name));
        return Count;
    }

    int GetPoint()
    {
        int Point = static_cast<int>(GiveFriends.size() - ReceiveFriends.size());
        return Point;
    }
private:

    unordered_multiset<string> GiveFriends;
    unordered_multiset<string> ReceiveFriends;
};

int solution(vector<string> friends, vector<string> gifts) 
{
    int FriendNum = static_cast<int>(friends.size());

    unordered_map<string, GiftInfo> FriendMap;

    for (const string& str : friends)
    {
        FriendMap[str] = GiftInfo();
    }

    for (const string& str : gifts)
    {
        stringstream ss(str);
        string Giver, Receiver;
        ss >> Giver >> Receiver;

        FriendMap[Giver].GiveGift(Receiver);
        FriendMap[Receiver].ReceiveGift(Giver);
    }


    vector<int> NextMonthGift(FriendNum, 0);

    for (int Left = 0; Left < FriendNum; ++Left)
    {
        const string& LeftName = friends[Left];
        for (int Right = Left + 1; Right < FriendNum; ++Right)
        {
            const string& RightName = friends[Right];

            int NumOfLeftGift = FriendMap[LeftName].GetGiveCountToFriend(RightName);
            int NumOfRightGift = FriendMap[RightName].GetGiveCountToFriend(LeftName);

            if (NumOfLeftGift > NumOfRightGift)
            {
                ++NextMonthGift[Left];
            }
            else if (NumOfLeftGift < NumOfRightGift)
            {
                ++NextMonthGift[Right];
            }
            else 
            {
                int LeftPoint = FriendMap[LeftName].GetPoint();
                int RightPoint = FriendMap[RightName].GetPoint();

                if (LeftPoint > RightPoint)
                {
                    ++NextMonthGift[Left];
                }
                else if (LeftPoint < RightPoint)
                {
                    ++NextMonthGift[Right];
                }
            }
        }
    }

    int answer = 0;
    for(int i : NextMonthGift)
    {
        if (answer < i)
        {
            answer = i;
        }
    }

    return answer;
}
