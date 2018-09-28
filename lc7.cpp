//leetcode: 7. Reverse Integer
//the sign will capture in x % 10
//to detect if ans is overflow, reverse it to previous ans and see if their are the same.

class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		int ans = 0;
		while (x != 0) {
			int digit = x % 10;
			int tmp = ans * 10 + digit;
			if (tmp / 10 != ans) return 0;
			ans = tmp;
			x /= 10;
		}
		return ans;
	}
};