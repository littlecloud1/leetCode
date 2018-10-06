//leetcode: 198. House Robber
//dynamic programming

class Solution {
public:
	int rob(vector<int>& nums) {
		int prev = 0;
		int cur = 0;
		for (int i : nums) {
			int tmp = cur;
			cur = max(prev + i, cur);
			prev = tmp;
		}
		return cur;
	}
};