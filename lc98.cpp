//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//use inorder travesel. Only ck if curr > prev
//why need pass by reference

//@owenzhu928 Because Java is "pass by value". Let's see that you pass an object like TreeNode. What you've actually passed to Java method is a copy reference of original reference. So whatever you modified on inside method is the copy reference. The original reference remains unchanged. In this case(code written in Java and pass reference variable), you modified copy reference of prev to node, but the original prev is still null. 
class Solution {
public:
 public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};