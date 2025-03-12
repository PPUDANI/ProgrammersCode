using System;
using System.Linq;
public class Solution {
    public int solution(int n) {
        int answer = n.ToString().Sum(c => c - '0');
        return answer;
    }
}