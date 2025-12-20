"""
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Brute Force Approach
Let prices[i] = [7,1,5,3,6,4]
"""

# brute force
def maxProfit(prices):

    # stores the maximum profit
    max_profit = 0

    for i in range(0, len(prices) - 1, 1):
        for j in range(i+1, len(prices), 1):
            profit = prices[j] - prices[i]
            if profit > max_profit:
                max_profit = profit
    
    return max_profit

    
print(maxProfit([7,1,5,3,6,4]))
print(maxProfit([7,6,4,3,1]))
