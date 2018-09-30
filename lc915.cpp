//leetcode 915. Partition Array into Disjoint Intervals
//record the local max and the max
//once curr is less than local max, include all num up to curr position into left area. 
//update local to max (because max are also in the left area now)
//if curr is larger, compare and record the max
class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		int local = A[0];
		int Max = local;
		int p = 0;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] < local) {
				local = Max;
				p = i;
			}
			else Max = max(Max, A[i]);
		}
		return p + 1;
	}
};