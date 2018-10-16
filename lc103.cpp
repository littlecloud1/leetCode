//leetcode 103. Binary Tree Zigzag Level Order Traversal
//similar to 102.
//use a bool to tigger the next level order


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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		bool zigzag = true;
		while (!q.empty()) {
			int n = q.size();
			vector<int> level;
			for (int i = 0; i < n; i++) {
				TreeNode* tmp = q.front();
				if (tmp->right) q.push(tmp->right);
				if (tmp->left) q.push(tmp->left);
				level.push_back(tmp->val);
				q.pop();
			}
			if (zigzag) {
				reverse(level.begin(), level.end());
				zigzag = false;
			}
			else zigzag = true;
			res.push_back(level);
		}

		return res;
	}
};