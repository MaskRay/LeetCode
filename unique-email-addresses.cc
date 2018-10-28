// Unique Email Addresses
class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> es;
    for (auto e : emails) {
      auto t = e.find('@');
      string l = e.substr(0, t), ll;
      auto p = e.find('+');
      if (p != string::npos)
        l.resize(p);
      l.erase(remove(l.begin(), l.end(), '.'), l.end());
      es.insert(ll + e.substr(t));
    }
    return es.size();
  }
};
