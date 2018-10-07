//leetcode 917. Reverse Only Letters
//check if it is Letter, if no  increase until i < j
class Solution {
public:
	string reverseOnlyLetters(string S) {
		for (int i = 0, j = S.size() - 1; i < j; i++, j--) {
			while (!isLetter(S[i]) && i < j) i++;
			while (!isLetter(S[j]) && i < j) j--;
			swap(S[i], S[j]);
		}
		return S;
	}


	bool isLetter(char c) {
		if ((c >= 'a' &&  c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
		else return false;

	}
};