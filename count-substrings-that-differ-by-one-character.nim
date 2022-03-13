# Count Substrings That Differ by One Character
import std/sequtils

proc countSubstrings(s: cstring, t: cstring): int {.exportc.} =
  let
    m = s.len
    n = t.len
  var
    l0 = newSeq[cint](n)
    l1 = newSeq[cint](n)
    r = newSeqWith(m, newSeq[cint](n))
  for i in countdown(m-1, 0):
    for j in countdown(n-1, 0):
      if s[i] == t[j]:
        r[i][j] = if i+1<m and j+1<n: r[i+1][j+1]+1 else: 1
  for i in 0..<m:
    for j in 0..<n:
      if s[i] == t[j]:
        l1[j] = if j>0: l0[j-1]+1 else: 1
      else:
        result += (if j>0: l0[j-1]+1 else: 1) * (if i+1<m and j+1<n: r[i+1][j+1]+1 else: 1)
    for j in 0..<n:
      l0[j] = l1[j]
      l1[j] = 0
