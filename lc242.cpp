//leetcode: 242. Valid Anagram
//can use two method
//1. sorting (shorter code longer time)
//2. hash table --> all lower case (can use array(faster) / unordered_map)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> mp;        
        for(auto i:s) {
            if(mp.find(i) == mp.end())
                mp[i] = 1;
            else
                mp[i]++;
        }
        for(auto i:t){
            if(mp.find(i) == mp.end())return false;
            else mp[i]--;
        }
        for(auto i:mp) if(i.second != 0) return false;
        return true;
    }
};