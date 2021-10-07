# Minimum Operations to Make a Uni-Value Grid
import std/algorithm

proc minOperations(grid: ptr UncheckedArray[ptr UncheckedArray[cint]], gridSize: int, gridColSize: ptr UncheckedArray[cint], x: cint): cint {.exportc.} =
  let n = gridSize * gridColSize[0]
  var
    a = newSeq[cint](n)
    k = 0
  for i in 0..<gridSize:
    for j in 0..<gridColSize[0]:
      a[k] = grid[i][j]
      inc k
  a.sort
  let median = a[n div 2]
  for y in a:
    let d = abs(y-median)
    if d mod x != 0: return -1
    result += d div x
