proc numSubarraysWithSum(nums: ptr UncheckedArray[cint], numsSize: int, goal: int): int {.exportc.} =
  var
    prev = -1
    j = 0
    s = 0
  for i in 0..<numsSize:
    s += nums[i]
    while j < i and s-nums[j] >= goal:
      if nums[j] > 0: prev = j
      s -= nums[j]
      j += 1
    if s == goal:
      result += j-prev
