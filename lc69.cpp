//leetcode 69. Sqrt(x)
//use binary search
//if m ^2 is smaller than target but (m+1) is larger than targer
//then the sqrt should between m+1 and m
// to truncated the decimal part, we take m 
class Solution {
public:
	int mySqrt(int x) {
		if (!x) return 0;
		int start = 1;
		int end = x;
		while (start <= end) {
			int m = start + (end - start) / 2;
			if (m > x / m) end = m - 1;
			else if (m + 1 > x / (m + 1)) return m;
			else {
				start = m + 1;
			}
		}
		return start;
	}
};