proc malloc(size: csize_t): pointer {.importc.}

proc removeKdigits(num: cstring, k0: int): cstring {.exportc.} =
  let n = num.len
  var
    j = 0
    k = k0
  result = cast[cstring](malloc(cast[csize_t](n+1)))
  for i in 0..<n:
    while k > 0 and j > 0 and result[j-1] > num[i]:
      dec j;
      dec k
    if j > 0 or num[i] != '0':
      result[j] = num[i]
      inc j
  if k < j:
    result[j-k] = '\0'
  else:
    result[0] = '0'
    result[1] = '\0'
