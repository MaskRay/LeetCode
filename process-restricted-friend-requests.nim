# Process Restricted Friend Requests
import std/sequtils

type Arr[T] = ptr UncheckedArray[T]
proc malloc(size: csize_t): pointer {.importc.}

proc friendRequests(n: int, restrict: Arr[Arr[cint]], m: int, u0: pointer, reqs: Arr[Arr[cint]], q: int, u1: pointer, returnSize: ptr cint): Arr[int8] {.exportc.} =
  result = cast[Arr[int8]](malloc(q.csize_t))
  returnSize[] = q.cint
  var uf = (0..<n).toSeq
  proc find(x: int): int =
    var
      r = x
      x = x
    while uf[r] != r: r = uf[r]
    while x != r:
      let t = uf[x]
      uf[x] = r
      x = t
    r
  for i in 0..<q:
    let x = find(reqs[i][0])
    let y = find(reqs[i][1])
    var ok = true
    if x != y:
      for rest in restrict.toOpenArray(0, m-1):
        let p = find(rest[0])
        let q = find(rest[1])
        if (p, q) == (x, y) or (p, q) == (y, x):
          ok = false
          break
    if ok:
      uf[y] = x
    result[i] = ok.int8
