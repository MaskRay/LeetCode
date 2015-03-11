// Compare Version Numbers
class Solution {
public:
  int compareVersion(string a, string b) {
    string::size_type i = 0, j = 0, ii, jj;
    while (i < a.size() && j < b.size()) {
      ii = a.find('.', i);
      jj = b.find('.', j);
      if (ii == string::npos) ii = a.size();
      if (jj == string::npos) jj = b.size();
      while (i < ii-1 && a[i] == '0') i++;
      while (j < jj-1 && b[j] == '0') j++;
      string x = a.substr(i, ii-i),
             y = b.substr(j, jj-j);
      if (x.size() < y.size()) return -1;
      if (x.size() > y.size()) return 1;
      if (x < y) return -1;
      if (x > y) return 1;
      i = ii+1;
      j = jj+1;
    }
    while (i < a.size()) {
      ii = a.find('.', i);
      if (ii == string::npos) ii = a.size();
      while (i < ii-1 && a[i] == '0') i++;
      if (a[i] != '0') return 1;
      i = ii+1;
    }
    while (j < b.size()) {
      jj = b.find('.', j);
      if (jj == string::npos) jj = b.size();
      while (j < jj-1 && b[j] == '0') j++;
      if (b[j] != '0') return -1;
      j = jj+1;
    }
    return 0;
  }
};
