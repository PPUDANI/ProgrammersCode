#include <string>
#include <sstream>

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

using namespace std;

// 각 사람들마다 선물을 준 정보를 담는 클래스
class GiftInfo
{
public:
    GiftInfo()
    {

    }

    // 주기
    void GiveGift(const string& _Name)
    {
        GiveFriends.insert(_Name);
    }

    // 받기
    void ReceiveGift(const string& _Name)
    {
        ++NumOfReceived;
    }

    // 특정 친구에게 선물을 준 횟수
    int GetCountOfGaveToFriend(const string& _Name)
    {
        int Count = static_cast<int>(GiveFriends.count(_Name));
        return Count;
    }

    // 이번달 선물 지수
    int GetGiftPoint()
    {
        int Point = static_cast<int>(GiveFriends.size() - NumOfReceived);
        return Point;
    }

private:
    // 내가 선물을 준 사람만 기억하면 됨.
    // Give는 multiset을 사용.
    // 받는 횟수는 int를 사용.
    unordered_multiset<string> GiveFriends;
    int NumOfReceived;
};


int solution(vector<string> friends, vector<string> gifts) 
{
    int FriendNum = static_cast<int>(friends.size());

    // 사람들의 이름과 정보를 담을 Map 선언
    unordered_map<string, GiftInfo> FriendMap;

    // FriendMap 초기화 및 객체 생성
    for (const string& str : friends)
    {
        FriendMap[str] = GiftInfo();
    }

    // gift의 데이터로 사람 별로 선물을 주고받은 횟수 계산
    for (const string& str : gifts)
    {
        stringstream ss(str);
        string Giver, Receiver;
        ss >> Giver >> Receiver;

        FriendMap[Giver].GiveGift(Receiver);
        FriendMap[Receiver].ReceiveGift(Giver);
    }

    // 조건에 따라 다음달에 받을 선물 개수 계산
    vector<int> NextMonthGift(FriendNum, 0);

    for (int Left = 0; Left < FriendNum; ++Left)
    {
        const string& LeftName = friends[Left];
        for (int Right = Left + 1; Right < FriendNum; ++Right)
        {
            const string& RightName = friends[Right];

            int NumOfLeftGift = FriendMap[LeftName].GetCountOfGaveToFriend(RightName);
            int NumOfRightGift = FriendMap[RightName].GetCountOfGaveToFriend(LeftName);

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
                int LeftPoint = FriendMap[LeftName].GetGiftPoint();
                int RightPoint = FriendMap[RightName].GetGiftPoint();

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

    // NextMonthGift에서 가장 큰 수 찾기
    int answer = *(std::max_element(NextMonthGift.begin(), NextMonthGift.end()));
    return answer;
}