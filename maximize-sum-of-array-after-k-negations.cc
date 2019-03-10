// Maximize Sum Of Array After K Negations
class Solution {
public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    auto it = partition(A.begin(), A.end(), bind(less<>(), placeholders::_1, 0));
    if (K < it-A.begin()) {
      nth_element(A.begin(), A.begin()+K, it);
      transform(A.begin(), A.begin()+K, A.begin(), negate<>());
    } else {
      transform(A.begin(), it, A.begin(), negate<>());
      if (K-(it-A.begin()) & 1) {
        it = min_element(A.begin(), it);
        auto it1 = min_element(it, A.end());
        (it == A.begin() || it1 != A.end() && *it1 < *it ? *it1 : *it) *= -1;
      }
    }
    return accumulate(A.begin(), A.end(), 0);
  }
};
