class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # declare buyDay as start of prices, sellDay as 1 after buyDay
        buyDay = 0
        sellDay = 1

        # declare an int representing highestProfit seen
        highestProfit = 0

        # keep looping sellDay until it reaches the end of the prices
        while sellDay < len(prices):
            # check if the buy and sell days make the trade profitable
            if prices[sellDay] - prices[buyDay] > 0:
                # calc the profit and update highestProfit if needed
                profit = prices[sellDay] - prices[buyDay]
                highestProfit = max(highestProfit, profit)
            # if not profitable then update buyDay to be the current
            # sell day
            else:
                buyDay = sellDay
            
            # increment sellDay
            sellDay += 1

        # return the highest profit seen, 0 if there are no profitable
        # trades
        return highestProfit



