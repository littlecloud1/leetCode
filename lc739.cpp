//leetcode 739. Daily Temperatures
//using stack
//start from the end of the array. keep an increasing stack

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> res(T.size(), 0);
		if (T.empty()) return res;
		stack<int> s;
		for (int i = T.size() - 1; i >= 0; i--) {
			//find the next greater
			while (!s.empty() && T[s.top()] <= T[i]) {
				s.pop();
			}
			//T[i] is the tmp greatest
			if (s.empty()) {
				res[i] = 0;
			}
			else {
				res[i] = s.top() - i;
			}

			s.push(i);
		}
		return res;
	}
};