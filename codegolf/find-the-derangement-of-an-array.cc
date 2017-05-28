struct Solution {
  int findDerangement(int n) {
    long s=0,i=2;
    for(;i<=n;i++)
      s=(i*s+1-i%2*2)%1000000007;
    return s;
  }
};
