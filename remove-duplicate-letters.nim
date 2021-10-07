proc malloc(size: csize_t): pointer {.importc.}

proc removeDuplicateLetters(s: cstring): cstring {.exportc.} =
  var
    last: array[26, int]
    ins: array[26, bool]
    r = ""
  for i in 0..s.high: last[s[i].ord-'a'.ord] = i
  for i in 0..s.high:
    if not ins[s[i].ord-'a'.ord]:
      while r.len > 0 and s[i] < r[^1] and i < last[r[^1].ord-'a'.ord]:
        ins[r[^1].ord-'a'.ord] = false
        r.setLen r.len-1
      ins[s[i].ord-'a'.ord] = true
      r.add s[i]
  result = cast[cstring](malloc(cast[csize_t](r.len+1)))
  for i in 0..r.high: result[i] = r[i]
  result[r.len] = '\0'
