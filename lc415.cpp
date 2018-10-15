//leetcode 415. Add Strings
//because the length is too long
//use string to calculate
//if num1 > num2 swap num num2
//add up from the end to the begining of num1
//if that digit + carry > 9 then digit = 0, carry =1
//add up util reach begin
class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.empty()) return num2;
		if (num2.empty()) return num1;

		//swap before calculate. the length of num1 always <= num2
		if (num1.size() > num2.size()) swap(num1, num2);

		int carry = 0;
		int i, j;
		for (i = num1.size() - 1, j = num2.size() - 1; i >= 0; i--, j--) {
			int digit = num1[i] - '0' + num2[j] - '0' + carry;
			if (digit > 9) {
				carry = 1;
				digit = digit - 10;
				num2[j] = digit + '0';
			}
			else {
				num2[j] = digit + '0';
				carry = 0;
			}
		}
		cout << carry << endl;
		while (j >= 0) {
			int digit = num2[j] - '0' + carry;
			if (digit > 9) {
				carry = 1;
				digit = digit - 10;
				num2[j] = digit + '0';
			}
			else {
				num2[j] = digit + '0';
				carry = 0;
			}
			j--;
		}
		if (carry == 1) {
			num2 = '1' + num2;
		}
		return num2;
	}


};