//leetcode 150. Evaluate Reverse Polish Notation
//use stack to store the num
//if see a operator
//remove the first two top from the stack
//I use switch case to check the operator;


class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> res;
		for (int i = 0; i< tokens.size(); i++) {

			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
				res.push(stoi(tokens[i]));
			}
			else {
				int num2 = res.top();
				res.pop();
				int num1 = res.top();
				res.pop();
				int sum;
				switch (tokens[i][0]) {
				case '+':
					sum = num1 + num2;
					break;
				case '-':
					sum = num1 - num2;
					break;
				case '/':
					sum = num1 / num2;
					break;
				case '*':
					sum = num1 * num2;
					break;
				}
				res.push(sum);
			}
		}
		return res.top();
	}
};