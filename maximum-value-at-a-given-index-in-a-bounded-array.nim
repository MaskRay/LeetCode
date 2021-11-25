# Maximum Value at a Given Index in a Bounded Array
proc maxValue(n: int, index: int, maxSum: int): int {.exportc.} =
  var
    l = 0
    h = maxSum - n
  while l < h:
    let a = (l+h+1) shr 1
    var b = max(a-index, 0)
    var sum = (a+b)*(a-b+1)
    b = max(a-(n-1)+index, 0)
    sum += (a+b)*(a-b+1)
    if sum div 2 - a <= maxSum - n:
      l = a
    else:
      h = a-1
  l+1
