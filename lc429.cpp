//leetcode 429. N-ary Tree Level Order Traversal
//similar to 102
//use a queue to store each level
/*
// Definition for a Node.
class Node {
public:
int val = NULL;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		if (!root) return res;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			vector<int> level;
			for (int i = 0; i < n; i++) {
				Node* tmp = q.front();
				for (Node* t : tmp->children)q.push(t);
				level.push_back(tmp->val);
				q.pop();
			}
			res.push_back(level);
		}
		return res;

	}
};