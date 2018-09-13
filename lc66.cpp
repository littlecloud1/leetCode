//leetcode: 66. Plus One
//go through the vector from the end to the begin
//add one to the end and if sum > 9 , store carry 
//if carry > 0 then go to next position and add it
//repeat until reach the begin of vector
//if carry > 0, insert one at the begining
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            int sum = digits[i]+carry;
            if(sum > 9){
                digits[i] = 0;
                carry = 1;
            }
            else {
                carry = 0;
                digits[i] = sum;
            }
        }
        if (carry){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};