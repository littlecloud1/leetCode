//leetcode 232. Implement Queue using Stacks
//use two stacks, one for tmp store the element when add new element O(n) per push O(1)per pop
class MyQueue {
private:
	stack<int> q1;
	stack<int> tmp;

public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		while (!q1.empty()) { tmp.push(q1.top()); q1.pop(); }
		q1.push(x);
		while (!tmp.empty()) { q1.push(tmp.top()); tmp.pop(); }
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int v = q1.top();
		q1.pop();
		return v;
	}

	/** Get the front element. */
	int peek() {
		return (q1.top());
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (q1.empty());
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/


//method2
//only move when call peek. Then, the value move only when calling peek. amortized analysis : O(1)for both push and pop operation
class MyQueue {
private:
	stack<int> q1;
	stack<int> q2;

public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int v = peek();
		q2.pop();
		return v;
	}

	/** Get the front element. */
	int peek() {
		if (q2.empty()) {
			while (!q1.empty()) {
				q2.push(q1.top());
				q1.pop();
			}
		}
		return q2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (q1.empty() && q2.empty());
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/