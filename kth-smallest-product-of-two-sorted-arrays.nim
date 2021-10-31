# Kth Smallest Product of Two Sorted Arrays
import std/algorithm

proc kthSmallestProduct(a: ptr UncheckedArray[cint], n: int, b: ptr UncheckedArray[cint], m: int, k: int): int64 {.exportc.} =
  var
    a0, a1, b0, b1: seq[cint]
    sign = 1
    l = 0'i64
    h = 10000000000'i64
    k = k
  a0 = newSeq[cint]()
  for x in toOpenArray(a, 0, n-1):
    if x < 0: a0.add -x
    else: a1.add x
  a0.reverse
  for x in toOpenArray(b, 0, m-1):
    if x < 0: b0.add -x
    else: b1.add x
  b0.reverse

  proc count(a: seq[cint], b: seq[cint], mid: int64): int64 =
    var j = b.len
    for x in a:
      while j > 0 and cast[int64](x)*b[j-1] > mid:
        dec j
      result += j

  let neg = a0.len*b1.len+a1.len*b0.len
  if neg < k:
    k -= neg
  else:
    k = neg-k+1
    sign = -1
    b0.swap b1
  while l < h:
    let mid = (l+h) shr 1
    if count(a0, b0, mid)+count(a1, b1, mid) < k: l = mid+1
    else: h = mid
  l*sign
