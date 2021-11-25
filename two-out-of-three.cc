// Two Out of Three
class Solution {
public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    int a[101] = {};
    for (int x: nums1) a[x] |= 1;
    for (int x: nums2) a[x] |= 2;
    for (int x: nums3) a[x] |= 4;
    vector<int> ans;
    for (int i = 0; i < sizeof(a)/sizeof(*a); i++)
      if (__builtin_popcount(a[i]) > 1)
        ans.push_back(i);
    return ans;
  }
};
