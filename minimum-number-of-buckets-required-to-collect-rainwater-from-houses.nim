# Minimum Number of Buckets Required to Collect Rainwater from Houses
proc minimumBuckets(a: cstring): int {.exportc.} =
  let n = a.len
  var l = -2
  for i in 0..<n:
    if a[i] == 'H' and i != l+1:
      if i+1 < n and a[i+1] == '.':
        l = i+1
      elif not (i > 0 and a[i-1] == '.'):
        return -1
      inc result
