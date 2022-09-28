#include <bits/stdc++.h>
using namespace std;

int mindistance (string wd1, string wd2) {
    int m = wd1.length();
    int n = wd2.length();

    int dp[m+1][n+1];

    for(int i = 0; i < m+1; i++) dp[i][0] = i;
    for(int i = 0; i < n+1; i++) dp[0][i] = i;

    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(wd1[i-1] == wd2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
        }
    }
}