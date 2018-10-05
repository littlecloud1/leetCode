//leetcode 34. Find First and Last Position of Element in Sorted Array
//use BinarySearch
//find out the first index of target and target+1
//return the result.
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res = { -1,-1 };
		int small = bs(nums, target);
		int large = bs(nums, target + 1) - 1;
		if (small < nums.size() && nums[small] == target) {
			res[0] = small;
			res[1] = large;
		}
		return res;
	}

	int bs(vector<int> & nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (nums[mid] < target) start = mid + 1;
			else end = mid - 1;
		}
		return start;

	}
};