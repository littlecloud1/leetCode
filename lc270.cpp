//leetcode 270. Closest Binary Search Tree Value
//dfs start from the root
//compare the diff between child and target , root and target
//return the 
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
	int closestValue(TreeNode* root, double target) {
		if (!root) return -1;
		return dfs(root, target);
	}

	int dfs(TreeNode* root, double target) {
		int child = root->val;
		if (target < root->val && root->left) child = dfs(root->left, target);
		else if (root->right) child = dfs(root->right, target);
		child = (abs(child - target) < abs(root->val - target)) ? child : root->val;
		return child;
	}
};