//leetcode: 28. Implement strStr()

//go through haystack,
//if match the first character of needle, record that position
//use while loop to go through entire string, if it meet the end, return the position we record before.
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		for (int i = 0; i < haystack.size(); i++) {
			if (haystack[i] == needle[0]) {
				int j = 0;
				while (haystack[i + j] == needle[j] && j < needle.size()) j++;
				if (j == needle.size()) return i;
			}
		}
		return -1;
	}
};

//can use advance algorithm KMP