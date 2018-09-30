//leetcode: 80. Remove Duplicates from Sorted Array II
//method 1: use hash to keep track of the cnt of the nums
//still keep correct area.
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		unordered_map<int, int> hash;
		int m = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (m != i) {
				nums[m] = nums[i];
			}
			if (hash[nums[i]] < 2) {
				hash[nums[i]]++;
				m++;
			}
		}

		return m;
	}
};


//method 2: compare it to correct area end - 2
//since it is sorted and no number can appear twice in that area
//so all numbers later should larger than end-2

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int m = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (m < 2 || nums[i] > nums[m - 2])
				nums[m++] = nums[i];
		}
		return m;
	}
};