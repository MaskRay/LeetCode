# Minimum Deletions to Make String Balanced
proc minimumDeletions(s: cstring): int {.exportc.} =
  var b = 0
  for c in s:
    if c == 'a':
      result = min(result+1, b)
    else:
      b += 1
