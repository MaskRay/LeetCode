# Find Original Array From Doubled Array
import std/[algorithm, sequtils, tables]

type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc findOriginalArray(changed: cintA, n: int, returnSize: ptr cint): cintA {.exportc.} =
  var a: seq[cint] = changed.toOpenArray(0, n-1).toSeq
  var freq = initTable[cint, int]()
  var res: seq[cint]
  a.sort
  for x in a:
    freq.mgetOrPut(x, 0) += 1
  for x in a:
    if freq[x] > 0:
      freq[x] -= 1
      var c = addr freq.mgetOrPut(x+x, 0)
      c[] -= 1
      if c[] < 0:
        returnSize[] = 0
        return nil
      res.add x
  returnSize[] = res.len.cint
  result = cast[cintA](malloc((cint.sizeof * res.len).csize_t))
  copyMem result, addr res[0], cint.sizeof * res.len
