class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //handle the case where there is only a singular day -> return 0 since no trade can be made
        if(prices.size() == 1) return 0;

        //init the min price thus far to be the first elem in prices
        int buy = prices[0];
        //init the profit thus far to be 0
        int profit = 0;

        //loop through each element in prices
        for(int p : prices)
        {
            //find the profit to be the max between profit seen so far and the curr possible profit
            profit = max(profit, p - buy);
            //update min to be the minimum between min and p
            buy = min(buy, p);
        }

        //once looped through -> return profit, if there is no profitable sell day -> will return 0
        return profit;
    }
};
