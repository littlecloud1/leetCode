//leetcode 304. Range Sum Query 2D - Immutable
//given starting point and ending point
//the range of row : row1 -> row2
//the range of col : col1 -> col2
// we can use two forloop:
//i from row1 to row2
//j form col1 to col2
//sum += M[i][j]




class NumMatrix {
private:
	vector<vector<int>> M;
public:
	NumMatrix(vector<vector<int>> matrix) {
		for (auto i : matrix) {
			M.push_back(i);
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) sum += M[i][j];
		}
		return sum;
	}
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/