//leetcode:543. Diameter of Binary Tree
//It calculate the longest path from any leaves to another leave
//root is not count.
//use a global var to record the longest path
//return to parent path but only with the longest side
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int longest = 0;
        compute(root, longest);
        return longest;
    }
    
    int compute(TreeNode* root, int &longest){
        if(!root) return 0;
        int l = 0, r = 0;
        //recursively call function for left and right child
        l = compute(root->left, longest);
        r = compute(root->right, longest);
        longest = max(longest, l+r);
        return 1 + max(l,r);
    }
};