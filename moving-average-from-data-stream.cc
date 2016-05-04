// Moving Average from Data Stream
class MovingAverage {
  double sum = 0;
  int size, i = 0, n = 0;
  vector<int> a;
public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : size(size), a(size) {}

  double next(int val) {
    if (n >= size)
      sum -= a[i];
    sum += a[i++] = val;
    if (i == size)
      i = 0;
    n++;
    return sum / min(n, size);
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
