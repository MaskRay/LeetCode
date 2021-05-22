#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )
typedef complex<double> cd;

const long MOD = 1000000007, SQ = 100000, NN = 1024;
const double IROOT = sqrt(double(MOD-SQ*SQ%MOD));
cd units[NN], aa[NN], bb[NN];

void fft_prepare(long n) {
  double ph = 2*M_PI/n;
  REP(i, n)
    units[i] = {cos(ph*i), sin(ph*i)};
}

void fft_dif2(cd a[], long n) { // sign = -1
  for (long m = n, dwi = 1; m >= 2; m >>= 1, dwi <<= 1)
    for (long r = 0; r < n; r += m) {
      cd *x = a+r, *y = a+r+(m>>1), *w = units;
      REP(j, m>>1) {
        cd v = *y, t = *x-v;
        *y++ = {t.real()*w->real()+t.imag()*w->imag(), t.imag()*w->real()-t.real()*w->imag()};
        *x++ += v;
        w += dwi;
      }
    }
}

void ifft_dit2(cd a[], long n) { // sign = 1
  for (long m = 2, dwi = n>>1; m <= n; m <<= 1, dwi >>= 1)
    for (long r = 0; r < n; r += m) {
      cd *x = a+r, *y = a+r+(m>>1), *w = units;
      REP(j, m>>1) {
        cd t{y->real()*w->real()-y->imag()*w->imag(), y->real()*w->imag()+y->imag()*w->real()};
        *y++ = *x-t;
        *x++ += t;
        w += dwi;
      }
    }
  REP(i, n)
    a[i] *= 1.0/n;
}

void fft_interleave(const vector<int>& a, long n, cd r[]) {
  REP(i, a.size()) {
    long z = a[i] <= MOD/2 ? a[i] : a[i]-MOD;
    r[i] = cd(z%SQ, z/SQ*IROOT);
  }
  fill(r+a.size(), r+n, 0);
  fft_dif2(&r[0], n);
}

vector<int> ifft_interleave(cd a[], long n) {
  ifft_dit2(a, n);
  vector<int> r(n);
  REP(i, n) {
    long x = round(a[i].real()), y = long(round(a[i].imag()/IROOT));
    r[i] = (x+y%MOD*SQ)%MOD;
    if (r[i] < 0) r[i] += MOD;
  }
  return r;
}

vector<int> rising_factorial(long l, long h) {
  if (h-l <= 64-1) {
    vector<int> r(h-l+1);
    r[0] = 1;
    FOR(i, l, h) {
      ROF(j, 0, i-l+1)
        r[j+1] = (r[j+1]*i+r[j])%MOD;
      r[0] = r[0]*i%MOD;
    }
    return r;
  }
  long m = l+h >> 1;
  auto a = rising_factorial(l, m), b = rising_factorial(m, h);
  long n = 1 << 63-__builtin_clzl(h-l)+1;
  fft_prepare(n);
  fft_interleave(a, n, aa);
  fft_interleave(b, n, bb);
  REP(i, n) aa[i] *= bb[i];
  return ifft_interleave(aa, n);
}

class Solution {
public:
  int rearrangeSticks(int n, int k) {
    return rising_factorial(0, n)[k];
  }
};
