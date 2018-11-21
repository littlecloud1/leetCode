//leetcode 75. Sort Colors
//use two pointers to keep the red and blue area
//if m == 1 m++
//if m == 2 swap high,m h--
//if m == 0 swap low, m low++ m++
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() <2) return;
		int l = 0, m = 0, h = nums.size() - 1;
		while (m <= h) {
			if (nums[m] == 0) {
				swap(nums[l++], nums[m++]);
			}
			else if (nums[m] == 2) {
				swap(nums[h--], nums[m]);
			}
			else m++;
		}
	}
};