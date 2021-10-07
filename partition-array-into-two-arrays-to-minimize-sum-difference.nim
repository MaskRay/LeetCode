# Partition Array Into Two Arrays to Minimize Sum Difference
import std/[algorithm, sequtils]

proc minimumDifference(nums: ptr UncheckedArray[cint], numsSize: int): int {.exportc.} =
  proc fn(a: openarray[cint]): seq[int] =
    var
      b = newSeq[int]()
      i, j: int
    result.add 0
    for x in a:
      b.setLen 0
      i = 0
      j = 0
      while i < result.len or j < result.len:
        if i < result.len and (j == result.len or result[i] > result[j]+1 shl 32+x):
          b.add result[i]
          inc i
        else:
          b.add result[j]+1 shl 32+x
          if i < result.len and result[i] == result[j]+1 shl 32+x: inc i
          inc j
      result.swap b
    result.reverse

  let
    n = numsSize div 2
    min = nums.toOpenArray(0, numsSize-1).toSeq.foldl(a.min(b))
    num = nums.toOpenArray(0, numsSize-1).mapIt(it-min).toSeq
    tot = num.foldl(a+b)
    half = tot div 2
    left = fn(num.toOpenArray(0, n-1))
    right = fn(num.toOpenArray(n, numsSize-1))
  var
    i = 0
    j = right.high
  while i < left.len and j >= 0:
    let
      x = left[i]+right[j]
      x0 = x and (1 shl 32-1)
      x1 = x shr 32
    if x1 == n and x0 <= half and x0 > result: result = x0
    if x1 < n or x1 == n and x0 <= half: inc i
    else: dec j
  return tot-result*2
