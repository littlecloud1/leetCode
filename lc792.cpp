//leetcode: 792. Number of Matching Subsequences
//create a waitlist vector [a-z] to store vector of <index in words, char index>
//go through the string S[i]
//tmp store the vector of pairs in S[i]
//clear that vector S[i]
//update the char index and push back into waitlist
//if index > w.size put into waitlist[27]

class Solution {
public:
	int numMatchingSubseq(string S, vector<string>& words) {
		vector<vector<pair<int, int>>> waitlist;
		waitlist.resize(128);
		for (int i = 0; i < words.size(); i++) {
			waitlist[words[i][0]].push_back(make_pair(i, 1));
		}
		for (char s : S) {
			vector<pair<int, int>> tmp = waitlist[s];
			waitlist[s].clear();
			for (auto it : tmp) {
				if (words[it.first].size() == it.second) waitlist[0].push_back(it);
				else waitlist[words[it.first][it.second++]].push_back(it);
			}

		}
		return waitlist[0].size();
	}
};