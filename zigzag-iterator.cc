// Zigzag Iterator
class ZigzagIterator {
  vector<int>::iterator i, ii, j, jj;
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    i = v1.begin();
    ii = v1.end();
    j = v2.begin();
    jj = v2.end();
  }

  int next() {
    if (i == ii)
      return *j++;
    swap(i, j);
    swap(ii, jj);
    return *j++;
  }

  bool hasNext() {
    return i != ii || j != jj;
  }
};
