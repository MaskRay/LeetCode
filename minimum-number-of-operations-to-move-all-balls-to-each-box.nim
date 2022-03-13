proc malloc(size: csize_t): pointer {.importc.}
type cintA = ptr UncheckedArray[cint]

proc minOperations(boxes: cstring, returnSize: ptr cint): cintA {.exportc.} =
  let n = boxes.len
  result = cast[cintA](malloc((cint.sizeof * n).csize_t))
  returnSize[] = n.cint
  var c, s: int
  for i in 0..<n:
    result[i] = s.cint
    c += boxes[i].ord - '0'.ord
    s += c
  c = 0
  s = 0
  for i in countdown(n-1, 0):
    result[i] += s.cint
    c += boxes[i].ord - '0'.ord
    s += c
