// Fraction Addition and Subtraction
class Solution {
public:
  string fractionAddition(string s) {
    int p = 0, q = 1, p1, q1, t;
    for (size_t i = 0, j; i < s.size(); i = j) {
      j = s.find_first_of("+-", i+1);
      if (j == string::npos) j = s.size();
      auto k = s.find('/', i);
      int x = stol(s.substr(i, k-i)), y = stol(s.substr(k+1, j));
      p1 = p*y+q*x;
      q1 = q*y;
      t = __gcd(abs(p1), q1);
      p = p1/t;
      q = q1/t;
    }
    return to_string(p)+"/"+to_string(q);
  }
};
