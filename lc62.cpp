//leetcode 62. Unique Paths
//the robot can only move down or right;
//the current position is come from its up and left;
//therefore the steps to move to current position is add the steps of up and left 

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n - 1][m - 1];
	}
};