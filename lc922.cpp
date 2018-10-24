//leetcode 922 Sort Array By Parity II
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			if (i & 1) {
				if ((A[i] & 1) != 1) {
					int j = i + 1;
					while ((A[j] & 1) != 1) j++;
					swap(A[i], A[j]);
				}
			}
			else {
				if (A[i] & 1) {
					int j = i + 1;
					while (A[j] & 1) j++;
					swap(A[i], A[j]);
				}
			}
		}
		return A;
	}
};