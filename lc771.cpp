//leetcode: 771. Jewels and Stones
//O(n)

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> mp;
        if(J.empty() || S.empty()) return 0;
        for(auto i:J) mp.insert(i);
        int count = 0;
        for(auto i:S){
            if(mp.count(i) > 0) count++;
        }
        return count;
        
    }
};