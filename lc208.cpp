//leetcode 208. Implement Trie (Prefix Tree)
//time complexity of searching O(l)

//structure for TrieNode
class TrieNode {
private:
	bool end = false;
	vector<TrieNode*> children;
public:
	TrieNode(bool end = false) :end(end), children(26, NULL) {}
	~TrieNode() {
		for (auto it : children) {
			delete it;
		}
		children.clear();
	}

	TrieNode* getChild(char c) {
		int pos = c - 'a';
		return children[pos];
	}

	void setChild(TrieNode* node, char c) {
		int pos = c - 'a';
		children[pos] = node;
	}
	void setEnd(bool b) {
		end = b;
	}
	bool isEnd() {
		return end;
	}


};


class Trie {
private:
	TrieNode* root;

public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode(false);
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* head = root;
		for (int i = 0; i < word.size(); i++) {
			TrieNode* tmp;
			if (!head->getChild(word[i])) {
				tmp = new TrieNode(false);
				head->setChild(tmp, word[i]);

			}
			head = head->getChild(word[i]);
		}
		head->setEnd(true);

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* head = find(word);
		if (!head) return false;
		return head->isEnd();
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* head = root;
		return find(prefix) != NULL;
	}

	TrieNode* find(string word) {
		TrieNode* head = root;
		for (int i = 0; i < word.size(); i++) {
			if (head->getChild(word[i]) != NULL) {
				head = head->getChild(word[i]);
			}
			else return NULL;
		}
		return head;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/