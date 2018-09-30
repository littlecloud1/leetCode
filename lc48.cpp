//leetcode: 48. Rotate Image
//First reverse up to down. 
//Then symmetry
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		//reverse up to down
		int n = matrix.size() - 1;
		int m = matrix[0].size();
		for (int i = 0; i < n / 2 + 1; i++) {
			vector<int> tmp(matrix[i]);
			matrix[i] = matrix[n - i];
			matrix[n - i] = tmp;
		}

		//symmetric
		for (int i = 0; i < n; i++)
			for (int j = i; j < m; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;

			}
	}

};