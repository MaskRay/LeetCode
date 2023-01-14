// Distinct Prime Factors of Product of Array
class Solution {
public:
  int distinctPrimeFactors(vector<int>& nums) {
    const int N = 1001;
    int pr[N] = {}, primes[N], np = 0;
    for (int i = 2; i < N; i++) {
      if (!pr[i])
        primes[np++] = pr[i] = i;
      for (int j = 0; j < np && primes[j] <= pr[i] && i*primes[j] < N; j++)
        pr[i*primes[j]] = primes[j];
    }
    unordered_set<int> s;
    for (int x : nums)
      for (; x > 1; x /= pr[x])
        s.insert(pr[x]);
    return s.size();
  }
};
