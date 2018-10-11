//leetcode 88. Merge Sorted Array
//set a target at the end of nums1
//if i > j put i to target and decrease i and target
//else put j into target and decrease i and target
//while(i>=0) put all i into target
//while(j>=0) put all j into target
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m + n == 0) return;
		int target = nums1.size() - 1;
		int i = m - 1, j = n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) nums1[target--] = nums1[i--];
			else nums1[target--] = nums2[j--];
		}
		while (i >= 0) nums1[target--] = nums1[i--];
		while (j >= 0) nums1[target--] = nums2[j--];
	}
};