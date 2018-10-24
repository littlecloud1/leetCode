//leetcode 461. Hamming Distance
//caculate the hamming distance means the amount of bit differents
//go through x and y until both == zero
// shift 1 bit each time, if the lsb are not equal then increase count
//return count at the end.
class Solution {
public:
	int hammingDistance(int x, int y) {
		int cnt = 0;
		while (x > 0 || y >0) {
			if (x % 2 ^ y % 2 == 1) cnt++;
			x = x >> 1;
			y = y >> 1;
		}
		return cnt;
	}
};