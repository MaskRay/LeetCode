# Diameter of Binary Tree
type
  TreeNode {.importc: "struct TreeNode".} = object
    val: cint
    left, right: ptr TreeNode

proc diameterOfBinaryTree(root: ptr TreeNode): int {.exportc.} =
  var res = 0
  proc height(x: ptr TreeNode): int =
    if x != nil:
      let l = height(x.left)
      let r = height(x.right)
      res = max(res, l+r)
      result = max(l, r) + 1
  discard height root
  res
