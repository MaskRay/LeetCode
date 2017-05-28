// Design Compressed String Iterator
class StringIterator {
  string a;
  size_t i = 0, c = 0;
  char ch;
public:
  StringIterator(string a) {
    this->a = a;
  }

  char next() {
    if (c)
      return c--, ch;
    if (i >= a.size())
      return ' ';
    ch = a[i++];
    while (i < a.size() && isdigit(a[i]))
      c = c*10+a[i++]-'0';
    c--;
    return ch;
  }

  bool hasNext() {
    return c || i < a.size();
  }
};
