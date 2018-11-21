//leetcode 333. Largest BST Subtree
//condition of being a BST:
//1. L <= root < R
//2. L and R are also BST

//dfs the root
// get following variables from L and R:
//Lsize, Rsize, Lmin, Rmin, Lmax, Rmax
//if Lmax < root < Rmin && dfs(R) &&dfs(L):
//size = Lsize + Rsize + 1
//min = L? Lmin:root->val (L/ R can be NULL)
//max = R? Rmax:root->val
//return true
//else just proporgate the max size from Left / Right;



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
	int largestBSTSubtree(TreeNode* root) {
		if (!root) return 0;
		int size = 0;
		int min = INT_MAX;
		int max = INT_MIN;
		dfs(root, size, min, max);
		return size;
	}

	bool dfs(TreeNode*root, int& size, int& min, int& max) {
		if (!root) return true;
		int Lsize = 0, Rsize = 0;
		int Lmin = INT_MAX, Rmin = INT_MAX, Lmax = INT_MIN, Rmax = INT_MIN;
		bool l = dfs(root->left, Lsize, Lmin, Lmax);
		bool r = dfs(root->right, Rsize, Rmin, Rmax);
		if (l && r && root->val > Lmax && root->val < Rmin) {
			size = Lsize + Rsize + 1;
			min = (root->left) ? Lmin : root->val;
			max = (root->right) ? Rmax : root->val;
			return true;
		}
		else {
			size = std::max(Lsize, Rsize);
			return false;
		}
	}
};