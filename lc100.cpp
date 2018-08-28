//leetcode: 100 same Tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool same = true;
        check(p, q, same);
        return same;
    }
    
    void check(TreeNode*p, TreeNode* q, bool& same){
        if (p == NULL){
            if (q != NULL)same = false;
            return;
        }
        if (q == NULL){
            if (p != NULL)same = false;
            return;
        }
        if (q->val != p->val){
            same = false;
            return;
        }
        check(p->left, q->left, same);
        check(p->right, q->right, same); 