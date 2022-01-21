# Minimum Remove to Make Valid Parentheses
proc malloc(size: csize_t): pointer {.importc.}

proc minRemoveToMakeValid(s: cstring): cstring {.exportc.} =
  var
    s = s
    l = newSeq[int]()
    r = newSeq[int]()
    res = $s
    n = 0
  for i in 0..<res.len:
    if s[i] == '(':
      l.add i
    elif s[i] == ')':
      if l.len > 0:
        discard l.pop
      else:
        r.add i
  for i in l: res[i] = '.'
  for i in r: res[i] = '.'
  for i in 0..<res.len:
    if res[i] != '.':
      res[n] = res[i]
      n += 1
  res.setLen n
  result = cast[cstring](malloc((n+1).csize_t))
  copyMem result, res.cstring, n+1
