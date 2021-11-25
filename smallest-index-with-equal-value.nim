proc smallestEqual(nums: ptr UncheckedArray[cint], n: int): cint {.exportc.} =
  for i in 0..<n:
    if i mod 10 == nums[i]:
      return cast[cint](i)
  -1
