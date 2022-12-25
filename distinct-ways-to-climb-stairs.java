/*
 * You are climbing a staircase. It takes n steps to reach the top. 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
    public int climbStairs(int n) {
        int S[] = new int[n+1];
        S[0] = 1; S[1] = 1;
        for(int i = 2; i <= n; i++)
            S[i] = S[i-1] + S[i-2];
        return S[n];
    }
} 