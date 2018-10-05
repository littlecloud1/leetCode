//leetcode: 8. String to Integer (atoi)
//I use DFA to make it easier
//O(N)
class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        if(str.empty()) return ans;
        int stage = 0, minus = 1 ;
        for(int i =0; i < str.size(); i++){
            if (str[i] == ' ') {
                if(stage != 0)break;
                continue;  
            }
            else if(str[i] == '-'){
                if(stage == 0) stage++;
                else break;
                minus = -1;
            }
            else if(str[i] == '+'){
                if(stage == 0) stage++;
                else break;
            }
            else if(str[i] >= '0' && str[i] <='9'){
                    if(stage == 1 || stage == 0) stage = 2;
                    ans = (str[i] - '0') + ans * 10;
                    if (ans > INT_MAX )break;
            }
            else if(stage == 2)  break;
            else return 0;
        }
        if (stage != 2) return 0;
        if (ans > INT_MAX ) ans = minus == 1? INT_MAX:INT_MAX+1;
        return ans *minus;
    }
};