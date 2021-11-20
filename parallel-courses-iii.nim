# Parallel Courses III
import sequtils

type cintArray = ptr UncheckedArray[cint]

proc minimumTime(n: int, rels: ptr UncheckedArray[cintArray], m: int, unused: pointer, time: cintArray, unused1: cint): int {.exportc.} =
  var
    d = newSeq[int](n)
    e = newSeq[seq[int]](n)
    fin = newSeq[int](n)
    top = -1
  for x in toOpenArray(rels, 0, m-1):
    inc d[x[1]-1]
    e[x[0]-1].add x[1]-1
  for i in 0..<n:
    if d[i] == 0:
      d[i] = top
      top = i
  while top >= 0:
    let x = top
    top = d[top]
    fin[x] += time[x]
    for y in e[x]:
      fin[y] = max(fin[y], fin[x])
      dec d[y]
      if d[y] == 0:
        d[y] = top
        top = y
  fin[maxIndex(fin)]
