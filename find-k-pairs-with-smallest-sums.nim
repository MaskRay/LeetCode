import std/heapqueue

type cintArray = ptr UncheckedArray[cint]

proc malloc(size: csize_t): pointer {.importc.}

proc kSmallestPairs(a: cintArray, m: int, b: cintArray, n: int, k0: int, returnSize: ptr cint, returnColumnSizes: ptr cintArray): ptr UncheckedArray[cintArray] {.exportc.} =
  let
    k = min(k0, m*n)
    sizes = cast[cintArray](malloc(cast[csize_t](cint.sizeof * k)))
  var
    h: HeapQueue[(cint, int32, int32)]
  for i in 0..<min(m, k):
    h.push (a[i]+b[0], cast[int32](i), 0'i32)
  result = cast[ptr UncheckedArray[cintArray]](malloc(cast[csize_t](pointer.sizeof * k)))
  returnSize[] = cast[cint](k)
  returnColumnSizes[] = sizes
  for i in 0..<k:
    let (x, p, q) = h.pop
    result[i] = cast[cintArray](malloc(cast[csize_t](cint.sizeof * 2)))
    result[i][0] = a[p]
    result[i][1] = b[q]
    sizes[i] = 2
    if q+1 < n:
      h.push (a[p]+b[q+1], p, q+1)
