//leetcode: 91. Decode Ways
//fibonacci-> take one or take two
//here there are three case:
// '1' - '9' 
// '10' - '26'
// '0' must be two digits.
// so if '0' appears, the previous one cannot be used.
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int n = s.size();
        int dp[n+1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for(int i =2; i <=n; i++ ){
            //case 1: a digit
            if(s[i-1] >= '1' && s[i-1] <= '9' ) dp[i] += dp[i-1];
            //case 2: two digits
            if(s[i-2] == '1' ||( s[i-2] =='2' && s[i-1] <= '6')) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};