# Minimum Adjacent Swaps for K Consecutive Ones
proc minMoves(nums: ptr UncheckedArray[cint], n: int, k: int): int {.exportc.} =
  var
    a: seq[int]
    s = 0
  for i in 0..<n:
    if nums[i] > 0:
      a.add s
      s += i-a.len
  a.add s
  result = int.high
  for i in 0..<a.len-k:
    let
      m = i+k div 2
      x = a[m+1]-a[m]
      left = x*(m-i) - (a[m]-a[i])
      right = a[i+k]-a[m] - x*(i+k-m)
    result = min(result, left+right)
