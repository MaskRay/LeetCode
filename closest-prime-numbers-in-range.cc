// Closest Prime Numbers in Range
#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> primes, pr(right+1);
    for (int i = 2; i <= right; i++) {
      if (!pr[i])
        primes.push_back(pr[i] = i);
      for (int j = 0; j < primes.size() && primes[j] <= pr[i] && i*primes[j] <= right; j++)
        pr[i*primes[j]] = primes[j];
    }

    int x = 0, y = INT_MAX;
    REP(i, (int)primes.size()-1)
      if (left <= primes[i] && primes[i+1]-primes[i] < y-x)
        x = primes[i], y = primes[i+1];
    if (!x) return {-1, -1};
    return {x, y};
  }
};
