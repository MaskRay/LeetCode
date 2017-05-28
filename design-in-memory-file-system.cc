// Design In-Memory File System
class FileSystem {
  struct Entry {
    bool file = false;
    string content;
    unordered_map<string, Entry*> ch;
  } *root = new Entry;
public:
  vector<string> parts(string path) {
    vector<string> r;
    size_t i = 1, j = 1;
    for (; j <= path.size(); j++)
      if (i < j && (j == path.size() || path[j] == '/')) {
        r.emplace_back(path.substr(i, j-i));
        i = j+1;
      }
    return r;
  }

  vector<string> ls(string path) {
    auto ps = parts(path);
    auto* x = root;
    for (auto p: ps)
      x = x->ch[p];
    if (x->file)
      return {ps.back()};
    vector<string> r;
    for (auto &i: x->ch)
      r.push_back(i.first);
    sort(r.begin(), r.end());
    return r;
  }

  void mkdir(string path) {
    auto* x = root;
    for (auto p: parts(path)) {
      if (! x->ch.count(p))
        x->ch[p] = new Entry;
      x = x->ch[p];
    }
  }

  void addContentToFile(string filePath, string content) {
    auto* x = root;
    for (auto p: parts(filePath)) {
      if (! x->ch.count(p))
        x->ch[p] = new Entry;
      x = x->ch[p];
    }
    x->file = true;
    x->content += content;
  }

  string readContentFromFile(string filePath) {
    auto* x = root;
    for (auto p: parts(filePath))
      x = x->ch[p];
    return x->content;
  }
};
