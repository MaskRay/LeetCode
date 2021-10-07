# Closest Subsequence Sum
import std/[algorithm, sequtils, sets]

proc minAbsDifference(nums: ptr UncheckedArray[cint], n: int, goal: int): int {.exportc.} =
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
        if i < result.len and (j == result.len or result[i] > result[j]+x):
          b.add result[i]
          inc i
        else:
          b.add result[j]+x
          if i < result.len and result[i] == result[j]+x: inc i
          inc j
      result.swap b
    result.reverse

  let
    nleft = n div 2
    left = fn(nums.toOpenArray(0, nleft-1))
  var i = left.len
  result = int.high
  for x in fn(nums.toOpenArray(nleft, n-1)):
    while i > 0 and left[i-1] >= goal-x: dec i
    if i < left.len: result = result.min(left[i]+x-goal)
    if i > 0: result = result.min(goal-left[i-1]-x)

###

import std/[algorithm, sequtils, sets]

proc minAbsDifference(nums: ptr UncheckedArray[cint], n: int, goal: int): int {.exportc.} =
  proc fn(a: openarray[cint]): seq[int] =
    var s = initHashSet[int]()
    s.incl 0
    for x in a.toOpenArray(0, a.high):
      var s1 = s
      for y in s: s1.incl x+y
      s = s1.move
    result = s.items.toSeq
    result.sort

  let
    nleft = n div 2
    left = fn(nums.toOpenArray(0, nleft-1))
  var i = left.len
  result = int.high
  for x in fn(nums.toOpenArray(nleft, n-1)):
    while i > 0 and left[i-1] >= goal-x: dec i
    if i < left.len: result = result.min(left[i]+x-goal)
    if i > 0: result = result.min(goal-left[i-1]-x)
