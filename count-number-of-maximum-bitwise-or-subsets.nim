# Count Number of Maximum Bitwise-OR Subsets
import std/bitops

proc countMaxOrSubsets(nums: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var
    sum = newSeq[cint](1 shl n)
    mx = 0
  for i in 1..<(1 shl n):
    let j = i.countTrailingZeroBits
    sum[i] = sum[i.bitxor 1 shl j].bitor nums[j]
  for i in 1..<(1 shl n):
    if sum[i] > mx:
      mx = sum[i]
      result = 0
    if sum[i] == mx:
      inc result
