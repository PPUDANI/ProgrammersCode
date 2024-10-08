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
        int TimeToIn= 0;
        int AccumulatedTime = 0;
    };

    map<int, TimeInfo> AccessRecord;
    vector<int> ChargeRecord;

    int DefaultTime;
    int DefaultCharge;
    int UnitTime;
    int UnitCharge;

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
        int ParkingTime = _Minute - AccessRecord[_VehicleNum].TimeToIn;
        AccessRecord[_VehicleNum].AccumulatedTime += ParkingTime;
        AccessRecord[_VehicleNum].TimeToIn = -1;
    }

    void ChargeSettlement()
    {
        CheckOutRemainingVehicles();
        for (const pair<int, TimeInfo>& Record : AccessRecord)
        {
            CalculationOfCharge(Record.second.AccumulatedTime);
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
                CheckOut(Record.first, 1439);
            }
        }
    }

    void CalculationOfCharge(int _ParkingTime)
    {
        int Charge = DefaultCharge;
        if (DefaultTime < _ParkingTime)
        {
            Charge += ceil(float(_ParkingTime - DefaultTime) / UnitTime) * UnitCharge;
        }

        ChargeRecord.push_back(Charge);
        return;
    }
};


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    ParkingCalculator PC(fees[0], fees[1], fees[2], fees[3]);
   
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

    PC.ChargeSettlement();
    answer = PC.GetChargeRecord();

    return answer;
}