//leetcode: 392. Is Subsequence
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0;
		for (int j = 0; i< s.size() && j < t.size(); j++) {
			if (s[i] == t[j]) i++;
		}
		return i == s.size();
	}
};

/*Follow up :
If there are lots of incoming S, say S1, S2, ..., Sk where k >= 1B, 
and you want to check one by one to see if T has its subsequence.
In this scenario, how would you change your code ?*/

//Binary Search

