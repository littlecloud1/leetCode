//leetcide:680. Valid Palindrome II
//only skip one element
//check the entire string at second time




class Solution {
public:
    bool validPalindrome(string s) {
        bool res = true;
        for(int i = 0, j = s.size()-1 ; i < j; i++,j-- ){
            if (s[i] != s[j])  {
                bool left = validP(s, i+1, j);
                bool right = validP(s, i, j-1);
                return left || right;
            }
        }
        return res;
    }
    
    bool validP(string s, int start, int end){
        for(int i = start, j = end ; i < j; i++,j-- )
            if (s[i] != s[j]) return false;
        return true;
    }
};