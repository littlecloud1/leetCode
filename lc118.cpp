//leetcode: 118. Pascal's Triangle
//resever enough space in vector,
//for every j =0 and j = i-1, push 1
//else (i,j) = (i-1,j-1) + (i-1,j);
//if numRows = 0 return.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++){
            for(int j =0; j <= i; j++){
                if(j == 0|| j == i) res[i].push_back(1);
                else {
                    int sum = res[i-1][j] + res[i-1][j-1];
                    res[i].push_back(sum);
                }
            }
        }
        return res;
    }
};