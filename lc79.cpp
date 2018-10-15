//leetcode 79. Word Search
//to avoid reusing same cell, marked the cell in place as used
//go through entire board
//dfs each cell
//each time if the letter match and the cell is available
//mark the cell as used,
//dfs all directions
//if all directions doesn't work and pos + 1 != word.size(),(if there is only one cell)
// release the cell in mp return false,
//else return false.



class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		bool found = false;
		vector<vector<int>> mp(board.size(), vector<int>(board.size(), 1));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				found = dfs(board, i, j, word, 0);
				if (found) return found;
			}
		}
		return found;
	}

	bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos) {
		if (pos == word.size()) return true;
		if (board[i][j] != word[pos]) return false;
		if (board[i][j] == word[pos]) {
			char tmp = board[i][j];
			board[i][j] = 0;
			bool u = false, d = false, l = false, r = false;
			if (i - 1 >= 0)  u = dfs(board, i - 1, j, word, pos + 1);
			if (i + 1 < board.size())  d = dfs(board, i + 1, j, word, pos + 1);
			if (j - 1 >= 0)  l = dfs(board, i, j - 1, word, pos + 1);
			if (j + 1 < board[i].size())  r = dfs(board, i, j + 1, word, pos + 1);
			if (u || d || l || r || pos + 1 == word.size()) return true;
			else {
				board[i][j] = tmp;
				return false;
			}
		}
		else {
			return false;
		}

	}


};