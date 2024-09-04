#include <vector>

using namespace std;

class Player
{
public:
    Player(int _Health)  : CurHealth(_Health), MaxHealth(_Health) {}

    void Heal(int _Value)
    {
        CurHealth += _Value;
        if (CurHealth > MaxHealth)
        {
            CurHealth = MaxHealth;
        }
    }

    void TakeDamage(int _Value)
    {
        CurHealth -= _Value;
    }

    int GetCurHealth() const
    {
        return CurHealth;
    }

private:
    int CurHealth;
    int MaxHealth;
};

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int TotalHealingTime = bandage[0];
    int HealPerSec = bandage[1];
    int BonusHeal = bandage[2];

    Player Mr_Undead = Player(health);

    int CurTime = 0;
    int BonusTime = 0;
    int NumOfAttack = static_cast<int>(attacks.size());

    int AttackIndex = 0;
    while(AttackIndex < NumOfAttack)
    {
        ++BonusTime;
        ++CurTime;
        if(attacks[AttackIndex][0] != CurTime)
        {
            Mr_Undead.Heal(HealPerSec);
            if (TotalHealingTime == BonusTime)
            {
                Mr_Undead.Heal(BonusHeal);
                BonusTime = 0;
            }
        }
        else
        {
            BonusTime = 0;
            Mr_Undead.TakeDamage(attacks[AttackIndex][1]);

            if (Mr_Undead.GetCurHealth() <= 0)
            {
                return -1;
            }
            ++AttackIndex;
        }
    }

    int answer = Mr_Undead.GetCurHealth();
    return answer;
}
