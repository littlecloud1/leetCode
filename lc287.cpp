//leetcode 287 Find the Duplicate Number
//reduce the problem into cycle detection
//the next node's index is the value of current node
//Use floyd's cycle detection algorithm

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.empty()) return -1;
		int walk = nums[0];
		int jump = nums[nums[0]];

		while (walk != jump) {
			walk = nums[walk];
			jump = nums[nums[jump]];
		}

		//after detect the cycle
		jump = 0;

		while (walk != jump) {
			walk = nums[walk];
			jump = nums[jump];

		}

		return jump;
	}
};