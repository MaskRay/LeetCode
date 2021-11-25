// Final Value of Variable After Performing Operations
class Solution {
public:
  int finalValueAfterOperations(vector<string>& operations) {
    int s = 0;
    for (auto op: operations)
      if (op[1] == '+') s++;
      else s--;
    return s;
  }
};
