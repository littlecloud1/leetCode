//leetcode: 46. Permutations
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        if(nums.empty())return res;
        dfs(res, sub, nums);
        return res;
        
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums){
        if(sub.size() == nums.size()){
            res.push_back(sub);
            return;
        }
        //use a loop to use every not-used element
        for (int i =0; i < nums.size(); i++){
            if(find(sub.begin(), sub.end(), nums[i]) == sub.end()){
                sub.push_back(nums[i]);
                dfs(res, sub, nums);
                sub.pop_back();
            }
        }
    }
    
};