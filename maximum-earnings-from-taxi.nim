# Maximum Earnings From Taxi
import std/algorithm

type cintA = ptr UncheckedArray[cint]

proc maxTaxiEarnings(n: int, rides: ptr UncheckedArray[cintA], m: int, u: pointer): int {.exportc.} =
  var
    a = newSeq[(cint,cint,cint)](m)
    dp = newSeq[int](n+1)
    j = 0
  for i in 0..<m:
    a[i] = (rides[i][0], rides[i][1], rides[i][1]-rides[i][0]+rides[i][2])
  a.sort proc (x, y: (cint,cint,cint)): int = x[1]-y[1]
  for i in 1..n:
    var t = dp[i-1]
    while j < m and a[j][1] == i:
      t = t.max dp[a[j][0]]+a[j][2]
      inc j
    dp[i] = t
  dp[n]
