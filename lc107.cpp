//leetcode 107. Binary Tree Level Order Traversal II

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			vector<int> level;
			while (n--) {
				TreeNode* tmp = q.front();
				if (tmp->left)q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
				level.push_back(tmp->val);
				q.pop();
			}
			res.push_back(level);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};