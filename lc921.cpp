//leetcode 921. Minimum Add to Make Parentheses Valid


class Solution {
public:
	int minAddToMakeValid(string S) {
		stack<char> st;
		int m = 0;
		for (char c : S) {
			if (c == '(') st.push(c);
			else {
				if (!st.empty() && st.top() == '(') { st.pop(); }
				else m++;
			}
		}
		return m + st.size();
	}
};