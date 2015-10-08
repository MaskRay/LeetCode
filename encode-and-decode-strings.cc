// Encode and Decode Strings
class Codec {
public:

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string r;
    for (auto &s: strs)
      r += to_string(s.size())+':'+s;
    return r;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> r;
    for (int l, j, i = 0; i < s.size(); i = j+1+l) {
      j = s.find(':', i);
      l = stoi(s.substr(i, j-i), NULL);
      r.push_back(s.substr(j+1, l));
    }
    return r;
  }
};
