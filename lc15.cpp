//leetcode:15 3SUM
//idea: https://www.youtube.com/watch?v=-AMHUdZc9ss



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty()) return res;
		sort(nums.begin(), nums.end());   //sort every element !!very important. make it much easier to move start and end pointer

		//have to check if nums.size is >=3, otherwise it will cause error.
		for (int i = 0; i < nums.size() - 2 && nums.size() >= 3; i++) {

			//skip repeated element at the front
			if (i == 0 || nums[i] > nums[i - 1]) {
				int start = i + 1;
				int end = nums.size() - 1;

				//check all the combinations between start and end
				while (start < end) {
					if (nums[i] + nums[start] + nums[end] == 0) {
						vector<int> triplet;
						triplet.push_back(nums[i]);
						triplet.push_back(nums[start]);
						triplet.push_back(nums[end]);
						res.push_back(triplet);
					}

					//increase start pointer and skip the duplicate
					if (nums[i] + nums[start] + nums[end] < 0) {
						int tmp = start;
						while (nums[start] == nums[tmp] && start < end) start++;
					}

					// the result is larger than / equal to zero, decrease end to decrese the result
					// also skip the duplicate.
					else {
						int tmp = end;
						while (nums[end] == nums[tmp] && start < end) end--;

					}
				}
			}
		}

		return res;
	}
};