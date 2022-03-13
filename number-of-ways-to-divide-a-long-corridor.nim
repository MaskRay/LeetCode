# Number of Ways to Divide a Long Corridor
proc numberOfWays(corridor: cstring): int {.exportc.} =
  var a, b, c: int
  a = 1
  for ch in corridor:
    if ch == 'S':
      (a, b, c) = (0, (a+c) mod 1000000007, b)
    else:
      (a, b, c) = ((a+c) mod 1000000007, b, c)
  c
