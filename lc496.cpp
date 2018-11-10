//leetcode 496. Next Greater Element I
//findNums is a query
//find the next greater for each i in nums
//maintain a increasing stack

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> res;
		if (findNums.empty()) return res;
		unordered_map<int, int> mp;
		stack<int> s;
		//Build hash map
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!s.empty() && s.top() <= nums[i]) {
				s.pop();
			}
			if (s.empty()) mp[nums[i]] = -1;
			else mp[nums[i]] = s.top();
			s.push(nums[i]);
		}

		//query
		for (int i : findNums) {
			res.push_back(mp[i]);
		}
		return res;
	}
};