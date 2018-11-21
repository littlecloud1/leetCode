//leetcode 760. Find Anagram Mappings
//go through A, put all A into hash-map.
//go through B map it back to P
class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		unordered_map<int, vector<int>> mp;
		vector<int> res(A.size(), 0);
		for (int i = 0; i< A.size(); i++) {
			mp[A[i]].push_back(i);
		}
		for (int i = 0; i < A.size(); i++) {
			vector<int> it = mp[B[i]];
			for (int pos = 0; pos < it.size(); pos++) {
				res[it[pos]] = i;
			}
		}
		return res;
	}
};