#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices) {
    int max_profit = 0;
    for(int i = 0; i < prices.size()-1; i++) {
        for(int j = i+1; j < prices.size(); j++) {
            int profit = prices[j] - prices[i];
            if(profit > max_profit) {
                max_profit = profit;
            }
        }
    }
    return max_profit;
}

int main() {
    cout << maxProfit({7,1,5,3,6,4}) << "\n";
}