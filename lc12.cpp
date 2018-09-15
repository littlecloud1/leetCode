//leetcode: 12. Integer to Roman
//for some discrete problem likes this, the best way is to enum the string;
string M[] = {"","M","MM","MMM"};
string C[] = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string X[] = {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string I[] = {"", "I","II","III", "IV", "V", "VI","VII","VIII","IX"}; 
class Solution {
public:
    string intToRoman(int num) {
        string res;
        res += M[(num/1000)];
        res += C[(num/100)%10];
        res += X[(num/10)%10];
        res += I[num%10];
        return res;
    }
};