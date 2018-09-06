//leetcode:639. Decode Ways II
//a lot of details to focus
// '1' - '9' 
// '10' - '26'
// '0' must be two digits.
// '*' 
// '**' 
// '1*' 
// '*6' 
// '*9' 
// '2*'
//also the table should set as long instead of int. 
#include <math.h> 
class Solution {
public:
    int numDecodings(string s) {
        cout<<endl;
        if(s.size() == 0 || s[0] == '0') return 0;
        int n = s.size();
        long dp[n+1] ={0};
        dp[0] = 1;
        dp[1] = s[0] == '*'? 9:1;
        for(int i = 2; i <= n; i++){
            //'1' - '9'
            if (s[i-1] >= '1' && s[i-1] <= '9' ) {
                dp[i] += dp[i-1];
                //'10' - '26'
                if (s[i-2] == '1' ||(s[i-2] == '2' && s[i-1] <= '6')) dp[i] += dp[i-2];}
            if(s[i-1] == '0') {
                if (s[i-2] == '1' ||(s[i-2] == '2')) dp[i] += dp[i-2];
            }
            //'*'
            if (s[i-1] == '*' ){
                dp[i] += dp[i-1] *9;
                if (s[i-2] == '1') dp[i] += dp[i-2]*9;
                if (s[i-2] == '2') dp[i] += dp[i-2]*6;
             }
            if (s[i-2] == '*') {
                if(s[i-1] == '*') dp[i] += dp[i-2]*15;
                else s[i-1] <= '6'? dp[i] += dp[i-2]*2:dp[i] += dp[i-2];
            }
            dp[i] %= 1000000007;
        }
       // for(auto i:dp) cout<<i <<' ';
        return dp[n];
    }
};