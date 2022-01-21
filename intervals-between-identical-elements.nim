# Intervals Between Identical Elements
import std/[sequtils, tables]

type cintA = ptr UncheckedArray[cint]
type intA = ptr UncheckedArray[int]
proc malloc(size: csize_t): pointer {.importc.}

proc getDistances(a: cintA, n: int, returnSize: ptr cint): intA {.exportc.} =
  var mp = initTable[cint, seq[int]]()
  for i in 0..<n:
    mp.mgetOrPut(a[i], @[]).add i
  result = cast[intA](malloc(cast[csize_t](int.sizeof * n)))
  returnSize[] = n.cint
  for b in mp.values:
    var sum = foldl(b, a+b)
    var pref = 0
    for i, v in b.pairs:
      result[v] = sum - pref*2 - (b.len-i*2)*v
      pref += v
