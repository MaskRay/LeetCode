// Verify Preorder Serialization of a Binary Tree
class Solution {
public:
  bool isValidSerialization(string preorder) {
    bool ok = true;
    int c = 0;
    for (string::size_type j, i = 0; i < preorder.size(); i = j+1) {
      j = preorder.find(',', i);
      if (j == string::npos)
        j = preorder.size();
      if (preorder[i] == '#')
        c--;
      else
        c++;
      if (c < 0 && j < preorder.size())
        ok = false;
    }
    return ok && c == -1;
  }
};
