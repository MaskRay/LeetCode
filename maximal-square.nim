type Arr[T] = ptr UncheckedArray[T]

proc maximalSquare(a: Arr[Arr[char]], m: int, ns: Arr[cint]): cint {.exportc.} =
  if m == 0: return 0
  let n = ns[0].int
  var
    s = newSeq[int](n)
    l = 0
  for i in 0..<m:
    var ul = 0
    for j in 0..<n:
      let t = ul
      ul = s[j]
      s[j] = if a[i][j] == '1': min(min(t, if j>0: s[j-1] else: 0), s[j])+1 else: 0
      l = max(l, s[j])
  cast[cint](l*l)
