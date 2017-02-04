// License Key Formatting
class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    S.erase(remove(S.begin(), S.end(), '-'), S.end());
    transform(S.begin(), S.end(), S.begin(), ::toupper);
    string r;
    int t = S.size()%K;
    if (! t) t = K;
    for (int i = 0; i < S.size(); i += t, t = K) {
      if (i) r += '-';
      r += S.substr(i, t);
    }
    return r;
  }
};
