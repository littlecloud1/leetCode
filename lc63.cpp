//leetcode 63. Unique Paths II
//similar to 64, but include obstacle
//detect the obstacle, the special case is the obstacle locate on boundries
//also the obstacle locate on obstacleGrid[0][0]


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else if (i == 0) {
					if (j == 0) dp[i][j] = 1;
					else dp[i][j] = dp[i][j - 1] ? 1 : 0;
				}
				else if (j == 0) {
					dp[i][j] = dp[i - 1][j] ? 1 : 0;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[n - 1][m - 1];
	}
};