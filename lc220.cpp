//leetcode: 220. Contains Duplicate III

//use set to store the nums in k+1 size
//check if size of size > k, then erase the first one.
//use lower bound to check if difference at most t exist. if yes, return true.
// lower_bound(num[i]-t)<=nums[i]+t
// lower_bound(num[i]-t) - nums[i] <= t
//insert into set.
//O(n*log n)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for(int i =0; i < nums.size() && k > 0; i++){
            long curr = nums[i];
            if(i > 0){
                if (i > k) window.erase(nums[i-k-1]); //O(log n)
                auto it = window.lower_bound(curr-t);
                if(it != window.end() && *it - curr <= t) return true;
            }
            window.insert(curr);          
        }
        return false;
    }
};