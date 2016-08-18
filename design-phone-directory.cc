// Design Phone Directory
class PhoneDirectory {
  vector<bool> used;
  vector<int> a;
  int top = 0;
public:
  /** Initialize your data structure here
    @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
  PhoneDirectory(int maxNumbers) : a(maxNumbers), used(maxNumbers, false) {
    iota(a.begin(), a.end(), 0);
  }

  /** Provide a number which is not assigned to anyone.
    @return - Return an available number. Return -1 if none is available. */
  int get() {
    if (top < a.size()) {
      used[a[top]] = true;
      return a[top++];
    }
    return -1;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return 0 <= number && number < a.size() && ! used[number];
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (0 <= number && number < a.size() && used[number]) {
      used[a[--top] = number] = false;
    }
  }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
