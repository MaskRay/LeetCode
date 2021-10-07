# Find the Most Competitive Subsequence
proc malloc(size: csize_t): pointer {.importc.}

proc mostCompetitive(nums: ptr UncheckedArray[cint], numsSize: int, k0: int, resultSize: ptr cint): ptr UncheckedArray[cint] {.exportc.} =
  var
    j = 0
    k = numsSize-k0
  result = cast[ptr UncheckedArray[cint]](malloc(cast[csize_t](cint.sizeof * numsSize)))
  for i in 0..<numsSize:
    while k > 0 and j > 0 and result[j-1] > nums[i]:
      dec j;
      dec k
    result[j] = nums[i]
    inc j
  resultSize[] = cast[cint](max(j-k, 0))
