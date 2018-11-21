//leetcode 211. Add and Search Word - Data structure design
//use TrieTree
class TrieNode {
private:
	bool end;
	vector<TrieNode*> children;
public:
	TrieNode(bool end = false) : end(end), children(26, NULL) {};
	~TrieNode() {
		for (auto it : children) delete it;
		children.clear();
	}
	void setChild(TrieNode* node, char c) {
		children[c - 'a'] = node;
	}
	void setEnd(bool end) {
		this->end = end;
	}
	bool isEnd() {
		return end;
	}
	TrieNode* getChild(char c) {
		return children[c - 'a'];
	}
	vector<TrieNode*> getList() {
		return children;
	}
};

class WordDictionary {
private:
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode* head = root;
		for (char c : word) {
			if (!head->getChild(c)) {
				head->setChild(new TrieNode(), c);
			}
			head = head->getChild(c);
		}
		head->setEnd(true);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return find(root, word, 0);
	}

	//go through word:
	//if see '.'
	//search all child , skip invalid child:
	//       if reach the end of word, check if it also the end, yes return true; else skip going
	//       else recursive on it for next character
	//else check if find character, if no return false; yes, move head pointer
	//return if head is the end
	bool find(TrieNode* head, string word, int pos) {
		if (!head) return false;
		for (int i = pos; i < word.size(); i++) {
			if (word[i] == '.') {
				for (auto it : head->getList()) {
					if (!it) continue;
					bool valid;
					if (i == word.size() - 1) {
						valid = it->isEnd();
					}
					else {
						valid = find(it, word, i + 1);
					}
					if (valid) return true;
				}
				return false;
			}
			else {
				head = head->getChild(word[i]);
				if (!head) return false;
			}
		}
		return head->isEnd();
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/