# Longest Repeating Character Replacement
proc characterReplacement(s: cstring, k: int): int {.exportc.} =
  var
    l = 0
    r = 0
    mx = 0
    c: array[127, int]
  while s[r] != '\0':
    inc c[s[r].ord]
    mx = mx.max(c[s[r].ord])
    inc r
    if mx+k < r-l:
      dec c[s[l].ord]
      inc l
  r-l
