//53. Maximum Subarray
//dynamic programing
//can use only two int to record sum.
//O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size()+1, 0);
        int maxN = nums[0];
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            dp[i+1] = max(nums[i], nums[i]+dp[i]);
            maxN = max(dp[i+1], maxN);
        }
        return maxN;
    }
};