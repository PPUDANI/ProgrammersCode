using System;
using System.Linq;

public class Solution {
    public int solution(int[] sides) 
    {
        int maxSide = sides.Max();
        int restSum = sides.Sum() - maxSide;
        return maxSide < restSum ? 1 : 2;
    }
}