//leetcode 804. Unique Morse Code Words
//go through every char c in words
//the position map to morse is c - 'a' 
//add back to the result string
class Solution {
private:
	string morse[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> mp;
		for (string s : words) {
			string tmp;
			for (char c : s) {
				int pos = c - 'a';
				tmp = tmp + morse[pos];
			}
			if (mp.find(tmp) == mp.end()) mp.insert(tmp);
		}
		return mp.size();
	}
};