//leetcode 244. Shortest Word Distance II
//build hashmp <string, vector<index>>
//for the function:
//move both iterator at the same time
//to make to iterator close to each other, move the smaller one only
//record the shortest distance
class WordDistance {
private:
	unordered_map<string, vector<int>> index;
	int size = 0;
public:
	WordDistance(vector<string> words) {
		size = words.size();
		for (int i = 0; i < size; i++) index[words[i]].push_back(i + 1);
	}

	int shortest(string word1, string word2) {
		int res = size;
		auto d1 = index[word1].begin();
		auto d2 = index[word2].begin();
		while (d1 != index[word1].end() && d2 != index[word2].end()) {
			res = min(res, abs(*d2 - *d1));
			if (*d1 < *d2) d1++;
			else d2++;

		}
		return res;
	}
};

/**
* Your WordDistance object will be instantiated and called as such:
* WordDistance obj = new WordDistance(words);
* int param_1 = obj.shortest(word1,word2);
*/