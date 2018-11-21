//leetcode 167. Two Sum II - Input array is sorted
//use two pointers: a at the begin and b at the end
//if a + b > target, decrease b
//if a + b < target, increase a

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		if (numbers.empty()) return numbers;
		vector<int> ans;
		int a = 0, b = numbers.size() - 1;
		while (a < b && ans.empty()) {
			if (numbers[a] + numbers[b] == target) {
				ans.push_back(a + 1);
				ans.push_back(b + 1);
			}
			if (numbers[a] + numbers[b] > target) b--;
			else if (numbers[a] + numbers[b] < target) a++;
		}
		return ans;
	}
};