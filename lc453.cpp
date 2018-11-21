//leetcode 453. Minimum Moves to Equal Array Elements
//** brute force --not work
//method 1: sorting
//the max is [n-1] and min is [0]
//add the diff  and count
//move max pointer to [n-2]...[1]


class Solution {
public:
	int minMoves(vector<int>& nums) {
		int cnt = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i > 0; i--) {
			int diff = nums[i] - nums[0];
			cnt += diff;
		}
		return cnt;

	}
};