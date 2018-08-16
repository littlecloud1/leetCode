//leetcode:340 Longest Substring with At Most K Distinct Characters
//easy sliding window question. O(n)

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		if (s.size() <= 0) return 0;
		int hash[256]{ 0 };
		int cnt = 0;
		int maxlen = 0;
		for (int i = 0, j = 0; i < s.size() && j < s.size(); i++) {
			while (j < s.size() && cnt <= k) {

				if (hash[s[j]] == 0) cnt++;
				hash[s[j]]++;
				maxlen = max(maxlen, j - i);
				j++;

			}
			if (cnt <= k)  maxlen = max(maxlen, j - i);
			if (hash[s[i]] - 1 == 0) cnt--;
			hash[s[i]]--;


		}


		return maxlen;
	}
};