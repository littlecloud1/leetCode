//leetcode 905. Sort Array By Parity
//use two pointer i and j 
//keep the even number before i
//use j to search rest of the even number

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		if (A.size() <1) return A;
		int n = A.size();
		for (int i = 0, j = 0; i < n, j < n; i++, j++) {
			if (A[i] % 2 != 0) {
				while (A[j] % 2 != 0 && j <n) j++;
				if (j < n) swap(A[i], A[j]);
				else return A;
			}

		}
		return A;
	}
};