//leetcode 102. Binary Tree Level Order Traversal
//BFS
//create a queue
//if the queue is not empty
//record the size of this level
//go through the amount of node of this level
//push it's left and right node into q
//also push the val into the vector and pop q
//after finish this level, push the vector into the result vector



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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> level;
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* tmp = q.front();
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
				level.push_back(tmp->val);
				q.pop();
			}
			res.push_back(level);
		}
		return res;
	}
};