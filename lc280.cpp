//leetcode 280. Wiggle Sort
//if the position is odd then nums[i] >= nums[i-1]
//if the position is even then nums[i] <= nums[i-1]
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() < 2) return;
		for (int i = 1; i < nums.size(); i++) {
			if (i % 2) {
				if (nums[i] < nums[i - 1]) {
					swap(nums[i], nums[i - 1]);
				}
			}
			else {
				if (nums[i] > nums[i - 1]) {
					swap(nums[i], nums[i - 1]);
				}
			}
		}
	}
};