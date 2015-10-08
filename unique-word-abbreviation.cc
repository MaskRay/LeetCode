// Unique Word Abbreviation
class ValidWordAbbr {
  string f(const string &w) const {
    return w.size() <= 2 ? w : w[0]+to_string(w.size()-2)+w.back();
  }
  map<string, string> m;
public:
  ValidWordAbbr(vector<string> &dictionary) {
    for (auto word: dictionary) {
      string w = f(word);
      m[w] = m.count(w) ? "" : word;
    }
  }

  bool isUnique(string word) {
    string w = f(word);
    return ! m.count(w) || m[w] == word;
  }
};
