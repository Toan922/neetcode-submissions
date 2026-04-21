class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyDay = 0
        sellDay = 1
        highestProfit = 0

        while sellDay < len(prices):
            if prices[sellDay] - prices[buyDay] > 0:
                profit = prices[sellDay] - prices[buyDay]
                highestProfit = max(highestProfit, profit)
            else:
                buyDay = sellDay

            sellDay += 1

        return highestProfit