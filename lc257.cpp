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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        addPath(root, res, to_string(root->val));
        return res;
    }
    
    void addPath(TreeNode* root, vector<string>& res, string s){
        if(!root->left && !root->right){
            res.push_back(s);
            return;
        }
        if(root->left)addPath(root->left, res,s+"->"+to_string(root->left->val) );
        if(root->right)addPath(root->right, res,s+"->"+to_string(root->right->val));
        
    }
};