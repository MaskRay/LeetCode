// Sum of Total Strength of Wizards
#define REP(i, n) for (long i = 0; i < (n); i++)

class Solution {
public:
  int totalStrength(vector<int>& a) {
    const long P = 1000000007;
    long n = a.size(), ret = 0;
    vector<long> st, l(n), r(n, n);
    vector<long> b(n+1), c(n+1);
    REP(i, n) {
      while (st.size() && a[st.back()] > a[i]) {
        r[st.back()] = i;
        st.pop_back();
      }
      l[i] = st.size() ? st.back() : -1;
      st.push_back(i);
      b[i+1] = (b[i] + a[i]) % P;
      c[i+1] = (c[i] + a[i]*i) % P;
    }
    REP(i, n) {
      long li = l[i], ri = r[i];
      long left = (c[i]-c[li+1] - li*(b[i]-b[li+1])) % P;
      long right = ((b[ri]-b[i])*ri - c[ri]+c[i]) % P;
      ret += ((ri-i)*left + (i-li)*right) % P * a[i] % P;
    }
    return (ret%P+P)%P;
  }
};
