type
  TreeNode {.importc: "struct TreeNode".} = object
    val: cint
    left, right: ptr TreeNode

proc maxPathSum(root: ptr TreeNode): int {.exportc.} =
  var res: int = root.val
  proc dfs(x: ptr TreeNode): int =
    if x == nil: return 0
    let l = max(dfs(x.left), 0)
    let r = max(dfs(x.right), 0)
    res = max(res, l+x.val+r)
    max(l, r)+x.val

  discard dfs(root)
  res
