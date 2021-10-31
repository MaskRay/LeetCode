proc findKthNumber(m: int, n: int, k: int): int {.exportc.} =
  var
    l = 1
    h = m*n
  while l < h:
    let mid = (l+h) shr 1
    var
      c = 0
      j = n
    for i in 1..m:
      while j > 0 and i*j > mid:
        dec j
      c += j
    if c < k: l = mid+1
    else: h = mid
  l
