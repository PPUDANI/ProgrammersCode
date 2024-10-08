#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
class ParkingCalculator
{
public:
    ParkingCalculator(int _DefaultTime, int _DefaultRate, int _UnitTime, int _UnitRate)
        : DefaultTime(_DefaultTime), DefaultCharge(_DefaultRate), UnitTime(_UnitTime), UnitCharge(_UnitRate)
    {
    }

private:
    struct TimeInfo
    {
        int TimeToIn= 0; // 들어온 시간
        int AccumulatedTime = 0; // 주차 누적 시간
    };

    map<int, TimeInfo> AccessRecord;
    vector<int> ChargeRecord;

    int DefaultTime; // 기본 시간
    int DefaultCharge; // 기본 요금
    int UnitTime; // 단위 시간
    int UnitCharge; // 단위 시간

public:
    void RecordProcessing(int _Minute, int _VehicleNum, const string& _Process)
    {
        if (_Process == "IN")
        {
            CheckIn(_VehicleNum, _Minute);
        }
        else if (_Process == "OUT")
        {
            CheckOut(_VehicleNum, _Minute);
        }
    }

    void CheckIn(int _VehicleNum, int _Minute)
    {
        AccessRecord[_VehicleNum].TimeToIn = _Minute;
    }

    void CheckOut(int _VehicleNum, int _Minute)
    {
        int ParkingTime = _Minute - AccessRecord[_VehicleNum].TimeToIn; // 주차한 시간 계산
        AccessRecord[_VehicleNum].AccumulatedTime += ParkingTime; // 주차 시간 누적
        AccessRecord[_VehicleNum].TimeToIn = -1; // 들어온 시간이 -1이면 CheckOut된 것으로 구분
    }

    void ChargeSettlement()
    {
        CheckOutRemainingVehicles(); // 남은 차량 CheckOut 시키기
        for (const pair<int, TimeInfo>& Record : AccessRecord)
        {
            CalculationOfCharge(Record.second.AccumulatedTime); // 요금 정산
        }
    }

    const vector<int>& GetChargeRecord()
    {
        return ChargeRecord;
    }

private:
    void CheckOutRemainingVehicles()
    {
        for (const pair<int, TimeInfo>& Record : AccessRecord)
        {
            if (Record.second.TimeToIn != -1)
            {
                CheckOut(Record.first, 1439); // 23:59 CheckOut으로 시간 누적
            }
        }
    }

    void CalculationOfCharge(int _ParkingTime)
    {
        int Charge = DefaultCharge; // 기본 요금
        if (DefaultTime < _ParkingTime)
        {
            int OverTime = ceil(float(_ParkingTime - DefaultTime) / UnitTime); // 추가 시간
            Charge += OverTime * UnitCharge; // 추가 요금 계산
        }

        ChargeRecord.push_back(Charge);
        return;
    }
};

vector<int> solution(vector<int> fees, vector<string> records) 
{
    ParkingCalculator PC(fees[0], fees[1], fees[2], fees[3]);

    // Record 처리
    for (const string& Record : records)
    {
        stringstream ss(Record);
        string Time, Process;
        int VehicleNum;

        ss >> Time >> VehicleNum >> Process;

        int Hour = stoi(Time.substr(0, 2));
        int Minute = stoi(Time.substr(3, 2));
        Minute += Hour * 60;
        
        PC.RecordProcessing(Minute, VehicleNum, Process);
    }

    PC.ChargeSettlement(); // 최종 요금 정산
    return PC.GetChargeRecord();
}