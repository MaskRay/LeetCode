# Ways to Make a Fair Array
proc waysToMakeFair(a: ptr UncheckedArray[cint], n: int): int {.exportc.} =
  var s0 = 0.cint
  for i in countdown(n-1, 0):
    s0 = a[i]-s0
  var s1 = 0.cint
  for i in countdown(n-1, 0):
    let s = a[i]-s1
    let d = s-s1
    if (if i mod 2 == 0: s0-d else: s0+d) == 0:
      result += 1
    s1 = s
