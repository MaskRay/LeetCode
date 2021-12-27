# Next Greater Element I
import std/tables

type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc nextGreaterElement(a: cintA, m: int, b: cintA, n: int, returnSize: ptr cint): cintA {.exportc.} =
  var
    st = newSeq[cint](m)
    r = initTable[cint, cint]()
  for x in b.toOpenArray(0, n-1):
    while st.len > 0 and st[^1] < x:
      r[st.pop] = x
    st.add x
  result = cast[cintA](malloc(cast[csize_t](cint.sizeof * n)))
  returnSize[] = m.cint
  for i in 0..<m:
    result[i] = r.getOrDefault(a[i], -1)
