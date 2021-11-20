# Two Best Non-Overlapping Events
import std/algorithm

type cintA = ptr UncheckedArray[cint]

proc maxTwoEvents(ev: ptr UncheckedArray[cintA], n: int, unused: pointer): cint {.exportc.} =
  var
    a = newSeq[(cint,cint)](n)
    b = newSeq[(cint,cint)](n)
    mx: cint = 0
    j = 0
  for i in 0..<n:
    a[i] = (ev[i][1], ev[i][2])
    b[i] = (ev[i][0], ev[i][2])
  sort a
  sort b
  for i in 0..<n:
    while j < n and a[j][0] < b[i][0]:
      mx = mx.max a[j][1]
      inc j
    result = result.max mx+b[i][1]
