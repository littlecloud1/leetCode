//leetcode 374. Guess Number Higher or Lower
//Binary Search
//take care of the guess API
//return my guess;


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int start = 0, end = n;
		while (start <= end) {
			int mid = start + (end - start) / 2;
			if (guess(mid) == 1) start = mid + 1;
			else if (guess(mid) == -1) end = mid - 1;
			else return mid;
		}
		return start;
	}
};