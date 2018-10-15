//leetcode 402. Remove K Digits
//use a stack to store the n-k #digits
//while top of stack > current digit, pop stack and insert the new one. decrease k


class Solution {
public:
	string removeKdigits(string num, int k) {
		if (k == num.size()) return "0";
		stack<char> s;
		for (int i = 0; i < num.size(); i++) {
			while (s.size() && s.top() > num[i] && k) {
				s.pop();
				k--;
			}
			if (s.size() || num[i] != '0') s.push(num[i]); //remove leading '0' 
		}
		while (k--) s.pop(); // case 112  : remove all large value at the end
		string res;
		while (s.size()) {
			res = s.top() + res;
			s.pop();
		}
		return res == "" ? "0" : res;
	}
};