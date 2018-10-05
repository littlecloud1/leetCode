//leetcode 334. Increasing Triplet Subsequence
/*
use two variable i, j
i is the smallest in the increasing subseq
j is a number smaller than k
if the upcomming number <= i, update i
else if <= j, update j
else return ture
it work because, it must exist and i before update j

*/
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int i = INT_MAX, j = INT_MAX;
		for (int k : nums) {
			if (k <= i) i = k;
			else if (k <= j) j = k;
			else return true;

		}
		return false;
	}
};