"""
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
O(n) approach
Let prices[i] = [7,1,5,3,6,4]
"""

def maxProfit(prices):
    buy = prices[0]
    # stores the maximum profit
    profit = 0
    for i in range(1, len(prices) - 1):
        if prices[i] < buy:
            buy = prices[i]
        elif prices[i] - buy > profit:
            profit = prices[i] - buy
    
    return profit

    
print(maxProfit([7,1,5,3,6,4]))
print(maxProfit([7,6,4,3,1]))
