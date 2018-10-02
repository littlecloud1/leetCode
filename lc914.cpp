//leetcode: 914. X of a Kind in a Deck of Cards
//find the min
//try to find the gcd for all cards
class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		unordered_map<int, int> mp;
		int m = deck.size();
		if (m < 2) return false;

		for (auto i : deck) mp[i]++;
		for (auto i : mp) m = min(i.second, m);

		int i = 2;
		while (i <= m) {
			bool valid = true;
			for (auto it : mp) {
				if (it.second % i != 0) valid = false;
			}
			if (valid) return true;
			i++;
		}
		return false;
	}
};