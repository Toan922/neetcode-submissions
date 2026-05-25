class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;

        int minPrice = prices[0];
        int profit = 0;

        for (int price : prices)
        {
            profit = max(profit, price - minPrice);
            minPrice = min(price, minPrice);
        }

        return profit;
    }
};
