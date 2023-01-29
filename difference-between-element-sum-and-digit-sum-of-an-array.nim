proc differenceOfSum(a: ptr UncheckedArray[cint], n: cint): cint {.exportc.} =
  result = cint(0)
  for x in toOpenArray(a, 0, n-1):
    result += x
    var y = x
    while y > 0:
      result -= y mod 10
      y = y div 10
  return abs(result)
