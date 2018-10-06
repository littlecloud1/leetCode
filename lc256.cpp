//leetcode 256. Paint House
//use dynamic programming
//to save space, add the cost directly to the costs matrix;
//dp(housei,colork) = costs(housei,colork) + min(dp(housei-1,color!k))

class Solution {
public:
	int minCost(vector<vector<int>>& costs) {
		if (costs.empty()) return 0;
		int n = costs.size();
		for (int i = 1; i < n; i++) {
			costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
			costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
			costs[i][2] += min(costs[i - 1][1], costs[i - 1][0]);
		}
		int cost = min(costs[n - 1][0], costs[n - 1][1]);
		return min(cost, costs[n - 1][2]);


	}
};