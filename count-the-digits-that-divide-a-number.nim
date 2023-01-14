proc countDigits(num: cint): cint {.exportc.} =
  var
    x = num
    s = 0
  while x > 0:
    if num mod (x mod 10) == 0:
      s += 1
    x = x div 10
  s.cint
