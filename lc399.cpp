//leetcode 399. Evaluate Division
//this question looks complicated but it is simple when it break down
//we have equations: a/b b/c
//we need queries: a/c 
//the result of a/c = a/b * b/c
//it can represent by a graph
//a->b(2.0), b->c(3.0)
//then a->c is a->b->c (2.0)*(3.0) = 6.0
//we can use hashmap to store the relationship between nodes
//node: <dest, value>
//also, the queries has reverse order: b/a
//we can put the reverse relationship into hashmap
//when we do dfs, we have to record visited node to prevent loop




class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {

		unordered_map<string, unordered_map<string, double>> hash;
		//insert the pair: O(#equations)
		for (int i = 0; i < equations.size(); i++) {
			string node = equations[i].first;
			string dest = equations[i].second;
			double val = values[i];
			hash[node][dest] = val;
			hash[dest][node] = 1 / val;
		}

		vector<double> res;
		//go through the queries;
		//O(#queries#equation)
		for (int i = 0; i < queries.size(); i++) {
			string node = queries[i].first;
			string dest = queries[i].second;
			if (node == dest && hash.find(node) != hash.end()) res.push_back(1.0);
			else {
				set<string> visited;
				res.push_back(dfs(hash, node, dest, visited));
			}
		}
		return res;
	}

	//O(#equations)
	double dfs(unordered_map<string, unordered_map<string, double>> hash, string node, string target, set<string> visited) {
		if (hash.find(node) == hash.end()) return -1.0;
		if (hash[node].find(target) != hash[node].end()) return hash[node][target];

		visited.insert(node);
		for (auto it : hash[node]) {
			//dfs not visited node
			if (visited.find(it.first) == visited.end()) {
				double result = dfs(hash, it.first, target, visited);
				if (result > -1.0) return result*(it.second);
			}
		}
		return -1.0;
	}


};