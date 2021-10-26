proc kthSmallest(matrix: ptr UncheckedArray[ptr UncheckedArray[cint]], n: int, ms: ptr UncheckedArray[cint], k: int): int {.exportc.} =
  let m = ms[0]
  var
    l = matrix[0][0]
    h = matrix[n-1][m-1]
  while l < h:
    let x = l+(h-l) div 2
    var
      c = 0
      j = m
    for i in 0..<n:
      while j > 0 and x < matrix[i][j-1]: dec j
      c += j
    if c < k: l = x+1
    else: h = x
  l
