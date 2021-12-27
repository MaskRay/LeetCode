# Find the Longest Valid Obstacle Course at Each Position
import std/algorithm

type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc longestObstacleCourseAtEachPosition(a: cintA, n: cint, returnSize: ptr cint): cintA {.exportc.} =
  var b = newSeq[cint]()
  result = cast[cintA](malloc((cint.sizeof*n).csize_t))
  returnSize[] = n
  for i in 0..<n:
    # b.len == 0 is to work around UB https://github.com/nim-lang/Nim/issues/9887
    let j = if b.len == 0: 0 else: upperBound(b, a[i])
    result[i] = j.cint + 1
    if j == b.len:
      b.add a[i]
    else:
      b[j] = a[i]
