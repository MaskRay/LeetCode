// Reconstruct Itinerary
/// Hierholzer's algorithm

class Solution {
  unordered_map<string, multiset<string>> m;
  vector<string> ret;
  void hierholzer(string x) {
    while (! m[x].empty()) {
      string y = *m[x].begin();
      m[x].erase(m[x].begin());
      hierholzer(y);
    }
    ret.push_back(x);
  }
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto &x: tickets)
      m[x.first].insert(x.second);
    hierholzer("JFK");
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

/// non-recursive Hierholzer's algorithm

class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    unordered_map<string, multiset<string>> m;
    for (auto &x: tickets)
      m[x.first].insert(x.second);
    stack<string> st;
    vector<string> ret;
    st.push("JFK");
    while (! st.empty()) {
      auto &x = st.top();
      if (m[x].empty()) {
        ret.push_back(x);
        st.pop();
      } else {
        auto it = m[x].begin();
        st.push(*it);
        m[x].erase(it);
      }
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};
