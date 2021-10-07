proc longestOnes(nums: ptr UncheckedArray[cint], numsSize: int, k: cint): int {.exportc.} =
  var
    l = 0
    bal = cast[int](k)
  for r in 0..<numsSize:
    if cast[int](nums[r]) == 0:
      dec bal
      if bal < 0:
        while (inc l; nums[l-1] > 0): discard
    result = max(result, r-l+1)
