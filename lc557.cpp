//leetcode 557. Reverse Words in a String III
//two pointers
//moving j until reach ' ', then reverse i to j=1
//set i = j+1 and j = i

class Solution {
public:
	string reverseWords(string s) {
		if (s.empty()) return s;
		int i = 0, j = 0;
		for (; j <= s.size(); j++) {
			if (j == s.size() || s[j] == ' ') {
				reverse(s, i, j - 1);
				i = j + 1;
				j = i;
			}
		}
		return s;
	}
	void reverse(string& s, int i, int j) {
		while (i < j) {
			swap(s[i], s[j]);
			i++;
			j--;
		}
	}

};