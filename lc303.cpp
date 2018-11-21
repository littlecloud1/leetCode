//leetcode 303. Range Sum Query - Immutable
//dynamic programming problem
//pre store the number in the array
//the sumRange is the val in j - the val in i-1


class NumArray {
private:
	vector<int> sum;

public:
	NumArray(vector<int> nums) {
		for (int i : nums) {
			if (!sum.empty()) {
				sum.push_back(sum.back() + i);
			}
			else sum.push_back(i);
		}
	}

	int sumRange(int i, int j) {
		if (i > 0) {
			return sum[j] - sum[i - 1];
		}
		else return sum[j];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/