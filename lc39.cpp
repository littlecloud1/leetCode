//leetcode 39. Combination Sum
//use backtracking method.
//dfs all combination, if it is larger than targer break, else keepgoing
//if equal to the sum, put it into result array


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> combin;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0, res, combin);
		return res;

	}

	void dfs(vector<int> candidates, int target, int start, vector<vector<int>>& res, vector<int> combin) {
		if (!target) {
			res.push_back(combin);
			return;
		}
		else {
			for (int i = start; i < candidates.size() && target; i++) {
				int newsum = target - candidates[i];
				if (newsum >= 0) {
					combin.push_back(candidates[i]);
					dfs(candidates, newsum, i, res, combin);
					combin.pop_back();
				}
				else break;
			}
		}
	}


};