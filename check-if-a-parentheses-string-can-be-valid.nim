# Check if a Parentheses String Can Be Valid
proc canBeValid(s: cstring, locked: cstring): bool {.exportc.} =
  let n = s.len
  var
    mn = 0
    mx = 0
  for i in 0..<n:
    if locked[i] == '0':
      mn -= 1
      mx += 1
    elif s[i] == '(':
      mn += 1
      mx += 1
    else:
      mn -= 1
      mx -= 1
    if mx < 0: return false
    if mn < 0: mn = 1
  mn == 0
