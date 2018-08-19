// Boats to Save People
class Solution {
public:
  int numRescueBoats(vector<int>& a, int limit) {
    int i = 0, j = a.size();
    sort(a.begin(), a.end());
    while (i < j)
      if (i < --j && a[i]+a[j] <= limit)
        i++;
    return a.size()-i;
  }
};
