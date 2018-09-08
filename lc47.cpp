// leetcode:47. Permutations II
// use the backtracking model
// make use of hash to record 
// the complexity of recursive function is branches * depth
// branches = n * n-1 * n-2 * ... 1 = n!
// depth = n
// so the complexity is O(n!n) = O(n!)

class Solution {
public:
    unordered_map<string, int> hash;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        if (nums.empty()) return res;
        bool used[nums.size()] = {false}; //make sure to initialize bool
        sort(nums.begin(), nums.end());
        dfs(res, sub, nums, used, "");
        
        return res;
    }
        
    void dfs (vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, bool used[], string s){
        if (sub.size() == nums.size() && hash.find(s) == hash.end()){
            res.push_back(sub);
            hash[s] = 1;
            return;
        }
        for (int i =0; i < nums.size(); i++){
            if(!used[i]){
                used[i] = true;
                sub.push_back(nums[i]);
                string sub_s = s + to_string(nums[i]);
                dfs(res, sub, nums, used, sub_s);
                sub.pop_back();
                used[i] = false;
            }
        }
    }
};
//improve:
//because nums is sorted, we only have to check if nums[i] == nums[i-1] and previous one used
//if it is the same and not used, then skip
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<int> sub;
		vector<vector<int>> res;
		if (nums.empty()) return res;
		bool used[nums.size()] = { false }; //make sure to initialize bool
		sort(nums.begin(), nums.end());
		dfs(res, sub, nums, used);

		return res;
	}

	void dfs(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, bool used[]) {
		if (sub.size() == nums.size()) {
			res.push_back(sub);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				if (i > 0 && nums[i] == nums[i - 1] && used[i - 1]) continue;
				used[i] = true;
				sub.push_back(nums[i]);
				dfs(res, sub, nums, used);
				sub.pop_back();
				used[i] = false;
			}
		}
	}
};