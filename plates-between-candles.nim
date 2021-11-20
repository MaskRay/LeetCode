# Plates Between Candles
import sequtils

type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc platesBetweenCandles(s: cstring, q: ptr UncheckedArray[cintA], m: int, unused: pointer, returnSize: ptr cint): cintA {.exportc.} =
  let n = s.len
  var
    pref = newSeq[int](n+1)
    l = newSeqWith[int](n, -1)
    r = newSeqWith[int](n, n)
    c = 0
    j = 0
  for i in 0..<n:
    if s[i] == '*':
      inc c
    else:
      while j <= i:
        r[j] = i
        inc j
    pref[i] = c
  j = n-1
  for i in countdown(n-1, 0):
    if s[i] != '*':
      while i <= j:
        l[j] = i
        dec j
  result = cast[cintA](malloc(cast[csize_t](cint.sizeof * m)))
  returnSize[] = cast[cint](m)
  for i in 0..<m:
    let
      x = r[q[i][0]]
      y = l[q[i][1]]
    result[i] = if x >= y: 0 else: pref[y]-pref[x]
