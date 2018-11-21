//leetcode 503. Next Greater Element II
//maintain an increasing sequence with stack
//to solve the circular problem
//we can prestore the increasing sequence first
//then do it again for normal comparsion. 


class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size(), 0);
		if (nums.empty()) return res;

		stack<int> s;
		//pre-store the increasing sequence
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && s.top() <= nums[i]) {
				s.pop();
			}
			s.push(nums[i]);
		}

		//find the next greater
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && s.top() <= nums[i]) {
				s.pop();
			}
			if (s.empty()) res[i] = -1;
			else res[i] = s.top();
			s.push(nums[i]);
		}
		return res;
	}
};