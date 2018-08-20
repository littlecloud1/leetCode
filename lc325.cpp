//leetcode:325 Maximum Size Subarray Sum Equals k
//It looks similar to 209 but it is totally different.

//Use the prefix sum of the current position and find a start index to form a subwindow with sum  k 
//[1, -1, 5, -2, 3] k=2
//now we are  ^ here  prefix sum of index 3 is 1 -1 +5 -2 = 2
//to find the start index use index 3 pre - k = start prefix
//if the start fix is in map, then we found the subwindow start index.
//eg. 
// 0..3 - 2 = 0 <-- the prefix we need is already recoded in map [0:1] (prefix-sum:index)
// 0..3 - 0..1 = 2 - 0 = 2 <- k
//So we only need to find the key(prefix-sum - k ) in map
//It is O(n) 


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int maxLen = 0;
        unordered_map <int, int> map;
        int sum = 0;
        
        for(int i =0; i < nums.size(); i++){
            sum += nums[i];
            if (sum == k) maxLen = i+1;
            else if(map.find(sum - k) != map.end()) maxLen = max(maxLen, i - map[sum - k]);
            if(map.find(sum) == map.end()) map[sum] = i;
            
            
        }
    
        return maxLen;
        
    }
};