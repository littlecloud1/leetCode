//leetcode 235. Lowest Common Ancestor of a Binary Search Tree
//if r > n2 > n1, the lca should be on left side
//if r < n2 < n1, the lca should be on right side
//if r between n2 and n1, the r should be lca
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q) return root;
		if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
		else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
		return root;
	}
};