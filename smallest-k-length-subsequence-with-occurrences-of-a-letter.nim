# Smallest K-Length Subsequence With Occurrences of a Letter
proc malloc(size: csize_t): pointer {.importc.}

proc smallestSubsequence(s: cstring, k: int, letter: char, repetition: int): cstring {.exportc.} =
  let n = s.len
  var
    j = 0
    behind = 0
    ahead = 0
  result = cast[cstring](malloc(cast[csize_t](k+1)))
  for i in 0..<n:
    if s[i] == letter: inc ahead
  for i in 0..<n:
    while j>0 and ((result[j-1]>s[i] and
                    behind-cast[int](result[j-1]==letter)+ahead >= repetition and
                    j-1+n-i >= k) or j-behind+repetition > k):
      if result[j-1] == letter: dec behind
      dec j
    if j < k:
      if s[i] == letter: inc behind
      result[j] = s[i]
      inc j
    if s[i] == letter: dec ahead
  result[k] = '\0'
