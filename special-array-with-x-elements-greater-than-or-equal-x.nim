# Special Array With X Elements Greater Than or Equal X
proc specialArray(nums: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var
    c = newSeq[n](n+1)
    s = 0
  for x in nums.toOpenArray(0, n-1):
    inc c[min(x, n)]
  for i in countdown(n, 1):
    s += c[i]
    if s == i:
      return i
  -1

###

import std/[algorithm, sequtils]

proc specialArray(nums: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  let a = nums.toOpenArray(0, n-1).sorted
  for i in countdown(n-1, 0):
    if a[i] >= n-i and (i == 0 or a[i-1] < n-i):
      return n-i
  -1
