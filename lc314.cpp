//leetcode:314. Binary Tree Vertical Order Traversal
//Use BFS
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        //use a queque to record the pos and the TreeNode
        map<int, vector<int>> hash;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root));
        while(!q.empty()){
            int key = q.front().first;
            TreeNode* node = q.front().second;
            hash[key].push_back(node->val);
            
            q.pop();
            if(node->left)q.push(make_pair(key-1,node->left));
            if(node->right)q.push(make_pair(key+1,node->right));
        }
        
        for(auto& it:hash){
            res.push_back(it.second);
        }
        return res;
    }
};