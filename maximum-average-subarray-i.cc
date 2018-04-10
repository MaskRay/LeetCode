// Maximum Average Subarray I
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int s = accumulate(nums.begin(), nums.begin()+k, 0), mx = s;
    for (int i = k; i < nums.size(); i++)
      mx = max(mx, s += nums[i]-nums[i-k]);
    return double(mx)/k;
  }
};
