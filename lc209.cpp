//leetcode:209 Minimum Size Subarray Sum
// window type problem. use two pointer, i and j. O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())return 0;
        int sum = nums[0];
        int minLen = INT_MAX;
        int i,j;
        for (i =0, j = 1; i < nums.size(); i++){
            while(j < nums.size() && sum < s){
                sum += nums[j];
                j++;
            }
            if (sum >= s){
                minLen = min(minLen, j - i);
            }
            
            sum -= nums[i];
        }
        if (sum >= s){
                minLen = j - i;
            }
        if(minLen != INT_MAX) return minLen;
        else return 0;
    }
};