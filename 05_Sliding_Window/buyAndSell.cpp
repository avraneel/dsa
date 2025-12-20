#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices) {
    int profit = 0;
    int buy = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] < buy) {
            buy = prices[i];
        }
        else if(prices[i] - buy > profit) {
            profit = prices[i] - buy;
        }
    }
    return profit;
}

int main() {
    cout << maxProfit({7,1,5,3,6,4}) << "\n";
}