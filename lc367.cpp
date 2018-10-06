//leetcode 367. Valid Perfect Square
//this question can be solved by many method.

//method 1: increase i and check if i*i == num until i*i > num O(sqrt(n))

class Solution {
public:
	bool isPerfectSquare(int num) {

		for (long i = 1; i*i <= num; i++) {
			if (i*i == num) return true;
		}
		return false;

	}
};

//method 2: binary search mid = num /2  O(logn)
class Solution {
public:
	bool isPerfectSquare(int num) {
		int start = 1;
		int end = num;
		while (start <= end) {
			long mid = start + (end - start) / 2;
			if (mid * mid == num) return true;
			else if (mid * mid > num) end = mid - 1;
			else start = mid + 1;
		}
		return start * start == num ? true : false;
	}
};

//method 3: 1 + 3 + 5 + 7 + .... O(sqrt(n))
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 1) return false;
		int i = 1;
		while (num > 0) {
			num -= i;
			i += 2;
		}
		return num == 0;

	}
};
//method 4: newton
class Solution {
public:
	bool isPerfectSquare(int x) {
		long r = x;
		while (r*r > x)
			r = (r + x / r) / 2;
		return r*r == x;
	}
};
