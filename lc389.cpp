//leetcode 389. Find the Difference
/*
bit manipulation:
go through s and t, use XOR
the letter left is the extra letter.
*/
class Solution {
public:
	char findTheDifference(string s, string t) {
		int different = t[t.size() - 1];
		for (int i = 0; i < s.size(); i++) {
			different ^= s[i];
			different ^= t[i];
		}
		return different;
	}
};