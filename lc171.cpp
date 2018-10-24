//leetcode 171. Excel Sheet Column Number
//go through S from the begin to the end
//sum += sum*26+current value
class Solution {
public:
	int titleToNumber(string s) {
		if (s.empty()) return 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum = sum * 26 + (s[i] - 'A' + 1);
		}
		return sum;
	}
};