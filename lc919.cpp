//leetcode 919. Complete Binary Tree Inserter
//to get the val of tree inorder: 1 2 3 4 5 6
//use bfs to do it
//to insert in a linked completed binary tree
//use a array to store the pointer of tree node
//the left node of i is stored in i*2 +1
//the right node of i is stored in i*2 +2
//thus, if l or r is outside the len of the treenode array, 
//then it should be insert at the end. the parent should be i.

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class CBTInserter {
private:
	TreeNode* head;
	vector<TreeNode*> table;
public:
	CBTInserter(TreeNode* root) {
		head = root;
		queue<TreeNode*> q;
		q.push(root);
		table.push_back(root);
		int i = 0;
		while (!q.empty()) {
			root = q.front();
			if (root->left) {
				q.push(root->left);
				table.push_back(root->left);
			}
			if (root->right) {
				q.push(root->right);
				table.push_back(root->right);
			}
			q.pop();
		}
	}

	int insert(int v) {
		int pv;
		TreeNode* node = new TreeNode(v);
		for (int i = 0; i <= table.size(); i++) {
			int l = i * 2 + 1, r = i * 2 + 2;
			if (table[i]) {
				if (l >= table.size()) {
					table.push_back(node);
					table[i]->left = node;
					pv = table[i]->val;
					break;
				}
				else if (r >= table.size()) {
					table.push_back(node);
					table[i]->right = node;
					pv = table[i]->val;
					break;
				}
			}

		}
		return pv;

	}




	TreeNode* get_root() {
		return head;
	}
};

/**
* Your CBTInserter object will be instantiated and called as such:
* CBTInserter obj = new CBTInserter(root);
* int param_1 = obj.insert(v);
* TreeNode* param_2 = obj.get_root();
*/