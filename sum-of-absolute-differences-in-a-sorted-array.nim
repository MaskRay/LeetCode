# Sum of Absolute Differences in a Sorted Array
type cintA = ptr UncheckedArray[cint]
proc malloc(size: csize_t): pointer {.importc.}

proc getSumAbsoluteDifferences(a: cintA, n: int, returnSize: ptr cint): cintA {.exportc.} =
  returnSize[] = n.cint
  result = cast[cintA](malloc(cast[csize_t](cint.sizeof*n)))
  result[0] = 0
  for i in 0..<n:
    result[0] += a[i]-a[0]
  for i in 1..<n:
    result[i] = result[i-1] + ((2*i-n)*(a[i]-a[i-1])).cint
