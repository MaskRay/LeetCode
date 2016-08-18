// Insert Delete GetRandom O(1)
class RandomizedSet {
  unordered_map<int, int> m;
  vector<int> a;
public:
  /** Initialize your data structure here. */
  RandomizedSet() {
  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (! m.emplace(val, a.size()).second) return false;
    a.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = m.find(val);
    if (it == m.end()) return false;
    m[a[it->second] = a.back()] = it->second;
    m.erase(it);
    a.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return a[rand()%a.size()];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
