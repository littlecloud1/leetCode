//leetcode: 278. First Bad Version
//using Binary Search
//to avoid overflow
//use start+(end-start)/2


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 0, end = n;
		int fbv = 0;
		while (start <= end) {
			int m = start + (end - start) / 2;
			if (isBadVersion(m)) end = m - 1;
			else start = m + 1;
		}
		if (isBadVersion(start)) return start;
		else return start + 1;
	}
};