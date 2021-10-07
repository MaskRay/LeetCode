# Find the Longest Substring Containing Vowels in Even Counts
import std/algorithm

proc findTheLongestSubstring(s: cstring): int {.exportc.} =
  var
    bgn: array[32, int]
    m = 0
    i = 0
  bgn.fill(-1)
  bgn[0] = 0
  while s[i] != '\0':
    case s[i]
    of 'a': m = m xor 1
    of 'e': m = m xor 2
    of 'i': m = m xor 4
    of 'o': m = m xor 8
    of 'u': m = m xor 16
    else: discard
    inc i
    if bgn[m] >= 0:
      result = max(result, i-bgn[m])
    else:
      bgn[m] = i
