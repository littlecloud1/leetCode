//leetcode: 46. Permutations
//branches = n * n-1 * ... * 1 = n!
//depth = n
//O(n!n) = O(n!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> res;
        if(nums.empty())return res;
        dfs(res, sub, nums);
        return res;
        
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums){
        if(sub.size() == nums.size()){
            res.push_back(sub);
            return;
        }
        //use a loop to use every not-used element
        for (int i =0; i < nums.size(); i++){
            if(find(sub.begin(), sub.end(), nums[i]) == sub.end()){
                sub.push_back(nums[i]);
                dfs(res, sub, nums);
                sub.pop_back();
            }
        }
    }
    
};


//improved  --> used an array instead of using find()
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> sub;
		vector<vector<int>> res;
		if (nums.empty())return res;
		bool used[nums.size()] = { false };
		dfs(res, sub, nums, used);
		return res;

	}

	void dfs(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, bool used[]) {
		if (sub.size() == nums.size()) {
			res.push_back(sub);
			return;
		}
		//use a loop to use every not-used element
		for (int i = 0; i < nums.size(); i++) {
			if (!used[i]) {
				used[i] = true;
				sub.push_back(nums[i]);
				dfs(res, sub, nums, used);
				sub.pop_back();
				used[i] = false;
			}
		}
	}

};

//leetcode 46
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		dfs(nums, 0, result);
		return result;
	}

	void dfs(vactor<int> nums, int pos, vector<vector<int>> & result) {
		if (pos >= nums.size()) {
			result.push_back(num);
			return;
		}
		for (int i = pos; i < nums.size(); i++) {
			swap(num[pos], num[i]);
			dfs(nums, pos + 1, result);
			swap(num[pos], num[i]);

		}


	}

};