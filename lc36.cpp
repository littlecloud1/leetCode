//leetcode: 36. Valid Sudoku
//use three flag to store already appear number
//for the subproblem , the index of it is i/3*3 + j/3
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool row[9][9] = { false };
		bool col[9][9] = { false };
		bool sub[9][9] = { false };

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '1';
					int k = i / 3 * 3 + j / 3;
					if (row[i][num] || col[j][num] || sub[k][num]) return false;
					row[i][num] = true;
					col[j][num] = true;
					sub[k][num] = true;
				}
			}
		}
		return true;
	}
};