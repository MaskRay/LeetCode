// Serialize and Deserialize Binary Tree
class Codec {
  void encode(TreeNode *x, string &s) {
    if (! x)
      s += ".,";
    else {
      s += to_string(x->val)+",";
      encode(x->left, s);
      encode(x->right, s);
    }
  }
  TreeNode *decode(istringstream &ss) {
    string t;
    getline(ss, t, ',');
    if (t == ".")
      return NULL;
    auto r = new TreeNode(stoi(t));
    r->left = decode(ss);
    r->right = decode(ss);
    return r;
  }
public:
  string serialize(TreeNode* root) {
    string s;
    encode(root, s);
    return s;
  }
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    return decode(ss);
  }
};

/// O(1) extra space, Morris pre-order traversal + edge crawling (resembling Schorr-Waite graph marking algorithm)

class Codec {
  int tag(TreeNode *x) {
    return ptrdiff_t(x) & 3;
  }
  TreeNode *pointer(TreeNode *x) {
    return (TreeNode *)(ptrdiff_t(x) & -4);
  }
public:
  string serialize(TreeNode *x) {
    string s;
    while (x) {
      auto y = x->left;
      if (y) {
        while (y->right && y->right != x)
          y = y->right;
        if (y->right == x) {
          y->right = NULL;
          s += ".,";
        } else {
          s += to_string(x->val)+",";
          y->right = x;
          x = x->left;
          continue;
        }
      } else
        s += to_string(x->val)+",.,";
      x = x->right;
    }
    s += ".,";
    return s;
  }
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    string t;
    getline(ss, t, ',');
    if (t == ".")
      return NULL;
    TreeNode *x = new TreeNode(stoi(t)), *y, *p = NULL;
    for(;;) {
      int xt = tag(x);
      auto xp = pointer(x);
      if (xt < 2) {
        x = (TreeNode *)(ptrdiff_t(xp) | xt+1);
        getline(ss, t, ',');
        y = t == "." ? NULL : new TreeNode(stoi(t));
        if (y) {
          (xt ? xp->right : xp->left) = p;
          p = x;
          x = y;
        } else
          (xt ? xp->right : xp->left) = NULL;
      } else {
        x = pointer(x);
        if (! p) break;
        y = x;
        x = p;
        xp = pointer(x);
        if (tag(x) == 1)
          p = xp->left, xp->left = y;
        else
          p = xp->right, xp->right = y;
      }
    }
    return x;
  }
};
