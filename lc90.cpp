//leetcode: 90. Subset II
//It is similar to Subset 
//It allows duplicate and the result have to be sorted.
//hash doesn't allow vector as key, I use string to be the key
//O(2^n) <- the no. of a powerset. 
class Solution {
public:
    unordered_map<string, int> mp; //global hash: keep track on duplicate.
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>>  res;
        if(nums.empty()) return res;
        helper(res, sub, nums, 0,  "");
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int start, string s){
        if(mp.find(s) == mp.end()) {
            res.push_back(sub);
            mp[s] == 1;
        }
        for(int i = start; i < nums.size(); i++){
            sub.push_back(nums[i]);
            string sub_s = s + to_string(nums[i]);  // use a new string to skip origin s.
            helper(res, sub, nums, i+1,  sub_s);
            sub.pop_back();
        }
    }
};