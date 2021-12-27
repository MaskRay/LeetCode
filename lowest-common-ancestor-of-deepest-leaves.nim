# Lowest Common Ancestor of Deepest Leaves
type TreeNode {.importc.} = ptr object
  val: cint
  left, right: TreeNode

proc lcaDeepestLeaves(root: TreeNode): TreeNode {.exportc.} =
  proc dfs(d: int, x: TreeNode): (int, TreeNode) =
    if x == nil:
      return (d-1, nil)
    let
      (dl, xl) = dfs(d+1, x.left)
      (dr, xr) = dfs(d+1, x.right)
    if dl > dr: return (dl, xl)
    if dl < dr: return (dr, xr)
    return (dl, x)
  dfs(0, root)[1]
