//leetcode: 301. Remove Invalid Parentheses
// This is a hard problem
// main idea is check count not valid parenthese
// then use dfs to try remove them in all position
// always remove the close parenthese first to make the prefix valid
// finially check if it is valid
// for remove duplicate, the easier way is to check if it is same as previous one
// this skill can use on any other removing duplicate problem.
 

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int l = 0, r = 0;
        //check how many l and r have to be removed.
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') l++;
            if(s[i] == ')'){
                if(l == 0)r++;
                else l--;
                }
        }
        dfs(res, s, 0, l ,r);
        return res;
        
    }
    
    void dfs(vector<string>& res, string s ,int pos ,int l, int r){
        if (l == 0 && r== 0){
            if(isvalid(s)) res.push_back(s);
            return;
        }
        if (r > 0){
            for(int i = pos; i < s.size(); i++){
                
                //skip duplicate
                if(i != pos && s[i] == s[i-1]) continue;
                //skip letter
                if(s[i] != '(' && s[i] != ')') continue;
                string curr = s;
                //check to remove l or r
                if(s[i] == ')') {
                    curr.erase(i,1);
                    dfs(res, curr, i, l, r-1);
                }
            }
        }
        else if (l > 0 && r == 0){
             for(int i = pos; i < s.size(); i++){
                //skip duplicate
                if(i != pos && s[i] == s[i-1]) continue;
                //skip letter
                if(s[i] != '(' && s[i] != ')') continue;
                string curr = s;
                //check to remove l or r
                if(s[i] == '(') {
                    curr.erase(i,1);
                    dfs(res, curr, i, l-1, r);
                }
            }
        }
        else return;
        
        
    }
    
    bool isvalid(string s){
        int count =0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') count++;
            if(s[i] == ')') count--;
            if(count < 0) return false;
        }
        return count == 0;
    }
    
};