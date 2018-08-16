//leetcode 350. Intersection of Two Arrays II
//complexity:max(O(n),O(m))
//space complexity : choose one O(m) or O(n)


/*Follow up:
What if the given array is already sorted ? How would you optimize your algorithm ?


What if nums1's size is small compared to nums2's size ? Which algorithm is better ?


What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?


*/

Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> hash;
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++) {
			hash[nums1[i]]++;
		}
		for (int j = 0; j < nums2.size(); j++) {
			if (hash[nums2[j]] > 0) {
				res.push_back(nums2[j]);
				hash[nums2[j]]--;

			}
		}
		return res;
	}
};