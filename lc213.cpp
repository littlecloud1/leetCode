//leetcode: 213. House Robber II
//run House Robber 2 times

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];

		int prev = 0;
		int cur = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			int tmp = cur;
			cur = max(prev + nums[i], cur);
			prev = tmp;
		}

		int res = cur;
		cur = prev = 0;
		for (int i = 1; i < nums.size(); i++) {
			int tmp = cur;
			cur = max(prev + nums[i], cur);
			prev = tmp;
		}
		return max(res, cur);

	}
};