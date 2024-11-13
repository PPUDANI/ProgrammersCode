#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n <= 1) return false;  // 1 이하의 숫자는 소수가 아님
    if (n == 2) return true;   // 2는 소수
    if (n % 2 == 0) return false; // 2 외의 짝수는 소수가 아님

    // 3부터 sqrt(n)까지 나누어보며 소수 판별
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers)
{
    set<int> numSet;  // 중복을 자동으로 처리하는 set 사용

    // numbers의 모든 순열을 생성
    sort(numbers.begin(), numbers.end());  // 순열을 만들기 위해 정렬
    do {
        // 순열로 만든 숫자를 set에 추가
        for (int len = 1; len <= numbers.length(); ++len) {
            int num = stoi(numbers.substr(0, len));  // 부분 문자열을 숫자로 변환
            numSet.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    int count = 0;

    // numSet에 있는 숫자들이 소수인지 체크
    for (int num : numSet) {
        if (isPrime(num)) {
            count++;
        }
    }

    return count;
}