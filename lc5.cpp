//leetcode:5. Longest Palindromic Substring
//expand around center
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int c = 0, l, r;
        string longest = s.substr(1,1);
        for(int i = 0 ; i < s.size()-1; i++){
            r = i+1;
            l = i>0? i-1:i;
            //'bbbb' patern
            if(s[r] == s[i]){
                while(s[r] == s[i]  && r < s.size())r++;
                //baab patern
                if(r < s.size() && s[r] == s[i-1]){
                    cout<<s[l]<<" "<<s[r];
                    while(s[r] == s[l] && l >= 0 && r < s.size()){
                        r++;
                        l--;
                    }
                    l = l >=0? l+1:0;
                    if(r-l > longest.size()) longest = s.substr(l, r-l);
                }
                if (r-i > longest.size()) longest = s.substr(i,r-i);
            }
            else if(s[r] == s[l]){
                while(s[r] == s[l] && l >=0 && r < s.size()){
                    r++;
                    l--;
                   
                }
                l = l >=0? l+1:0;
                if(r-l > longest.size()) longest = s.substr(l,r-l);
               // cout<<i <<" "<<r<<" "<<l<<" "<<longest<<endl;
            }
            
        }
        
        return longest;
    }
};