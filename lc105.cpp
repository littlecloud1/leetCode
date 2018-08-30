//leetcode:105. Construct Binary Tree from Preorder and Inorder Traversal
//take a val in preorder, find the position in inorder
//that position is root. anything in the left side of that position from left tree, right side form right tree.
// nextstart-start is the size of left tree.
// the position of root of right tree is 
// the position of current root + the size of right tree's left tree + 1.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            TreeNode* head;
            head = build(inorder, preorder, 0, 0 ,inorder.size()-1);
            return head;
    }
    
    //
    TreeNode* build(vector<int>& inorder,vector<int>& preorder, int rpos, int start, int end ){
            if(start > end)return NULL;
            //create a new root from the preorder
            TreeNode* root = new TreeNode(preorder[rpos]);
            //count the left tree size
            int nextstart =0;
            for(int i = start; i <= end; i++){
                if (root->val == inorder[i]){
                    nextstart = i;
                    i = end+1;
                }
            }
            root->left = build(inorder, preorder, rpos+1, start, nextstart -1);
            root->right = build(inorder, preorder, rpos+ (nextstart - start) +1, nextstart+1, end);
            return root;
    }
};