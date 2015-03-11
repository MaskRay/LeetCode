// Simplify Path
class Solution {
public:
  string simplifyPath(string path) {
    string r = "/";
    for (const char *p = path.c_str(), *q = p; *p; p = q) {
      for (q = p+1; *q && *q != '/'; q++);
      if (q-p == 1)
        ;
      else if (q-p == 2 && p[1] == '.')
        ;
      else if (q-p == 3 && p[1] == '.' && p[2] == '.') {
        auto i = r.rfind('/');
        if (i == 0)
          r.resize(1);
        else
          r.erase(r.begin()+i, r.end());
      } else {
        if (r.back() != '/')
          r += '/';
        r += string(p+1, q);
      }
    }
    return r;
  }
};
