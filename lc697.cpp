//leetcode: 697. Degree of an Array
//use vector and unordered_map
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        
        unordered_map<int,vector<int>> mp;
        int fq = 0, maxLen = n;
        
        for(int i = 0 ; i < n; i++){
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() > fq){
                    fq = mp[nums[i]].size();
                    maxLen = mp[nums[i]][fq-1] - mp[nums[i]][0] +1;
               }
            else if (mp[nums[i]].size() == fq){
                   maxLen = min(mp[nums[i]][fq-1] - mp[nums[i]][0] +1, maxLen);
               }
        }
        return maxLen;
    }
};