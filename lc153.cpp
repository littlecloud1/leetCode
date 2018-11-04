//leetcode 153. Find Minimum in Rotated Sorted Array
//if mid > high then the increaseing int shift to left
//else shift to right

class Solution {
public:
	int findMin(vector<int>& nums) {
		int Min = nums[0];
		int low = 0, high = nums.size() - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			Min = min(nums[mid], Min);
			if (nums[mid] > nums[high]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return Min;
	}
};