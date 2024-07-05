#include <vector>
#include <iostream>

std::string solution(std::string X, std::string Y) {
    std::string answer = "";

 int XLength = static_cast<int>(X.length());
 int YLength = static_cast<int>(Y.length());

 // X, Y 서로 어떤 숫자를 몇 개 가지고 있는지 체크
 std::vector<int> XNum(10, 0);
 std::vector<int> YNum(10, 0);

 for (int i = 0 ; i < XLength; ++i)
 {
     int Num = static_cast<int>(X[i]) - 48;
     ++XNum[Num];
 }

 for (int i = 0; i < YLength; ++i)
 {
     int Num = static_cast<int>(Y[i]) - 48;
     ++YNum[Num];
 }


 for (int i = 9; i >= 0 ; --i)
 {
     // 가장 큰 수인 9부터 0까지 서로 숫자가 있는지 체크
     // 둘 다 가지고 있다면 결과값에 추가하고 개수를 한개씩 제거
     while (XNum[i] > 0 && YNum[i] > 0) 
     {
         answer.push_back(i + 48);            
         --XNum[i];
         --YNum[i];
     }
 }

 // 문제 예외처리
 if (answer.length() == 0)
 {
     return "-1";
 }
 else if (answer[0] == '0')
 {
     return "0";
 }

 return answer;
}
