# Find K-th Smallest Pair Distance
import std/algorithm

proc smallestDistancePair(nums: ptr UncheckedArray[cint], n: int, k: int): cint {.exportc.} =
  var a = newSeq[cint](n)
  for i in 0..<n: a[i] = nums[i]
  a.sort()
  var
    l: cint = 0
    h = a[^1]-a[0]
  while l < h:
    let m = (l+h) shr 1
    var
      i = 0
      c = 0
    for j in 0..<n:
      while a[j]-a[i] > m:
        inc i
      c += cast[int](j-i)
    if k <= c: h = m
    else: l = m+1
  l
