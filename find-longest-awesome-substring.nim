import std/algorithm

proc longestAwesome(s: cstring): int {.exportc} =
  var
    bgn: array[1024, int]
    m = 0
    i = 0
  bgn.fill(-1)
  bgn[0] = 0
  while s[i] != '\0':
    m = m xor 1 shl (s[i].ord-'0'.ord)
    inc i
    for j in 0..<10:
      let l = bgn[m xor 1 shl j]
      if l >= 0:
        result = max(result, i-l)
    if bgn[m] >= 0:
      result = max(result, i-bgn[m])
    else:
      bgn[m] = i
