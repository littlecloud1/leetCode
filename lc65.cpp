//leetcode: 65. Valid Number
//use DFA to make it easier
//the input will change from state to state
class Solution {
public:
    bool isNumber(string s) {
        int stage = 0;
        int start =0 , end = s.size()-1;
        //skip leading and ending space
        while(s[start] ==  ' ') start++;
        while(s[end] == ' ') end--;
        for(int i = start; i < end+1; i++){
            if(s[i] == '+' || s[i] == '-') {
                if(stage == 0 || stage == 5) stage++;
                else return false;
            }
            else if(s[i] == 'e'){
                if(stage == 2 || stage == 4) stage = 5;
                else return false;
            }
            else if(s[i] == '.'){
                if(stage == 0 || stage == 1) stage = 3;
                else if (stage == 2) stage = 4;
                else return false;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if (stage == 0 || stage == 1 || stage == 2) stage = 2;
                else if(stage ==3 || stage == 4) stage = 4;
                else if(stage == 5 || stage == 6 || stage == 7) stage = 7;
                else return false;
            }
            else return false; 
        }
        if(stage == 7|| stage == 2 || stage == 4)return true;
        else return false;
    }
};