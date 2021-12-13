# Sell Diminishing-Valued Colored Balls
{.experimental: "views".}
import sequtils

type cintA = ptr UncheckedArray[cint]

proc maxProfit(inventory: cintA, n, orders: int): int {.exportc.} =
  var
    a = inventory.toOpenArray(0, n-1)
    l = 0
    h = a[a.maxIndex].int
  while l < h:
    let mi = (l+h+1) shr 1
    if a.foldl(a+max(int(b-mi), 0), 0) >= orders:
      l = mi
    else:
      h = mi-1
  for x in a:
    if x > l:
      result += (x+l+1)*(x-l) div 2
  (result - (a.foldl(a+max(int(b-l), 0), 0)-orders) * (l+1)) mod 1000000007
