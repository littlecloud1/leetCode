//leetcode: 38. Count and Say
//decrease n everytime by 1
//continue until n == 0
//loop:
//go through prev, if i != i-1 then add to the end of new string
//after finish, update prev
class Solution {
public:
    string countAndSay(int n) {
        string prev;
        if(n == 0) return prev;
        prev = "1";
        while(n > 1){
            string s;
            int cnt = 1;
            for(int i =1; i < prev.size(); i++){
                if(prev[i] == prev[i-1]) cnt++;
                else{
                    s = s + to_string(cnt) + prev[i-1];
                    cnt =1;
                }
            } 
            s = s + to_string(cnt) + prev[prev.size()-1];
            prev = s;
            n--;
        }
        return prev;
    }
};
