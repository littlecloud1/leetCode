//leetcode 268. Missing Number
/*
method 1: Gauss' Formula
sum of expected answer - actual sum of nums = missing number
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int actual = 0, expected = 0;
		for (int i = 0; i < nums.size(); i++) {
			actual += nums[i];
			expected += i;
		}
		expected += nums.size();
		return expected - actual;
	}
};

/*
method 2: bit manipulation
use XOR for the i and nums [i];
the number left at the end is the missing number
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int miss = nums.size();
		for (int i = 0; i< nums.size(); i++) {
			miss ^= nums[i];
			miss ^= i;
		}
		return miss;

	}
};