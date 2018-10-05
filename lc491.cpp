//leetcode 491. Increasing Subsequences
/*
backtracking problem
use dfs
reference to subsetII
use the skill to remove duplicate
*/
class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> list;
		helper(res, nums, 0, list);
		return res;
	}

	void helper(vector<vector<int>>& res, vector<int> nums, int pos, vector<int> list) {

		if (list.size() > 1)res.push_back(list);
		unordered_set<int> hash;
		for (int i = pos; i< nums.size(); i++) {
			if (hash.find(nums[i]) == hash.end() && (list.empty() || nums[i] >= list.back())) {
				list.push_back(nums[i]);
				helper(res, nums, i + 1, list);
				list.pop_back();
				hash.insert(nums[i]);


			}
		}

	}



};