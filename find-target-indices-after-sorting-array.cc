// Find Target Indices After Sorting Array
#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  vector<int> targetIndices(vector<int>& nums, int target) {
    vector<int> r;
    sort(ALL(nums));
    REP(i, nums.size())
      if (nums[i] == target)
        r.push_back(i);
    return r;
  }
};
