//leetcode 300. Longest Increasing Subsequence
/*
dynamic programming O(n2)
if nums[i] > nums[j]
dp[i] = max(dp[i],dp[j]+1)
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp(nums.size(), 1);
		int Max = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			Max = max(Max, dp[i]);
		}

		return Max;
	}
};


/*
the new smaller number won't affect the length, but might affect the next coming num
so replace the upper bound in the list
if the number is largest, add it at the end

maintain an vector of possible increasing subsequence
go through nums
find the lowerbound and replace it
if not found, push back
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> list;
		for (int i : nums) {
			auto it = lower_bound(list.begin(), list.end(), i);
			if (it == list.end()) list.push_back(i);
			else *it = i;
		}
		return list.size();
	}
};