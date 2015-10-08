// Two Sum III - Data structure design
class TwoSum {
  unordered_multiset<int> a;
public:
  // Add the number to an internal data structure.
  void add(int number) {
    a.insert(number);
  }

  // Find if there exists any pair of numbers which sum is equal to the value.
  bool find(int value) {
    for (int i: a)
      if (a.count(i) > (i == value-i ? 1 : 0))
        return true;
    return false;
  }
};
