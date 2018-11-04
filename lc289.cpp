//leetcode 289. Game of Life
//use bit manipulation
//00 dead -> dead
//01 live -> dead
//10 dead -> live
//11 live -> live

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty()) return;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				int live = 0;
				//count live around the cell
				for (int I = max(i - 1, 0); I < min(i + 2, (int)board.size()); I++) {
					for (int J = max(j - 1, 0); J < min(j + 2, (int)board[0].size()); J++) {
						live += board[I][J] & 1;
					}
				}
				live -= board[i][j] & 1;
				if (board[i][j] == 1) {
					if (live >= 2 && live <= 3) board[i][j] = 3;
				}
				else {
					if (live == 3) board[i][j] = 2;
				}
			}
		}
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				board[i][j] >>= 1;
			}
		}
	}

};