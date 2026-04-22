class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyDay = 0
        sellDay = 1

        highestProfit = 0

        while sellDay < len(prices):
            # check if the trade would be profitable at all
            if prices[sellDay] - prices[buyDay] > 0:
                # if it is then calc the profit and take the max between
                # highest profit and the calc'd one
                profit = prices[sellDay] - prices[buyDay]
                highestProfit = max(highestProfit, profit)
            # otherwise set the buyDay to be the sellDay
            else:
                buyDay = sellDay
            
            # always increment sellDay
            sellDay += 1

        return highestProfit