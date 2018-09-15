//leetcode: 119. Pascal's Triangle II
//calculate from the end to begin
//push_back(1)everytime.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        for(int i = 0; i< rowIndex; i++){
            res.push_back(1);
            for(int j = i; j > 0; j--){
                        res[j] = res[j] + res[j-1];
            }
        }
        res.push_back(1);
        return res;
    }
};