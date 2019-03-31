// Partition Array Into Three Parts With Equal Sum
class Solution {
public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int e = accumulate(A.begin(), A.end(), 0)/3, s = 0, c = 0;
    for (int x: A)
      if ((s += x) == e)
        s = 0, c++;
    return c >= 3;
  }
};
