type cintArray = ptr UncheckedArray[cint]

proc canFinish(n: int, prerequisites: ptr UncheckedArray[cintArray], m: int, unused: pointer): bool {.exportc.} =
  var
    d = newSeq[int](n)
    e = newSeq[seq[int]](n)
    top = -1
    num = 0
  for x in toOpenArray(prerequisites, 0, m-1):
    inc d[x[0]]
    e[x[1]].add x[0]
  for i in 0..<n:
    if d[i] == 0:
      d[i] = top
      top = i
  while top >= 0:
    let x = top
    top = d[top]
    inc num
    for y in e[x]:
      dec d[y]
      if d[y] == 0:
        d[y] = top
        top = y
  return num == n
