// Permutations II
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

class Solution {
private:
  bool f(vector<int> &a) {
    ROF(i, 0, a.size()-1)
      if (a[i] < a[i+1]) {
        int j = a.size();
        while (! (a[i] < a[--j]));
        swap(a[i], a[j]);
        reverse(&a[i+1], &*a.end());
        return true;
      }
    return false;
  }
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > r;
    sort(num.begin(), num.end());
    do r.push_back(num);
    while (f(num));
    return r;
  }
};
