//leetcode: 217. Contains Duplicate
//method one: use hash table.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> hash;
        for(auto i:nums){
            if(hash.find(i) != hash.end())return true;
            else hash[i] = true;
        }
        return false;
    }
};