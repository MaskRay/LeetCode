// Count Collisions on a Road
class Solution {
public:
  int countCollisions(string a) {
    int n = a.size(), i = 0;
    while (i < n && a[i] == 'L') i++;
    while (i < n && a[n-1] == 'R') n--;
    return n-i-count(a.begin()+i, a.begin()+n, 'S');
  }
};
