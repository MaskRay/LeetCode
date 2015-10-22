// Find Median from Data Stream
class MedianFinder {
public:
  priority_queue<int> mx;
  priority_queue<int, vector<int>, greater<int>> mi;
  int i = 0;
  // Adds a number into the data structure.
  void addNum(int num) {
    mx.push(num);
    mi.push(mx.top());
    mx.pop();
    if (mx.size() < mi.size()) {
      mx.push(mi.top());
      mi.pop();
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    return mx.size() > mi.size() ? mx.top() : 0.5 * mx.top() + 0.5 * mi.top();
  }
};
