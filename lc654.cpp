//leetcode 654. Maximum Binary Tree
//if the incoming value > left, root become the incomming value, put the old root to the left
//else if root right is not empty, dfs the root right because it might need to reconstructe the right subtree
//else just add it there.

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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.empty()) return NULL;
		TreeNode* root = new TreeNode(nums[0]);
		for (int i = 1; i< nums.size(); i++) {
			root = helper(root, nums[i]);
		}
		return root;
	}

	TreeNode* helper(TreeNode* root, int n) {
		if (!root) return root;
		//put to left
		if (n > root->val) {
			TreeNode* head = new TreeNode(n);
			head->left = root;
			root = head;
		}
		//put to right
		else {
			if (root->right) root->right = helper(root->right, n);
			else root->right = new TreeNode(n);
		}
		return root;



	}

};