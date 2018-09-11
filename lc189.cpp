//leetcode: 189. Rotate Array
//method one: use reverse string method -> reverse the half part
//then reverse the entire part
//***k can be any number
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 || k < 0) return ;
        k = k % n;
        reverse(nums, n-k, n);
        reverse(nums, 0, n-k);
        reverse(nums, 0, n);
    }
    
    void reverse(vector<int>& nums, int start, int end){
        for(int i = start, j = end-1; i < j; i++, j--){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        
    }
};