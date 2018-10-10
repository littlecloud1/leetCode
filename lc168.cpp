//leetcode 168. Excel Sheet Column Title
//given n, turn to column title
//to get the title: (n-1) % 26 + 'A'
//to go to next digit, n =  (n-1) / 26
class Solution {
public:
	string convertToTitle(int n) {
		if (n < 1) return "";
		string s = "";
		while (n > 0) {
			char c = (n - 1) % 26 + 'A';
			s = c + s;
			n = (n - 1) / 26;
		}
		return s;
	}
};