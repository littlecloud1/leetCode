//leetcode 904. Fruit Into Baskets
//3 conditions:
/*
[c] == [a]? a = c
[c] == [b]? b = c
[c] != [a] or [b]:
//1,2,1,1,1,1,3
if a > b:
start  = b+1;
//1,2,2,2,2,2,2,3
else:
start = a+1;
a = b;

*/
class Solution {
public:
	int totalFruit(vector<int>& tree) {
		if (tree.size() < 3) return tree.size();
		int start = 0, b1 = 0, b2 = -1, c = 1;
		int nfruit = 0;
		while (c < tree.size()) {
			if (tree[c] == tree[b1]) {
				b1 = c;
			}
			else if (b2 == -1 || tree[b2] == tree[c]) {
				b2 = c;
			}
			else {
				nfruit = max(nfruit, c - start);
				if (b1 > b2) {
					start = b2 + 1;
				}
				else {
					start = b1 + 1;
					b1 = b2;
				}
				b2 = c;
			}
			c++;
		}
		nfruit = max(nfruit, c - start);
		return nfruit;
	}
};