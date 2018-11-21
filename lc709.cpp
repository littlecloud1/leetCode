//leetcode 709. To Lower Case
//c = c - 'A' + 'a'
class Solution {
public:
	string toLowerCase(string str) {
		string s;
		for (char c : str) {
			if (c >= 'A' && c <= 'Z') {
				c = c - 'A' + 'a';
			}
			s = s + c;
		}
		return s;
	}
};