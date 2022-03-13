# Minimum Number of Removals to Make Mountain Array
import std/algorithm

proc minimumMountainRemovals(a: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var lis = newSeq[int](n)
  var b = newSeq[cint]()
  for i in 0..<n:
    let j = b.lowerBound(a[i])
    if j == b.len: b.add a[i]
    else: b[j] = a[i]
    lis[i] = j
  b.setLen 0
  for i in countdown(n-1, 0):
    let j = b.lowerBound(a[i])
    if j == b.len: b.add a[i]
    else: b[j] = a[i]
    if lis[i] > 0 and j > 0:
      result = max(result, lis[i]+1+j)
  result = n-result
