# Removing Minimum and Maximum From Array
{.experimental: "views".}
import std/sequtils

proc minimumDeletions(nums: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var
    a = nums.toOpenArray(0, n-1)
    x = a.minIndex
    y = a.maxIndex
  if x > y: swap x, y
  min y+1, min(n-x, x+1+n-y)
