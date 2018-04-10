// Friends Of Appropriate Ages
#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
  int numFriendRequests(vector<int>& a) {
    int j = 0, s = 0, n = a.size();
    sort(ALL(a));
    for (int i = 0; i < n; ) {
      int k = i+1;
      while (k < n && a[i] == a[k]) k++;
      while (j < n && 2*a[j] <= a[i]+14)
        j++;
      s += (k-i)*max(k-j-1, 0);
      i = k;
    }
    return s;
  }
};
