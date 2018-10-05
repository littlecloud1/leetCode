//leetcode 245. Shortest Word Distance III
//build hashmp <string, vector<index>>
//for the function:
//move both iterator at the same time
//to make to iterator close to each other, move the smaller one only
//record the shortest distance, skip the same index
class Solution {
public:
	int shortestWordDistance(vector<string>& words, string word1, string word2) {
		unordered_map<string, vector<int>> hash;
		for (int i = 0; i < words.size(); i++) hash[words[i]].push_back(i + 1);
		auto d1 = hash[word1].begin();
		auto d2 = hash[word2].begin();
		int res = words.size();
		while (d1 != hash[word1].end() && d2 != hash[word2].end()) {
			if (*d2 != *d1) res = min(res, abs(*d2 - *d1));
			if (*d2 > *d1) d1++;
			else d2++;
		}
		return res;
	}
};