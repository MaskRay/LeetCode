# Maximum Employees to Be Invited to a Meeting
import std/sequtils
type cintA = ptr UncheckedArray[cint]

proc maximumInvitations(fa: cintA, n: int): int {.exportc.} =
  var
    d = newSeq[int](n)
    dp = newSeqWith[int](n, 1)
    vis = newSeq[bool](n)
  var top = -1
  for i in 0..<n: d[fa[i]] += 1
  for i in 0..<n:
    if d[i] == 0:
      d[i] = top
      top = i
      vis[i] = true
  while top >= 0:
    let u = top
    top = d[top]
    let v = fa[u]
    dp[v] = max(dp[v], dp[u]+1)
    d[v] -= 1
    if d[v] == 0:
      d[v] = top
      top = v
      vis[v] = true
  var sum = 0
  for i in 0..<n:
    if vis[i]: continue
    var c = 0
    var j = i
    while true:
      c += 1
      vis[j] = true
      j = fa[j]
      if j == i: break
    if c == 2:
      sum += dp[i]+dp[fa[i]]
    else:
      result = max(result, c)
  max(result, sum)
