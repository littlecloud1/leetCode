//leetcode 276. Paint Fence
//n == 0 no color can paint
//n == 1 as many as k color
//n >= 2:
//this round #same is equal to prev round #diff
//the total #diff is last round (same + diff) * k-1
// since there is already one color used by last round.


class Solution {
public:
	int numWays(int n, int k) {
		if (n == 0 || k == 0) return 0;
		int same = 0;
		int diff = k;
		for (int i = 1; i < n; i++) {
			int tmp = diff;
			diff = (same + diff) * (k - 1);
			same = tmp;
		}
		return same + diff;
	}
};