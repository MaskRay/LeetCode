proc minSwaps(s: cstring): int {.exportc.} =
  var x = 0
  for ch in s:
    if ch == '[': x += 1
    elif x > 0: x -= 1
  (x+1) div 2
