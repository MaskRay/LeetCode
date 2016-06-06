// Intersection of Two Arrays
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> r;
    auto i = nums1.begin(), j = nums2.begin();
    while (i != nums1.end() && j != nums2.end()) {
      if (*i < *j)
        ++i;
      else if (*i > *j)
        ++j;
      else {
        r.push_back(*i);
        while (++i != nums1.end() && *i == r.back());
        while (++j != nums2.end() && *j == r.back());
      }
    }
    return r;
  }
};
