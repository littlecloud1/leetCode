//leetcode 11 Container with Most Water from https://www.youtube.com/watch?v=IONgE6QZgGI
//find the area : the shortest * distance
//update the shortest if the next one is taller.
//complexity = O(n)

class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxA = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i < j) {
			int area = min(height[i], height[j]) * (j - i);
			maxA = max(maxA, area);
			if (height[j] > height[i]) i++; // this part can use a while loop to skip lines 
			else j--;
		}


		return maxA;
	}
};