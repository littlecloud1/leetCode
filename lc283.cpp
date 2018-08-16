//leetcode:283 Moves Zeros.
//use two pointers, keep track of the leading zero and leading non-zero. swap these two values.
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int i = 0, j = 0; j < nums.size() - 1; ) {
			//found zero position
			if (nums[i] == 0) {
				//find the 1st non zero
				while (nums[j] == 0 && j < nums.size() - 1) j++;
				nums[i++] = nums[j];
				nums[j] = 0;
			}
			else {
				i++;
				j++;
			}



		}
	}
};