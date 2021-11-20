// Check if an Original String Exists Given Two Encoded Strings
const int P = 32768;
struct HNode {int key; bool val; HNode *next; } pool[P*2], *head[P], *allo;

class Solution {
  static const int BASE = 999*10;
  string s1, s2;
  bool f(int i, int j, int p) {
    int key = ((p+BASE)*41+i)*41+j, hash = key%P;
    for (HNode *x = head[hash]; x; x = x->next)
      if (x->key == key)
        return x->val;
    if (s1.size() == i && s2.size() == j) return !p;
    bool ret = false;

    if (unsigned(s1[i]-'0') < 10) {
      int x = 0;
      do {
        x = x*10+s1[i]-'0';
        ret = f(++i, j, p+x);
      } while (!ret && unsigned(s1[i]-'0') < 10);
    } else if (unsigned(s2[j]-'0') < 10) {
      int x = 0;
      do {
        x = x*10+s2[j]-'0';
        ret = f(i, ++j, p-x);
      } while (!ret && unsigned(s2[j]-'0') < 10);
    } else {
      if (p > 0) {
        if (j < s2.size())
          ret = f(i, j+1, p-1);
      } else if (p < 0) {
        if (i < s1.size())
          ret = f(i+1, j, p+1);
      } else if (s1[i] == s2[j])
        ret = f(i+1, j+1, p);
    }
    HNode *x = allo == end(pool) ? new HNode : allo++;
    *x = {key, ret, head[hash]};
    head[hash] = x;
    return ret;
  }
public:
  bool possiblyEquals(string s1, string s2) {
    this->s1 = move(s1);
    this->s2 = move(s2);
    allo = pool;
    fill_n(head, sizeof(head)/sizeof(*head), nullptr);
    return f(0, 0, 0);
  }
};

/// unordered_map (slow)

class Solution {
  static const int BASE = 999*10;
  string s1, s2;
  unordered_map<unsigned, char> memo;
  bool f(int i, int j, int p) {
    char &ret = memo[((p+BASE)*41+i)*41+j];
    if (ret) return ret-1;
    if (s1.size() == i && s2.size() == j) return !p;

    if (unsigned(s1[i]-'0') < 10) {
      int x = 0;
      do {
        x = x*10+s1[i]-'0';
        ret = f(++i, j, p+x);
      } while (!ret && unsigned(s1[i]-'0') < 10);
    } else if (unsigned(s2[j]-'0') < 10) {
      int x = 0;
      do {
        x = x*10+s2[j]-'0';
        ret = f(i, ++j, p-x);
      } while (!ret && unsigned(s2[j]-'0') < 10);
    } else {
      if (p > 0) {
        if (j < s2.size())
          ret = f(i, j+1, p-1);
      } else if (p < 0) {
        if (i < s1.size())
          ret = f(i+1, j, p+1);
      } else if (s1[i] == s2[j])
        ret = f(i+1, j+1, p);
    }
    return ret++;
  }
public:
  bool possiblyEquals(string s1, string s2) {
    this->s1 = s1;
    this->s2 = s2;
    return f(0, 0, 0);
  }
};
