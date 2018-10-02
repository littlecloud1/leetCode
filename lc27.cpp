//leetcode: 27. Remove Element
/*
	to in-place remove, manage an area that is without target val
	return the length of that area.
*/
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int m = 0;
		if (nums.empty()) return nums.size();
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[m] = nums[i];
				m++;
			}
		}
		return m;
	}
};