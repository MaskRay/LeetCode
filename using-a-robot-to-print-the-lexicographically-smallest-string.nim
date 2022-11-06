# Using a Robot to Print the Lexicographically Smallest String
proc malloc(size: csize_t): pointer {.importc.}

proc robotWithString(s: cstring): cstring {.exportc.} =
  let n = s.len
  result = cast[cstring](malloc(n.csize_t+1))
  var
    m = 0
    mn = ('z'.ord+1).chr
    b = newSeq[char](n)
    t = newSeq[char]()
  for i in countdown(n-1, 0):
    if s[i] < mn:
      mn = s[i]
    b[i] = mn
  for i in 0..<n:
    while t.len > 0 and t[^1] <= b[i]:
      result[m] = t.pop
      inc m
    t.add s[i]
  while t.len > 0:
    result[m] = t.pop
    inc m
  result[m] = '\0'
