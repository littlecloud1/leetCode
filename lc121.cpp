//leetcode: 121. Best Time to Buy and Sell Stock
//the maximum profit is the max(maxprice- minprice)
//O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_Profit = 0;
        if(prices.empty()) return max_Profit;
        int min_price = INT_MAX;
        for(int i =0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            max_Profit = max(max_Profit, prices[i] - min_price);
        }
        
        return max_Profit;
    }
};