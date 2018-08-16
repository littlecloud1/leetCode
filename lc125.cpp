//leetcode:125. Valid Palindrome
//usage of isalnum ,http://www.cplusplus.com/reference/cctype/isalnum/
// s.size()/2 = 0.5 -> 1


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        for(int i = 0,j = s.size()-1; i < s.size()/2 && j >= s.size()/2; i++,j--){
            while(!isalnum(s[i]) && i < s.size()/2) i++; 
            while(!isalnum(s[j])  && j >= s.size()/2) j--; 
            if(isalnum(s[i]) && isalnum(s[j]))
                if(toupper(s[i]) != toupper(s[j])){return false;}
            
        }
        
        return true;
        
    }
};