# Detect Squares
import tables

const N = 1001

type DetectSquares {.exportc.} = object
  ls: Table[int, seq[int]]
  rs: Table[int, seq[int]]
  c: seq[int]

proc detectSquaresCreate(): ptr DetectSquares {.exportc.} =
  result = create DetectSquares
  result[] = DetectSquares(ls: initTable[int, seq[int]](), rs: initTable[int, seq[int]](), c: newSeq[int](N*N))

proc detectSquaresAdd(obj: ptr DetectSquares, point: ptr UncheckedArray[cint], pointSize: cint) {.exportc.} =
  let (x, y) = (cast[int](point[0]), cast[int](point[1]))
  obj.ls.mgetOrPut(x+y, @[]).add(y)
  obj.rs.mgetOrPut(x-y, @[]).add(y)
  obj.c[x+y*N] += 1

proc detectSquaresCount(obj: ptr DetectSquares, point: ptr UncheckedArray[cint], pointSize: cint): int {.exportc.} =
  let (x0, y0) = (cast[int](point[0]), cast[int](point[1]))
  for y1 in obj.ls.getOrDefault(x0+y0, @[]):
    if y0 == y1: continue
    let x1 = x0+y0-y1
    result += obj.c[x0+y1*N] * obj.c[x1+y0*N]
  for y1 in obj.rs.getOrDefault(x0-y0, @[]):
    if y0 == y1: continue
    let x1 = x0-y0+y1
    result += obj.c[x0+y1*N] * obj.c[x1+y0*N]

proc detectSquaresFree(obj: sink DetectSquares) {.exportc.} = discard
