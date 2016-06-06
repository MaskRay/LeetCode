// Intersection of Two Arrays II
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> r;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    auto i = nums1.begin(), j = nums2.begin();
    while (i != nums1.end() && j != nums2.end())
      if (*i < *j)
        ++i;
      else if (*i > *j)
        ++j;
      else {
        r.push_back(*i);
        ++i;
        ++j;
      }
    return r;
  }
};
