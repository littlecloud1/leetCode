//leetcode 33. Search in Rotated Sorted Array
//use binary search to find the index of smallest value
//l == h, is the rotate index;
//then we use binary search to find the target


class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0, h = nums.size() - 1;
		//find the smallest value
		while (l<h) {
			int m = (l + h) / 2;
			if (nums[m] > nums[h]) l = m + 1;
			else h = m;
		}
		int shift = l;
		//apply the shfit
		l = 0, h = nums.size() - 1;
		while (l <= h) {
			int m = (l + h) / 2;
			int realm = (m + shift) % nums.size();
			if (nums[realm] == target) return realm;
			if (nums[realm] < target) l = m + 1;
			else h = m - 1;
		}
		return -1;
	}
};