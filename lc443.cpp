//leetcode 443. String Compression.
//use a target pointer and a moving pointer
//inside the loop
//check if t == i, if yes, increase i
//also, we have to check if i reach the end
//if [t] != [i], then put the cnt into t to cnt digit ,
// have to put i back to t position
class Solution {
public:
	int compress(vector<char>& chars) {
		int t = 0, cnt = 0;
		for (int i = 0; i <= chars.size(); i++) {
			if (chars[i] == chars[t] && i != chars.size()) cnt++;
			else {
				t++;
				if (cnt > 1) {
					//if len chars[t] > 1000;
					if (cnt / 1000) {
						chars[t++] = cnt / 1000 + '0';
						cnt = cnt % 1000;
					}
					if (cnt / 100) {
						chars[t++] = cnt / 100 + '0';
						cnt = cnt % 100;
					}
					if (cnt / 10) {
						chars[t++] = cnt / 10 + '0';
						cnt = cnt % 10;
					}
					chars[t++] = cnt % 10 + '0';
				}
				cnt = 1;
				chars[t] = chars[i];
			}

		}
		return t;
	}
};