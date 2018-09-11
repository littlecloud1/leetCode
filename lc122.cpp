//leetcode: 122. Best Time to Buy and Sell Stock II
//sell before the price drop. buy in at that drop day.
//the max profit is today price - yesterday price if it is positive.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        
        //sell before the price drop. buy in at that drop day.
        //the max profit is today price - yesterday price if it is positive.
        
        for(int i =1; i < prices.size(); i++){
            profit += max(prices[i] - prices[i-1], 0);
        }
        return profit;
    }
};