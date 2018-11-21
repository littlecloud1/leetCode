//leetcode 695. Max Area of Island
//go through the grid, if it see any land,
//call dfs function and compare the return value to the maximum
//update the maximum
//return the maximum
//dfs functions:
//dfs all directions,
//sum up the return value,
//mark the current land to zero
//return value+1
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					int area = dfs(grid, i, j);
					maxArea = max(maxArea, area);
				}
			}

		}
		return maxArea;
	}

	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (grid[i][j] == 0) return 0;
		grid[i][j] = 0; //marked as zero
		int area = 1;
		if (i - 1 >= 0) area += dfs(grid, i - 1, j);// up
		if (i + 1 < grid.size()) area += dfs(grid, i + 1, j); //down
		if (j - 1 >= 0) area += dfs(grid, i, j - 1); // left
		if (j + 1 < grid[i].size()) area += dfs(grid, i, j + 1); // right
		return area;
	}

};