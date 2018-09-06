//leetcode:78. Subsets
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> s;
        vector<vector<int>> res;
        if (nums.empty())return res;
            helper(res, nums , s, 0);
        
        return res;
        
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, vector<int> s, int i){
        res.push_back(s);
        for(int k =i; k< nums.size(); k++){
            s.push_back(nums[k]);
            helper(res, nums, s,k+1);
            s.pop_back();
        }
    }
};