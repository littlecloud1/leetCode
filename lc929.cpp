//leetcode 929. Unique Email Addresses
//only focus on the string before @
//if there is a '.' skip
//if there is an '@' skip rest of the string until reach @
//ans should be within 1 to 100

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		if (emails.empty()) return -1;
		unordered_set<string> mp;
		for (int i = 0; i < emails.size(); i++) {
			string email = emails[i];
			string s;
			int j = 0;
			for (; email[j] != '@' && email[j] != '+'; j++) {
				while (email[j] == '.') { j++; }
				if (email[j] != '+') s += email[j];
			}
			while (email[j] != '@') j++;
			s += email.substr(j, email.size() - j);
			mp.insert(s);
		}
		return mp.size();
	}
};