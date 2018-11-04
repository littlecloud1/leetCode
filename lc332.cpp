//leetcode 332. Reconstruct Itinerary
//Eulerian path
//build the unorder map struc    [dep: multiset<dest>]
//

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> res;
		unordered_map<string, multiset<string>> mp;
		for (auto it : tickets) {
			mp[it.first].insert(it.second);
		}
		visit("JFK", mp, res);
		return vector<string>(res.rbegin(), res.rend());
	}
	void visit(string dep, unordered_map<string, multiset<string>> &mp, vector<string>& res) {
		while (!mp[dep].empty()) {
			string nextdep = *mp[dep].begin();
			mp[dep].erase(mp[dep].begin());
			visit(nextdep, mp, res);
		}
		res.push_back(dep);
	}


};