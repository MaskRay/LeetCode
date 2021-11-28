# K Radius Subarray Averages
proc malloc(size: csize_t): pointer {.importc.}

type cintA = ptr UncheckedArray[cint]

proc getAverages(nums: cintA; n, k: int; returnSize: ptr cint): cintA {.exportc.} =
  result = cast[cintA](malloc(cast[csize_t](cint.sizeof * n)))
  returnSize[] = cast[cint](n)
  var
    s = newSeq[int](n+1)
  for i in 0..<n: s[i+1] = s[i]+nums[i]
  for i in 0..<n: result[i] = -1
  for i in k..<n-k: result[i] = cast[cint]((s[i+k+1]-s[i-k]) div (2*k+1))
