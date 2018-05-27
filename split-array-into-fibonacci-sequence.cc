// Split Array into Fibonacci Sequence
#define ALL(x) (x).begin(), (x).end()
#define ROF(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (b); --i >= (a); )

class Solution {
public:
  vector<int> splitIntoFibonacci(string S) {
    int n = S.size();
    long ta = 1, tb = 1;
    long oa = 0, ob, oc, a, b, c;
    vector<int> ret;
    ROF(i, 0, n) {
      oa += ta*(S[i]-'0');
      ta *= 10;
      if (oa > INT_MAX) break;
      ob = 0;
      tb = 1;
      ROF(j, 0, i) {
        ob += tb*(S[j]-'0');
        tb *= 10;
        if (ob > oa) break;
        int k = j-1;
        ret.clear();
        ret.push_back(a = oa);
        ret.push_back(b = ob);
        while (k >= 0) {
          c = a-b;
          oc = c;
          do if (S[k]-'0' != oc % 10) goto nxt;
          while (k--, oc /= 10);
          a = b;
          b = c;
          ret.push_back(c);
        }
      nxt:
        if (k < 0 && ret.size() >= 3) {
          reverse(ALL(ret));
          return ret;
        }
      }
    }
    return {};
  }
};
