import std/algorithm

type cintA = ptr UncheckedArray[cint]

proc jobScheduling(startTime: cintA, n: int, endTime: cintA, u0: cint, profit: cintA, u1: cint): cint {.exportc.} =
  var
    a = newSeq[(cint, cint, cint)](n)
    dp = newSeq[cint](n)
  for i in 0..<n:
    a[i] = (startTime[i], endTime[i], profit[i])
  a.sort proc (x, y: (cint, cint, cint)): int = x[1] - y[1]
  dp[0] = a[0][2]
  for i in 1..<n:
    var l = 0
    var h = i
    while l < h:
      let m = (l+h) shr 1
      if a[m][1] <= a[i][0]: l = m+1
      else: h = m
    dp[i] = dp[i-1].max a[i][2] + (if l>0: dp[l-1] else: 0)
  dp[n-1]
