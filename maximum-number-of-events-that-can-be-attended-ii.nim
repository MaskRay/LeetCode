# Maximum Number of Events That Can Be Attended II
import algorithm

proc maxValue(events: ptr UncheckedArray[ptr UncheckedArray[cint]], n: int, u: pointer, k: int): int {.exportc.} =
  type E = tuple[start,stop,value: int]
  var
    a = newSeq[E](n)
    dp0: seq[int] = newSeq[int](n+1)
    dp1: seq[int] = newSeq[int](n+1)
  for i in 0..<n:
    a[i] = (cast[int](events[i][0]), cast[int](events[i][1]), cast[int](events[i][2]))
  a.sort proc (x, y: E): int = x.stop - y.stop
  for _ in 0..<k:
    for i in 0..<n:
      let j = a.lowerBound(a[i].start, proc (x: E, y: int): int = x.stop - y)
      dp1[i+1] = max(dp1[i], dp0[j]+a[i].value)
    swap(dp0, dp1)
  result = dp0[n]
