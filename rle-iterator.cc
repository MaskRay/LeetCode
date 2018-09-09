// RLE Iterator
class RLEIterator {
  vector<int> A;
  int i = 0, c = 0;
public:
  RLEIterator(vector<int> A) : A(A) {}

  int next(int n) {
    while (i < A.size()) {
      if ((c += n) <= A[i])
        return A[i+1];
      n = c-A[i];
      c = 0;
      i += 2;
    }
    return -1;
  }
};
