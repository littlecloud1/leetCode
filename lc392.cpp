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
/*
use a vector to record every char and vector of its indexs
go through s, record the prev
find the upper bound of the index of current char in t,
if the index > prev, continue
else return false
O(len(s))*O(log(len(t)))
*/

class Solution {
public:
	bool isSubsequence(string s, string t) {
		vector<vector<int>> hash;
		hash.resize(128);
		for (int i = 0; i < t.size(); i++) {
			hash[t[i]].push_back(i);
		}
		int prev = -1;
		for (char c : s) {
			vector<int> it = hash[c];
			if (it.empty()) return false;
			auto cur = upper_bound(it.begin(), it.end(), prev);
			if (cur == it.end() || *cur < prev) return false;
			prev = *cur;
		}
		return true;
	}
};
