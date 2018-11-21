//leetcode 324. Wiggle Sort II
//sort it
//put the large half on odd and small half on even
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() < 2) return;
		vector<int> s(nums);
		sort(s.begin(), s.end());
		int n = nums.size(), j = 0, k = (n - 1) / 2 + 1;
		for (int i = n - 1; i >= 0; i--) {
			nums[i] = (i % 2) ? s[k++] : s[j++];
		}

	}
};