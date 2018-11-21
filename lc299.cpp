//leetcode 299. Bulls and Cows
//use a hashmap to store the numbers
//if bull increase bull
//check if # in hashmap > 0 yes, decrease hashmap
//if no -> 1 cow used bull position. remove 1 cow.
//if cow, decrese hashmap, increase cow

class Solution {
public:
	string getHint(string secret, string guess) {
		string s = "";
		if (secret.empty() || guess.empty()) return s;
		int A = 0;//bull
		int B = 0;//cow
		unordered_map<int, int> mp;
		//initial secret hashtable
		for (char c : secret) {
			mp[c]++;
		}

		//check guess
		for (int i = 0; i < guess.size(); i++) {
			char c = guess[i];
			if (secret[i] == c) {
				A++;
				if (mp[c] > 0) {
					mp[c]--;
				}
				else {
					B--;
				}
			}
			else if (mp[c] > 0) {
				B++;
				mp[c]--;
			}
		}
		s = to_string(A) + 'A' + to_string(B) + 'B';
		return s;
	}
};