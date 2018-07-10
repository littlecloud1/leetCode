//method 1: (idea from : https://blog.csdn.net/wzy_1988/article/details/46916179)
//create 2 arrays: one is [1, a1, a1*a2, a1*a2*a3]
//the another array is [a2*a3*a4, a3*a4, a4, 1] 
// the result is the product of these two arrays.


class Solution1 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> arr(nums.size(), 1);
		vector<int> res(nums.size(), 1);

		//create 1st array
		for (int i = 1, j = nums.size() - 2; i < nums.size(); i++, j--) {
			arr[i] = arr[i - 1] * nums[i - 1];
			res[j] = res[j + 1] * nums[j + 1];
		}

		for (int i = 0; i < nums.size(); i++) {
			res[i] = res[i] * arr[i];
		}

		return res;
	}
};


