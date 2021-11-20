type cintArray = ptr UncheckedArray[cint]

proc malloc(size: csize_t): pointer {.importc.}

proc findOrder(n: int, prereq: ptr UncheckedArray[cintArray], m: int, unused: pointer, returnSize: ptr cint): cintArray {.exportc.} =
  var
    d = newSeq[int](n)
    e = newSeq[seq[int]](n)
    fore = 0
    rear = 0
  result = cast[cintArray](malloc(cast[csize_t](cint.sizeof * n)))
  for x in toOpenArray(prereq, 0, m-1):
    inc d[x[0]]
    e[x[1]].add x[0]
  for i in 0..<n:
    if d[i] == 0:
      result[rear] = cast[cint](i)
      inc rear
  while fore < rear:
    let x: int = result[fore]
    inc fore
    for y in e[x]:
      dec d[y]
      if d[y] == 0:
        result[rear] = cast[cint](y)
        inc rear
  returnSize[] = if fore == n: cast[cint](n) else: 0
