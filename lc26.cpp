//leetcode: 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()< 2) return nums.size();
        //go through nums. use two pointer, one pointer iterate
        //the entire array, the another record the position that any nums before that position is unqiue.
        int unqi = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[unqi-1]){
                nums[unqi] = nums[i];
                unqi++;
            }
        }
        return unqi;
    }
};