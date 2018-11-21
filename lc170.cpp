//leetcode 170. Two Sum III - Data structure design
//O(1) in add O(n) in find
//use hash table for finding sum

class TwoSum {
private:
	unordered_map<int, int> val;

public:
	/** Initialize your data structure here. */
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		val[number]++;
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		for (auto it : val) {
			long j = value - it.first;
			if (j == it.first) {
				if (it.second > 1)
					return true;
				else continue;
			}
			else if (val.find(j) != val.end()) return true;
		}
		return false;
	}
};

/**
* Your TwoSum object will be instantiated and called as such:
* TwoSum obj = new TwoSum();
* obj.add(number);
* bool param_2 = obj.find(value);
*/