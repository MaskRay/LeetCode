proc stoneGameIX(stones: ptr UncheckedArray[cint], stonesSize: cint): cint {.exportc.} =
  var a = [0,0,0]
  for x in toOpenArray(stones, 0, cast[int](stonesSize-1)):
    inc a[x mod 3]
  result = cast[cint](if a[0] mod 2 == 0: a[1]>0 and a[2]>0 else: abs(a[1]-a[2]) >= 3)
