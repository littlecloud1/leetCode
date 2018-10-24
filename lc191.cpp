//leetcode 191. Number of 1 Bits
//even time move one bit
//use and gate to check if the lsb is one, if yes, increase cnt.

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n) {
			if (n & 1) cnt++;
			n = n >> 1;
		}
		return cnt;
	}
};