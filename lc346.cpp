//leetcode 346. Moving Average from Data Stream
//reserve window size;
//record the actual window size
//if the [index] == 0, update actual window size
//else, average miuns [index]
//then update[index] and average move index
class MovingAverage {
private:
	vector<int> window;
	int index = 0;
	double avg = 0;
	int n = 0;
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		for (int i = 0; i < size; i++) window.push_back(0);
	}

	double next(int val) {
		if (window[index] != 0) avg -= window[index];
		else n++;
		window[index] = val;
		avg += window[index];
		index = (index + 1) % window.size();
		return avg / n;

	}
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage obj = new MovingAverage(size);
* double param_1 = obj.next(val);
*/