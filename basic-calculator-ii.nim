import strutils

proc calculate(s: cstring): cint {.exportc.} =
  var
    i = 0
    sign = 1
    sum = 0
  while s[i].isSpaceAscii: inc i
  if s[i] == '-':
    inc i
    sign = -1

  while true:
    while s[i].isSpaceAscii: inc i
    var x = s[i].ord-'0'.ord
    while (inc i; s[i].isDigit): x = x*10+s[i].ord-'0'.ord

    while (while (s[i].isSpaceAscii): inc i; let op = s[i]; op == '*' or op == '/'):
      inc i
      while s[i].isSpaceAscii: inc i
      var y = s[i].ord-'0'.ord
      while (inc i; s[i].isDigit): y = y*10+s[i].ord-'0'.ord
      x = if op == '*': x*y else: x div y
    sum += sign*x
    while s[i].isSpaceAscii: inc i
    if s[i] == 0.char: break
    sign = if s[i] == '-': -1 else: 1
    inc i

  return cast[cint](sum)
