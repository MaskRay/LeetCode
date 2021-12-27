# Count Square Submatrices with All Ones
type Arr[T] = ptr UncheckedArray[T]

proc countSquares(a: Arr[Arr[cint]], m: int, ns: Arr[cint]): cint {.exportc.} =
  let n = ns[0].int
  var s = newSeq[cint](n)
  for i in 0..<m:
    var ul = 0.cint
    for j in 0..<n:
      let t = ul
      ul = s[j]
      s[j] = if a[i][j]>0: min(min(t, if j>0: s[j-1] else: 0), s[j])+1 else: 0
      result += s[j]
